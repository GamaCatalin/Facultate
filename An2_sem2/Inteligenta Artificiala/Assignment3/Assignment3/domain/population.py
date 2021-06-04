from random import *
import numpy as np
from Assignment3.domain.individual import *
from Assignment3.domain.map import *

class Population():
    def __init__(self, populationSize=0, individualSize=0, startX=0,startY=0, currentMap = Map()):
        self.__populationSize = populationSize
        self.__individualSize = individualSize
        self.__v = [Individual(individualSize,startX,startY) for x in range(populationSize)]
        self.__map = currentMap

    def getPopulationSize(self):
        return self.__populationSize

    def getIndividualSize(self):
        return self.__individualSize

    def getMap(self):
        return copy.copy(self.__map)

    def getIndividuals(self):
        return self.__v

    def evaluate(self):
        # evaluates the population
        for x in self.__v:
            x.fitness(self.__map)

    def selection(self, k=0):

        self.evaluate()

        self.__v.sort(reverse=True)

        topIndividuals = self.__v[:k]

        return topIndividuals

        # perform a selection of k individuals from the population
        # and returns that selection
        pass

    def getBest(self):
        self.__v.sort(reverse=True)
        return self.__v[0]


    def setIndividualsPool(self,pool):
        self.__v = pool


    def getAverageFitness(self):
        avgFitness = 0
        for elem in self.__v:
            avgFitness += elem.getFitness()

        avgFitness = avgFitness/self.__populationSize

        return avgFitness