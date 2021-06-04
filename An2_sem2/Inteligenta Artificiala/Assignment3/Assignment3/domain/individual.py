from random import *
from Assignment3.domain.utils import *
import numpy as np

class gene:
    def __init__(self):
        self._gene = randint(0, 3)
        # random initialise the gene according to the representation

    #def __str__(self):
    #    return self._gene


class Individual:
    def __init__(self, size=0, startX=0, startY=0):
        self.__size = size
        self.__chromosome = [randint(0,3) for i in range(self.__size)]
        self.__x = startX
        self.__y = startY
        self.__mutateProbability = 0.04
        self.__crossoverProbability = 0.8
        self.__fitness = 0

    def __lt__(self, other):
        return self.__fitness < other.__fitness

    def __str__(self):
        return self.__fitness

    def fitness(self, map):
        # compute the fitness for the individual
        # and save it in self.__f

        self.__fitness = 0

        moves = self.__chromosome

        x = self.__x
        y = self.__y

        surface = map.getSurface()

        enteredWall = False

        for i in range(self.__size):
            if (surface[x][y] == 1):
                self.__fitness -= 20
                enteredWall = True
            elif (x < 0 or x > mapLength - 1 or y < 0 or y > mapLength - 1):
                enteredWall = True
                self.__fitness -= 10
            elif (i > self.__size/2 and (not enteredWall) and x == self.__x and y == self.__y):
                self.__fitness += 900
            else:
                possitiveGain = self.checkArea(surface,x,y)
                self.__fitness += possitiveGain
                #print(surface)
                #print(f"Current fitness: {self.__fitness},           current gain: {possitiveGain}")


            if (moves[i] == UP):
                x -= 1
            elif (moves[i] == LEFT):
                y -= 1
            elif (moves[i] == DOWN):
                x += 1
            elif (moves[i] == RIGHT):
                y += 1

    def checkArea(self,surface,x,y):
        yf = 0
        xf = 0

        seenArea = 0

        # UP
        xf = x - 1
        while ((xf >= 0 and y < mapLength-1 and y >= 0) and (surface[xf][y] != 1)):
            if (surface[xf][y] == 0):
                #print("pass up")
                seenArea += 1
            surface[xf][y] = 2
            xf = xf - 1

        # DOWN
        xf = x + 1
        while ((xf < mapLength-1 and y < mapLength-1 and y >= 0) and (surface[xf][y] != 1)):
            if (surface[xf][y] == 0):
                #print("pass down")
                seenArea += 1
            surface[xf][y] = 2
            xf = xf + 1
        # LEFT
        yf = y + 1
        while ((yf < mapLength-1 and x < mapLength-1 and x >= 0) and (surface[x][yf] != 1)):
            if (surface[x][yf] == 0):
                #print("pass left")
                seenArea += 1
            surface[x][yf] = 2
            yf = yf + 1

        # RIGHT
        yf = y - 1
        while ((yf >= 0 and x < mapLength-1 and x >= 0) and (surface[x][yf] != 0)):
            if (surface[x][yf] == 0):
                #print("pass right")
                seenArea += 1
            surface[x][yf] = 2
            yf = yf - 1

        #print(f"Seen area: {seenArea}")
        return seenArea



    def mutate(self, mutateProbability=0.04):
        # perform a mutation with respect to the representation

        if random() < mutateProbability:
            index = randint(0,self.__size-1)
            self.__chromosome[index] = randint(0,3)


    def crossover(self, otherParent, crossoverProbability=0.8):
        offspring1, offspring2 = Individual(self.__size), Individual(self.__size)

        # perform the crossover between the self and the otherParent

        for i in range(self.__size):
            if random() < crossoverProbability:
                offspring1.__chromosome[i] = self.__chromosome[i]
                offspring2.__chromosome[i] = otherParent.__chromosome[i]
            else:
                offspring1.__chromosome[i] = otherParent.__chromosome[i]
                offspring2.__chromosome[i] = self.__chromosome[i]

        return offspring1, offspring2



    def getFitness(self):
        return self.__fitness

    def getPath(self):
        return self.__chromosome

    def setMutate(self, n):
        self.__mutateProbability = n

    def setCrossover(self, n):
        self.__crossoverProbability = n