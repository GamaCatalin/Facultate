import torch

class Net(torch.nn.Module):
    def __init__(self, inputSize, firstHiddenSize, secondHiddenSize, outputSize):
        super(Net, self).__init__()
        self.firstHidden = torch.nn.Linear(inputSize, firstHiddenSize)
        self.secondHidden = torch.nn.Linear(firstHiddenSize, secondHiddenSize)
        self.output = torch.nn.Linear(secondHiddenSize, outputSize)


    def forward(self, x):

        firstHiddenOutput = torch.nn.functional.relu(self.firstHidden(x))
        secondHiddenOutput = torch.nn.functional.relu(self.secondHidden(firstHiddenOutput))

        output = self.output(secondHiddenOutput)

        return output