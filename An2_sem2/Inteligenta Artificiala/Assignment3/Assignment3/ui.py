# -*- coding: utf-8 -*-


# imports
from controller import *
from gui import *
from time import *
import numpy as np
import matplotlib
import matplotlib.pyplot as plt



# create a menu
#   1. map options:
#         a. create random map
#         b. load a map
#         c. save a map
#         d visualise map
#   2. EA options:
#         a. parameters setup
#         b. run the solver
#         c. visualise the statistics
#         d. view the drone moving on a path
#              function gui.movingDrone(currentMap, path, speed, markseen)
#              ATTENTION! the function doesn't check if the path passes trough walls


"""

self.__repo = args[0]
self.__populationSize = args[1]
self.__individualSize = args[2]
self.__startPos = args[3]
self.__bestIndividualsNr = args[4]
self.__crossoverProbability = args[5]
self.__mutationProbability = args[6]
self.__maxIterations = args[7]

"""


class Menu:
    def __init__(self):
        self.__isRunning = True
        self.__repository = repository()
        self.__populationSize = 80
        self.__individualSize = 15
        self.__startPos = (0, 0)
        self.__bestIndividualsNr = 40
        self.__crossoverProbability = 0.5
        self.__mutationProbability = 0.02
        self.__maxIterations = 10000
        self.__dummyMap = Map()
        self.__dummyMap.randomMap()
        self.__controller = controller([self.__repository,
                                        self.__populationSize,
                                        self.__individualSize,
                                        self.__startPos,
                                        self.__bestIndividualsNr,
                                        self.__crossoverProbability,
                                        self.__mutationProbability,
                                        self.__maxIterations,
                                        self.__dummyMap])
        self.__stoppingFitness = 1000
        self.__lastBest = Individual()
        self.__statistics = []

        self.__repository.cmap = self.__dummyMap
        self.__lastRunStartTime = time()
        self.__lastRunEndTime = time()



    def run(self):
        while (self.__isRunning):
            self.printMenu()
            self.__isRunning = self.processCommand()

    def printMenu(self):
        print("\n              Menu")
        print("1. Map options")
        print("2. EA options")
        print("\n0. Exit")

        pass

    def processCommand(self):

        command = input("Enter command: ")
        if(command=="1"):
            submenuRun = True
            while(submenuRun):
                self.printMapMenu()
                submenuRun=self.processMenuCommand()
            return True
        elif(command=="2"):
            submenuRun = True
            while(submenuRun):
                self.printEAMenu()
                submenuRun=self.processEACommand()
            return True
        elif(command=="0"):

            return False
        else:
            print("Wrong command!")
            return True

    def printMapMenu(self):
        print("\n              Map Menu")
        print("1. Random map")
        print("2. Load map")
        print("3. Save map")
        print("4. Visualize")
        print("5. Get start position")
        print("6. Set start position")
        print("\n0. Back\n")

    def processMenuCommand(self):
        command = input("Enter command: ")
        if (command == "1"):
            self.randomMap()
            return True
        elif (command == "2"):
            self.loadMap()
            return True
        elif (command == "3"):
            self.saveMap()
            return True
        elif (command == "4"):
            self.visualizeMap()
            return True
        elif (command == "5"):
            self.getStartPos()
            return True
        elif (command == "6"):
            self.setStartPos()
            return True
        elif (command == "0"):
            return False
        else:
            print("Wrong command!")
            return True

    def randomMap(self):
        self.__repository.createRandomMap(0.2)

    def loadMap(self):
        mapName = input("Enter file name: ")
        self.__repository.loadMapFromFile(mapName)
        self.__dummyMap = self.__repository.getMap()

    def saveMap(self):
        mapName = input("Enter file name: ")
        self.__repository.saveMapToFile(mapName)

    def visualizeMap(self):
        visualize(self.__repository.cmap,self.__startPos[0],self.__startPos[1])

    def getStartPos(self):
        print(f"Start position is: {self.__startPos}")

    def setStartPos(self):
        x = int(input("Start x: "))
        y = int(input("Start y: "))
        self.__startPos = (x, y)

    #   2. EA options:
    #         a. parameters setup
    #         b. run the solver
    #         c. visualise the statistics
    #         d. view the drone moving on a path
    #              function gui.movingDrone(currentMap, path, speed, markseen)

    def printEAMenu(self):
        print("\n              EA Menu")
        print("1. Parameters menu")
        print("2. Run solver")
        print("3. View statistics")
        print("4. View menu")
        print("\n0. Back")

    def processEACommand(self):
        command = input("Enter command: ")
        if (command == "1"):
            submenuRun = True
            while (submenuRun):
                self.printParametersMenu()
                submenuRun = self.processParametersCommand()
            return True
        elif (command == "2"):
            self.runSolver()
            return True
        elif (command == "3"):
            self.viewStatistics()
            return True
        elif (command == "4"):
            submenuRun = True
            while (submenuRun):
                self.printViewMenu()
                submenuRun = self.processViewCommand()
            return True
        elif (command == "0"):
            return False
        else:
            print("Wrong command!")
            return True

    def runSolver(self):
        controllerArgs = [
            self.__repository,
            self.__populationSize,
            self.__individualSize,
            self.__startPos,
            self.__bestIndividualsNr,
            self.__crossoverProbability,
            self.__mutationProbability,
            self.__maxIterations,
            self.__dummyMap
        ]

        self.__controller = controller(controllerArgs)

        solverArgs = [self.__stoppingFitness]

        (self.__lastBest,self.__statistics,self.__lastRunStartTime,self.__lastRunEndTime) = self.__controller.solver(solverArgs)

    def viewStatistics(self):
        print(f"Last best path: {self.__lastBest.getPath()}")
        print(f"Fitnesses: {self.__statistics}")

        average = np.average(self.__statistics)
        deviation = np.std(self.__statistics)

        print(f"Average: {average}")
        print(f"Deviation: {deviation}")


        plt.plot(range(0,len(self.__statistics)), self.__statistics)
        plt.show()





    def printParametersMenu(self):
        print("\n              Parameters Menu")
        print("1. Show parameters")
        print("2. Set population size")
        print("3. Set battery length")
        print("4. Set starting position")
        print("5. Set crossover probability")
        print("6. Set mutation probability")
        print("7. Set max iterations")
        print("8. Set stop condition")
        print("\n0. Back")

    def processParametersCommand(self):
        command = input("Enter command: ")
        if (command == "1"):
            self.printParameters()
            return True
        elif (command == "2"):
            self.setPopulationSize()
            return True
        elif (command == "3"):
            self.setBatteryLenght()
            return True
        elif (command == "4"):
            self.setStartPos()
            return True
        elif (command == "5"):
            self.setCrossover()
            return True
        elif (command == "6"):
            self.setMutation()
            return True
        elif (command == "7"):
            self.setMaxIterations()
            return True
        elif(command == "8"):
            self.setStoppingFitness()
            return True
        elif (command == "0"):
            return False
        else:
            print("Wrong command!")
            return True




    """

            self.__repo = args[0]
            self.__populationSize = args[1]
            self.__individualSize = args[2]
            self.__startPos = args[3]
            self.__bestIndividualsNr = args[4]
            self.__crossoverProbability = args[5]
            self.__mutationProbability = args[6]
            self.__maxIterations = args[7]

            """

    def printParameters(self):
        print("Parameters:{")
        print(f"Population size: {self.__populationSize}")
        print(f"Battery length: {self.__individualSize}")
        print(f"Starting position: {self.__startPos}")
        print(f"Top individuals number: {self.__bestIndividualsNr}")
        print(f"Crossover probability: {self.__crossoverProbability}")
        print(f"Mutation probability: {self.__mutationProbability}")
        print(f"Max iterations: {self.__maxIterations}")
        print(f"Stopping fitness: {self.__stoppingFitness}")
        print("}")

    def setPopulationSize(self):
        self.__populationSize = int(input("Enter population size: "))

    def setBatteryLenght(self):
        self.__individualSize = int(input("Enter battery life: "))
        self.__bestIndividualsNr = int(self.__individualSize/2)

    def setCrossover(self):
        self.__crossoverProbability = float(input("Enter crossover probability: "))

    def setMutation(self):
        self.__mutationProbability = float(input("Enter mutation probability: "))

    def setMaxIterations(self):
        self.__maxIterations = float(input("Enter max iterations: "))

    def setStoppingFitness(self):
        self.__stoppingFitness = int(input("Enter stopping fitness: "))






    def printViewMenu(self):
        print("\n              View Menu")
        print("1. Show last best path")
        print("2. Show all best paths")
        print("3. Run last best path")
        print("4. Run specific best path")
        print("\n0. Back")

    def processViewCommand(self):
        command = input("Enter command: ")
        if (command == "1"):
            self.printLastBestPath()
            return True
        elif (command == "2"):
            self.printAllBestPaths()
            return True
        elif (command == "3"):
            self.runLastBestPath()
            return True
        elif (command == "4"):
            self.runSpecificPath()
            return True
        elif (command == "0"):
            return False
        else:
            print("Wrong command!")
            return True

    def printLastBestPath(self):
        print(self.__lastBest.getPath())

    def printAllBestPaths(self):
        bestIndividuals = self.__controller.getBestIndividuals()

        for i in range(len(bestIndividuals)):
            print(f"{i}: {bestIndividuals[i].getPath()}")

    def runLastBestPath(self):
        movingDrone(self.__repository.getMap(), self.__controller.convertMovesToPositions(self.__lastBest.getPath()))

    def runSpecificPath(self):
        index = int(input("Enter iteration number: "))
        bestIndividuals = self.__controller.getBestIndividuals()
        movingDrone(self.__repository.getMap(),self.__controller.convertMovesToPositions(bestIndividuals[index].getPath()))



ui = Menu()

if __name__ == "__main__":
    ui.run()
