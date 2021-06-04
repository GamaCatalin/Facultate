# -*- coding: utf-8 -*-
"""
Created on Tue May 18 16:50:38 2021

@author: tudor
"""

#Import needed packages
import torch
import torch.nn as nn
from torchvision.datasets import CIFAR10
from torchvision.transforms import transforms
from torch.utils.data import DataLoader
from torch.optim import Adam
from torch.autograd import Variable
import numpy as np
from MyDataset import *


class Unit(nn.Module):
    def __init__(self, in_channels, out_channels):
        super(Unit, self).__init__()


        self.conv = nn.Conv2d(in_channels=in_channels,kernel_size=3,out_channels=out_channels,stride=1,padding=1)
        self.bn = nn.BatchNorm2d(num_features=out_channels)
        self.relu = nn.ReLU()

    def forward(self, input):
        output = self.conv(input)
        output = self.bn(output)
        output = self.relu(output)

        return output

class SimpleNet(nn.Module):
    def __init__(self,num_classes=2):
        super(SimpleNet,self).__init__()

        #Create 14 layers of the unit with max pooling in between
        self.unit1 = Unit(in_channels=3,out_channels=32)
        self.unit2 = Unit(in_channels=32, out_channels=32)
        self.unit3 = Unit(in_channels=32, out_channels=32)

        self.pool1 = nn.MaxPool2d(kernel_size=2)

        self.unit4 = Unit(in_channels=32, out_channels=64)
        self.unit5 = Unit(in_channels=64, out_channels=64)
        self.unit6 = Unit(in_channels=64, out_channels=64)
        self.unit7 = Unit(in_channels=64, out_channels=64)

        self.pool2 = nn.MaxPool2d(kernel_size=2)

        self.unit8 = Unit(in_channels=64, out_channels=128)
        self.unit9 = Unit(in_channels=128, out_channels=128)
        self.unit10 = Unit(in_channels=128, out_channels=128)
        self.unit11 = Unit(in_channels=128, out_channels=128)

        self.pool3 = nn.MaxPool2d(kernel_size=2)

        self.unit12 = Unit(in_channels=128, out_channels=128)
        self.unit13 = Unit(in_channels=128, out_channels=128)
        self.unit14 = Unit(in_channels=128, out_channels=128)

        self.avgpool = nn.AvgPool2d(kernel_size=4)
        
        #Add all the units into the Sequential layer in exact order
        self.net = nn.Sequential(self.unit1, self.unit2, self.unit3, self.pool1, self.unit4, self.unit5, self.unit6
                                 ,self.unit7, self.pool2, self.unit8, self.unit9, self.unit10, self.unit11, self.pool3,
                                 self.unit12, self.unit13, self.unit14, self.avgpool)

        self.fc = nn.Linear(in_features=128*7*7,out_features=num_classes)

    def forward(self, input):
        output = self.net(input)
        output = output.view(-1, 128*7*7)
        output = self.fc(output)
        return output


class Train:
    def __init__(self):
        self.train_loader = self.TrainLoader()
        self.test_loader = self.TestLoader()
        self.model = SimpleNet(num_classes=2)

        self.cuda_avail = torch.cuda.is_available()

        if self.cuda_avail:
            self.model.cuda()

        self.optimizer = optimizer = Adam(self.model.parameters(), lr = 0.0001, weight_decay=0.0001)
        self.loss_fn = nn.CrossEntropyLoss()

    def adjust_learning_rate(self, epoch):
        lr = 0.001

        if epoch > 180:
            lr = lr / 1000000
        elif epoch > 150:
            lr = lr / 100000
        elif epoch > 120:
            lr = lr / 10000
        elif epoch > 90:
            lr = lr / 1000
        elif epoch > 60:
            lr = lr / 100
        elif epoch > 30:
            lr = lr / 10

        for param_group in self.optimizer.param_groups:
            param_group["lr"] = lr

    def save_models(self, epoch):
        torch.save(self.model.state_dict(), "Model_{}.model".format(epoch))
        print("Checkpoint saved")

    def test(self):
        self.model.eval()
        test_acc = 0.0
        for i, (images, labels) in enumerate(self.test_loader):

            if self.cuda_avail:
                images = Variable(images.cuda())
                labels = Variable(labels.cuda())

            # Predict classes using images from the test set
            outputs = self.model(images)
            _, prediction = torch.max(outputs.data, 1)
            # prediction = prediction.cpu().numpy()

            test_acc += torch.sum(torch.eq(prediction, labels.data))

        # Compute the average acc and loss over all 75 test images
        test_acc = test_acc / 75

        return test_acc

    def TestLoader(self):
        dataset = getTestDataset()

        test_loader = DataLoader(dataset, batch_size=5, shuffle=False, num_workers=4)

        return test_loader

    def TrainLoader(self):
        dataset = getDataset()

        train_loader = DataLoader(dataset, batch_size=5, shuffle=False, num_workers=4)

        return train_loader

    def train(self, num_epochs):
        best_acc = 0.0

        for epoch in range(num_epochs):
            self.model.train()
            train_acc = 0.0
            train_loss = 0.0
            for i, (images, labels) in enumerate(self.train_loader):
                # Move images and labels to gpu if available
                if self.cuda_avail:
                    images = Variable(images.cuda())
                    labels = Variable(labels.cuda())

                # Clear all accumulated gradients
                self.optimizer.zero_grad()
                # Predict classes using images from the test set
                outputs = self.model(images)
                # Compute the loss based on the predictions and actual labels
                loss = self.loss_fn(outputs, labels)
                # Backpropagate the loss
                loss.backward()

                # Adjust parameters according to the computed gradients
                self.optimizer.step()

                train_loss += loss.cpu().data.item() * images.size(0)
                _, prediction = torch.max(outputs.data, 1)

                train_acc += torch.sum(prediction == labels.data)

            # Call the learning rate adjustment function
            self.adjust_learning_rate(epoch)

            # Compute the average acc and loss over all 50000 training images
            train_acc = train_acc / 150
            train_loss = train_loss / 150

            # Evaluate on the test set
            test_acc = self.test()

            # Save the model if the test acc is greater than our current best
            if test_acc > best_acc:
                self.save_models(epoch)
                best_acc = test_acc

            # Print the metrics
            print(
                "Epoch {}, Train Accuracy: {} , TrainLoss: {} , Test Accuracy: {}".format(epoch+1, train_acc, train_loss,
                                                                                          test_acc))

    def run(self):
        torch.cuda.empty_cache()
        self.train(20)

if __name__ == "__main__":
    train = Train()
    train.run()






