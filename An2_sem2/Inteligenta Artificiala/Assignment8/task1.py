from PIL import Image
from matplotlib import image as img
from matplotlib import pyplot


def pilOpen():
    image = Image.open("f1.jpg")
    print(image.format)
    print(image.mode)
    print(image.size)
    # show the image
    image.show()

def plotOpen():
    data = img.imread("f1.jpg")

    print(data.dtype)
    print(data.shape)
    # display the array of pixels as an image

    pyplot.imshow(data)
    pyplot.show()

def resize():
    # load the image
    image = Image.open('f1.jpg')
    # report the size of the image
    print(image.size)
    # create a thumbnail and preserve aspect ratio
    image.thumbnail((100, 100))
    # report the size of the thumbnail

    image.show()
    print(image.size)


def main():
    pilOpen()
    plotOpen()
    resize()

if __name__ == "__main__":
    main()
