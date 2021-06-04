from Repository import *


class Service():
    def __init__(self,drone,repository,detectedMap):
        self.drone = drone
        self.repo = repository
        self.detectedMap = detectedMap
        self.isDone = False


    def moveDrone(self,nextMove):
        self.drone.moveDirection(nextMove)

    def moveDroneReversed(self,nextMove):
        self.drone.moveReversed(nextMove)

    def moveDFS(self, detectedMap):

        self.detectedMap.markAsVisited(self.drone.getX(), self.drone.getY())


        nextMove = self.detectedMap.emptyDirection(self.drone.getX(), self.drone.getY())

        if(nextMove!=-1):
            self.moveDrone(nextMove)
        else:
            nextMove = self.self.repo.getLastMove()
            self.moveDroneReversed(nextMove)

        if(len(self.repo.lastMoves)==0):
            self.isDone=True