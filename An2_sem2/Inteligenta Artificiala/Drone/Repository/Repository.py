import Domain.Drone
import Domain.Enviroment
import Domain.DetectedMap



class Repository():
    def __init__(self):
        self.lastMoves=[]
        self.nextMoves=[]


    def getNextMove(self):
        return self.nextMoves.pop(0)

    def addNextMove(self,nextMove):
        return self.nextMoves.append(nextMove)

    def getLastMove(self):
        return self.lastMoves.pop()

    def addLastMove(self,lastMove):
        self.lastMoves.append(lastMove)