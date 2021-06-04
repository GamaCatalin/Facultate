import torch
import myModel
import matplotlib.pyplot as plt

inputSize = 2
firstHiddenSize = 40
secondHiddenSize = 20
outputSize = 1
batchSize = 15
noEpochs = 8000


def loadData(filename="mydataset.dat"):
    tensor = torch.load(filename)
    input = tensor.narrow(1, 0, 2)
    output = tensor.narrow(1, 2, 1)

    return input, output


def saveData(ann, filename="myNet.pt"):
    torch.save(ann.state_dict(), filename)


def train():
    ann = myModel.Net(inputSize, firstHiddenSize, secondHiddenSize, outputSize).double()

    # we set up the lossFunction as the mean square error
    lossFunction = torch.nn.MSELoss()

    # we use an optimizer that implements stochastic gradient descent
    optimizer_batch = torch.optim.SGD(ann.parameters(), lr=0.05)

    inputTensor, outputTensor = loadData()

    lossList = []
    avgLossList = []

    noBatches = int(len(inputTensor) / batchSize)

    for epoch in range(noEpochs):
        totalLoss = 0

        for batch in range(noBatches):
            # we prepare the current batch  -- please observe the slicing for tensors
            batchInput, batchOutput = inputTensor[batch * batchSize:(batch + 1) * batchSize, ], \
                                      outputTensor[batch * batchSize:(batch + 1) * batchSize, ]

            # we compute the output for this batch
            prediction = ann(batchInput.double())

            # we compute the loss for this batch
            loss = lossFunction(prediction, batchOutput)

            # we save it for graphics
            lossList.append(loss)
            totalLoss += loss.item()

            # we set up the gradients for the weights to zero (important in pytorch)
            optimizer_batch.zero_grad()

            # we compute automatically the variation for each weight (and bias) of the network
            loss.backward()

            # we compute the new values for the weights
            optimizer_batch.step()

        avgLossList.append(totalLoss / noBatches)

        # we print the loss for all the dataset for each 10th epoch
        if epoch % 100 == 99:
            y_pred = ann(inputTensor.double())
            loss = lossFunction(y_pred, outputTensor)
            print('\repoch: {}\tLoss =  {:.5f}'.format(epoch, loss))

    plt.plot(avgLossList)
    plt.savefig("lossPlot.png")
    plt.show()
    saveData(ann)


if __name__ == "__main__":
    train()
