import torch
import numpy as np


def computeResults(tensor):
    results = []
    for point in tensor.numpy():
        y = np.sin((point[0] + point[1] / np.pi))
        results.append(y)
    return torch.tensor(results)


def createDistribution(n = 1000):
    points = torch.rand(n, 2) * 20 - 10
    results = computeResults(points)

    return torch.column_stack((points, results))

def saveData(filename = "mydataset.dat"):
    data = createDistribution()
    torch.save(data, filename)

if __name__ == "__main__":
    saveData()