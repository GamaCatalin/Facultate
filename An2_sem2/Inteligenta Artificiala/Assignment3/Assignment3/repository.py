# -*- coding: utf-8 -*-

from Assignment3.domain import *
from Assignment3.domain.map import *
from Assignment3.domain.population import *



class repository():
    def __init__(self):
        self.__populations = []
        self.__startX = 0
        self.__startY = 0
        self.__lastPopulation = Population()
        self.__currentPopulation = Population()
        self.cmap = Map()


    def setStartPosition(self,position):
        (self.__startX,self.__startY) = position


    def createPopulation(self, args):
        # args = [populationSize, individualSize] -- you can add more args

        population = Population(args[0], args[1], self.__startX, self.__startY, self.cmap)

        self.__populations.append(population)
        self.__lastPopulation = population

        return population

    def addPopulation(self,population):
        self.__populations.append(population)
        self.__lastPopulation = population

    def getMap(self):
        return self.cmap

    def getLastPopulation(self):
        return copy.copy(self.__lastPopulation)

    def loadMapFromFile(self, fileName):
        self.cmap.loadMap(fileName)

    def saveMapToFile(self, fileName):
        self.cmap.saveMap(fileName)

    def createRandomMap(self,wallDensity=0.2):
        self.cmap.randomMap(wallDensity)

    def savePopulationsToFile(self):
        file = open("populations.txt", "wt")
        file.close()

        file = open("populations.txt", "at")
        for i in range(len(self.__populations)):
            file.write("\n")
            file.write(f"Population: {i}\n")
            file.write(f"Starting position: ({self.__startX},{self.__startY})\n")
            file.write(f"Best individual fitness: {self.__populations[i].getBest().getFitness()}\n")
            file.write(f"Best individual path: {self.__populations[i].getBest().getPath()}\n")
        file.close()

    def getFitnessTendency(self):
        fitnessPopulations = []

        for i in range(len(self.__populations)-1):
            population = self.__populations[i]
            fitnessPopulations.append(population.getAverageFitness())

        return fitnessPopulations

    def getPopulationsLenght(self):
        return len(self.__populations)

    # TO DO : add the other components for the repository: 
    #    load and save from file, etc

    def getAllBest(self):
        bestIndividuals = []

        for elem in self.__populations:
            bestIndividuals.append(elem.getBest())

        return bestIndividuals