from repository import *
from time import *

class controller():
    def __init__(self, args):
        # args - list of parameters needed in order to create the controller
        self.__repo = args[0]
        self.__populationSize = args[1]
        self.__individualSize = args[2]
        self.__startPos = args[3]
        self.__bestIndividualsNr = args[4]
        self.__crossoverProbability = args[5]
        self.__mutationProbability = args[6]
        self.__maxIterations = args[7]
        self.__map = args[8]
        self.__iterationNr = 0
        self.__currentMapName = "testMap.map"

    

    def iteration(self, args=None):
        # args - list of parameters needed to run one iteration
        # a iteration:
        # selection of the parents
        # create offsprings by crossover of the parents
        # apply some mutations
        # selection of the survivors


        population = args[0]
        self.__repo.cmap=self.__map

        self.__iterationNr += 1

        if(self.__bestIndividualsNr%2!=0):
            self.__bestIndividualsNr-=1

        bestIndividuals = self.__repo.getLastPopulation().selection(self.__bestIndividualsNr)

        offsprings = []


        for i in range(int(self.__bestIndividualsNr/2)):
            newOffsprings = bestIndividuals[i].crossover(bestIndividuals[i+1],self.__crossoverProbability)
            newOffsprings[0].mutate(self.__mutationProbability)
            newOffsprings[1].mutate(self.__mutationProbability)
            offsprings.append(newOffsprings[0])
            offsprings.append(newOffsprings[1])

        offsprings.sort()

        resultIndividuals = []

        for i in range(self.__populationSize-1):
            if(i < self.__populationSize/2):
                resultIndividuals.append(bestIndividuals[i])
            else:
                resultIndividuals.append(offsprings[i-int(self.__bestIndividualsNr)])

        newPopulation = Population(self.__populationSize,self.__individualSize,self.__startPos[0],self.__startPos[1],copy.copy(self.__map))
        newPopulation.setIndividualsPool(resultIndividuals)

        self.__repo.addPopulation(newPopulation)

        return newPopulation

        pass
        
    def run(self, args=None):
        # args - list of parameters needed in order to run the algorithm
        # until stop condition
        #    perform an iteration
        #    save the information need it for the statistics

        # return the results and the info for statistics

        if args is None:
            args = []

        stoppingFitness = args[0]


        lastPopulation = self.__repo.getLastPopulation()

        bestIndividual = Individual()

        startTime = time()

        while(self.__iterationNr<self.__maxIterations):
            #print(f"Current iteration: {self.__iterationNr}")

            args[0] = lastPopulation

            lastPopulation = self.iteration(args)

            bestIndividual = lastPopulation.getBest()

            if(bestIndividual.getFitness()>=stoppingFitness):
                endTime = time()
                return [bestIndividual,self.__repo.getFitnessTendency(),startTime,endTime]

        endTime = time()
        return [bestIndividual, self.__repo.getFitnessTendency(),startTime,endTime]


    
    
    def solver(self, args):
        # args - list of parameters needed in order to run the solver
        
        # create the population,
        # run the algorithm
        # return the results and the statistics

        if (self.__repo.getPopulationsLenght() == 0):
            self.__repo.createPopulation([self.__populationSize, self.__individualSize])

        results = self.run(args)

        return results


    def getRandomMap(self):
        self.__repo.createRandomMap()


    def getBestIndividuals(self):
        return self.__repo.getAllBest()


    def convertMovesToPositions(self,movesPath):
        x = self.__startPos[0]
        y = self.__startPos[1]

        path = []
        path.append((x,y))
        for move in movesPath:
            if(move == UP):
                x-=1
            elif(move == LEFT):
                y-=1
            elif(move == DOWN):
                x+=1
            elif(move == RIGHT):
                y+=1

            path.append((x, y))

        return path

