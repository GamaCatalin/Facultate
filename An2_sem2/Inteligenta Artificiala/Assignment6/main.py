import math
import operator
import numpy
import numpy as np
import csv
import matplotlib.pyplot as plt
from matplotlib.image import imread


class Point:
    def __init__(self):
        self.label = ""
        self.x = 0
        self.y = 0
        self.cluster = None

    def closestCluster(self, clusters):
        minimum = None
        for cluster in clusters:
            if minimum is None:
                minimum = cluster
                continue
            clusterDist = math.dist([cluster.meanX, cluster.meanY], [self.x, self.y])
            minimumDist = math.dist([minimum.meanX, minimum.meanY], [self.x, self.y])

            # #default
            # if clusterDist < minimumDist:
            #     minimum = cluster

            #somewhat optimum
            if abs(clusterDist-minimumDist) <= 1.1:
                allPoints = list(cluster.points)
                allPoints.extend(x for x in minimum.points if x not in allPoints)
                labels = self.nearestLabel(allPoints)
                if labels[cluster.label] < labels[minimum.label]:
                    minimum = cluster
            else:
                if clusterDist < minimumDist:
                    minimum = cluster

        return minimum

    def nearestLabel(self, points):
        labels = {"A": 0, "B": 0, "C": 0, "D": 0}

        for point in points:
            distance = math.dist([point.x, point.y], [self.x, self.y])
            if distance <= 0.5:
                labels[point.label] += distance

        return labels

class Cluster:
    def __init__(self, label):
        self.points = []
        self.label = label
        self.meanX = 0
        self.meanY = 0

    def addPoint(self, point):
        self.points.append(point)

        if point.cluster is not None:
            point.cluster.points.remove(point)

        point.cluster = self

        return self.updateMeans()

    def updateMeans(self):
        oldMeanX = self.meanX
        oldMeanY = self.meanY

        sumX = 0
        sumY = 0

        for i in self.points:
            sumX += i.x
            sumY += i.y
        self.meanX = sumX / len(self.points)
        self.meanY = sumY / len(self.points)

        if abs(self.meanX - oldMeanX) < 0.000001 and abs(self.meanY - oldMeanY) < 0.000001:
            return False
        return True

    def updateLabel(self):
        freq = {"A": 0, "B": 0, "C": 0, "D": 0}
        for point in self.points:
            freq[point.label] += 1

        self.label = max(freq.items(), key=operator.itemgetter(1))[0]

    def statistics(self, points):
        assignedPoints = 0
        notAssignedPoints = 0
        outsidePoints = 0
        clusterPoints = 0
        currentPoints = 0

        for point in points:
            if point.label == self.label:
                assignedPoints += 1
            else:
                notAssignedPoints += 1

        for point in points:
            if point not in self.points:
                if point.cluster.label != self.label:
                    outsidePoints += 1
                else:
                    clusterPoints += 1
            if point.cluster.label == self.label:
                currentPoints += 1

        accuracy = (assignedPoints - abs(assignedPoints-currentPoints)) / assignedPoints
        precision = (assignedPoints - abs(assignedPoints-currentPoints)) / ((assignedPoints + notAssignedPoints) - outsidePoints)
        rappel = assignedPoints / (assignedPoints + clusterPoints)
        score = 2 / ((1 / rappel) / (1 / precision))

        return accuracy, precision, rappel, score


def sample(points, count):
    np.random.RandomState(123)

    indexes = []
    for i in range(len(points)):
        indexes.append(i)
    randomIds = np.random.permutation(indexes)

    initClusters = []

    for i in range(count):
        initClusters.append(points[randomIds[i]])

    return initClusters


def readPoints():
    points = []

    with open('dataset.csv', newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=',', quotechar='|')

        firstRow = False

        for row in spamreader:
            if (firstRow):
                newData = Point()
                newData.y = float(row.pop())
                newData.x = float(row.pop())
                newData.label = row.pop()
                points.append(newData)
            else:
                firstRow = True

    return points


def plotClusters(clusters):
    for cluster in clusters:
        if cluster.label == "A":
            formatString = "yo"
        elif cluster.label == "B":
            formatString = "go"
        elif cluster.label == "C":
            formatString = "bo"
        else:
            formatString = "co"

        for point in cluster.points:
            plt.plot(point.x, point.y, formatString)

        plt.plot(cluster.meanX, cluster.meanY, "rX")

    plt.show()

def main():
    clusters = [Cluster('A'), Cluster('B'), Cluster('C'), Cluster('D')]

    points = readPoints()

    randomPoints = sample(points, 4)

    for i in range(len(randomPoints)):
        clusters[i].meanX = randomPoints[i].x
        clusters[i].meanY = randomPoints[i].y

    doScatter = True

    counter = 0

    while doScatter:
        doScatter = False

        for point in points:
            bestCluster = point.closestCluster(clusters)

            if bestCluster.addPoint(point) and counter <= 10000:
                doScatter = True

        counter += 1

    for cluster in clusters:
        cluster.updateLabel()

    for cluster in clusters:
        statistics = cluster.statistics(points)
        print(f"Label: {cluster.label} -- {len(cluster.points)}\n"
              f"Accuracy: {statistics[0]}\n"
              f"Precision: {statistics[1]}\n"
              f"Rappel: {statistics[2]}\n"
              f"Score: {statistics[3]}\n\n")

    plotClusters(clusters)


if __name__ == "__main__":
    main()
