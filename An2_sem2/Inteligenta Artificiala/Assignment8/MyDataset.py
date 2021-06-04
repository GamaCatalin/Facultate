import torch
import torch.nn as nn
import torch.optim as optim
import time
from PIL import Image
from torch.utils.data import Dataset, DataLoader
from torchvision import datasets, models, transforms


device = torch.device('cuda:0' if torch.cuda.is_available() else 'cpu')


class ImageClassifierDataset(Dataset):
    def __init__(self, image_list, image_classes):
        self.images = []
        self.labels = []
        self.classes = list(set(image_classes))
        self.class_to_label = {c: i for i, c in enumerate(self.classes)}
        self.image_size = 224
        self.transforms = transforms.Compose([
            transforms.Resize(self.image_size),
            transforms.CenterCrop(self.image_size),
            transforms.ToTensor(),
            transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))
        ])
        for image, image_class in zip(image_list, image_classes):
            transformed_image = self.transforms(image)
            self.images.append(transformed_image)
            label = self.class_to_label[image_class]
            self.labels.append(label)

    def __getitem__(self, index):
        return self.images[index], self.labels[index]

    def __len__(self):
        return len(self.images)


def getMales():
    imgs = []
    cls = []

    for i in range(1, 51):
        name = f"male ({i})"
        image = Image.open(f"faces/male/{name}.jpg")
        cls.append(1)
        imgs.append(image)

    return imgs, cls

def getFemales():
    imgs = []
    cls = []

    for i in range(1, 51):
        name = f"female ({i})"
        image = Image.open(f"faces/female/{name}.jpg")
        cls.append(1)
        imgs.append(image)

    return imgs, cls


def getOthers():
    imgs = []
    cls = []

    for i in range(1, 51):
        name = f"other ({i})"
        image = Image.open(f"faces/other/{name}.jpg")
        cls.append(0)
        imgs.append(image)

    return imgs, cls


def getImages():
    males = getMales()
    females = getFemales()
    others = getOthers()

    images = []
    images.extend(males[0])
    images.extend(females[0])
    images.extend(others[0])

    classes = []
    classes.extend(males[1])
    classes.extend(females[1])
    classes.extend(others[1])

    return images, classes

def getTestImages():
    imgs = []
    cls = []

    for i in range(1, 51):
        name = f"testFace ({i})"
        image = Image.open(f"faces/testSet/{name}.jpg")
        cls.append(1)
        imgs.append(image)

    for i in range(1, 26):
        name = f"testNoFace ({i})"
        image = Image.open(f"faces/testSet/{name}.jpg")
        cls.append(0)
        imgs.append(image)

    return imgs, cls


def getDataset():
    (images, classes) = getImages()

    icd = ImageClassifierDataset(images, classes)
    return icd

def getTestDataset():
    (images, classes) = getTestImages()

    icd = ImageClassifierDataset(images, classes)
    return icd

def main():
    icd = getDataset()
    print(len(icd))

    #print(icd[0][1])


if __name__ == "__main__":
    main()


