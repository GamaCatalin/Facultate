import torch
from myModel import *
from trainingmodel import *
import numpy as np


def run(ann):
    x1, x2 = 0, 0
    while x1 != "stop":
        x1 = input("x1= ")
        if x1 == "stop":
            break
        x2 = input("x2= ")

        x1 = float(x1)
        x2 = float(x2)

        if -10 <= x1 <= 10 and -10 <= x2 <= 10:
            approximated = ann(torch.tensor([x1, x2])).item()
            actual = np.sin((x1 + x2 / np.pi))
            print("approx: " + str(approximated))
            print("actual: " + str(actual))
        else:
            print("numbers have to be in [-10, 10]")

def main():
    ann = Net(inputSize, firstHiddenSize, secondHiddenSize, outputSize)

    ann.load_state_dict(torch.load("myNet.pt"))
    ann.eval()

    # visualise the parameters for the ann (aka weights and biases)
    for name, param in ann.named_parameters():
        if param.requires_grad:
            print(name, param.data)

    run(ann)

main()