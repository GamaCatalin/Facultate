from Domain.DetectedMap import *

class Drone():


    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.queue = []
        self.lastMoves = []
        self.isMoving = True

    def getX(self):
        return self.x

    def getY(self):
        return self.y

    def move(self, detectedMap):
        pressed_keys = pygame.key.get_pressed()
        if self.x > 0:
            if pressed_keys[K_UP] and detectedMap.surface[self.x - 1][self.y] == 0:
                self.x = self.x - 1
        if self.x < 19:
            if pressed_keys[K_DOWN] and detectedMap.surface[self.x + 1][self.y] == 0:
                self.x = self.x + 1

        if self.y > 0:
            if pressed_keys[K_LEFT] and detectedMap.surface[self.x][self.y - 1] == 0:
                self.y = self.y - 1
        if self.y < 19:
            if pressed_keys[K_RIGHT] and detectedMap.surface[self.x][self.y + 1] == 0:
                self.y = self.y + 1


    def updateQueue(self,detectedMap):
        print("Entered update")

        a = self.x
        b = self.y

        if (self.x > 0 and (detectedMap.surface[self.x - 1][self.y] == 0 or detectedMap.surface[self.x - 1][self.y] == 2)):
            # top clear
            print("entered UP")
            a = a-1
            while (detectedMap.surface[a][b]==0 or detectedMap.surface[a][b] == 2) and a>0:
                a = a-1
                self.queue.append(UP)
        elif (self.y > 0 and (detectedMap.surface[self.x][self.y - 1] == 0 or detectedMap.surface[self.x][self.y - 1] == 2)):
            # left clear
            print("entered LEFT")
            b=b-1
            while (detectedMap.surface[a][b] == 0 or detectedMap.surface[a][b] == 2) and b > 0:
                b = b - 1
                self.queue.append(LEFT)
        elif (self.x < 19 and (detectedMap.surface[self.x + 1][self.y] == 0 or detectedMap.surface[self.x + 1][self.y] == 2)):
            # down clear
            print("entered DOWN")
            a=a+1
            while (detectedMap.surface[a][b] == 0 or detectedMap.surface[a][b] == 2) and a < 19:
                a = a + 1
                self.queue.append(DOWN)
        elif (self.y < 19 and (detectedMap.surface[self.x][self.y + 1] == 0 or detectedMap.surface[self.x][self.y + 1] == 2)):
            # right clear
            print("entered RIGHT")
            b=b+1
            while (detectedMap.surface[a][b] == 0 or detectedMap.surface[a][b] == 2) and b <19:
                b = b + 1
                self.queue.append(RIGHT)

    def getNextMove(self,detectedMap):

        possibleMove = -1
        nextMove = -1

        if (self.x > 0 and nextMove==-1 and (detectedMap.surface[self.x - 1][self.y] == 0 or detectedMap.surface[self.x - 1][self.y] == 2) ):
            # top clear
            print("entered UP")
            if (detectedMap.surface[self.x - 1][self.y] == 2):
                possibleMove = UP
            else:
                nextMove = UP
        if (self.y > 0  and nextMove==-1 and (detectedMap.surface[self.x][self.y - 1] == 0 or detectedMap.surface[self.x][self.y - 1] == 2)):
            # left clear
            print("entered LEFT")
            if (detectedMap.surface[self.x][self.y - 1] == 2):
                possibleMove = LEFT
            else:
                nextMove = LEFT
        if (self.x < 19 and nextMove==-1 and (detectedMap.surface[self.x + 1][self.y] == 0 or detectedMap.surface[self.x + 1][self.y] == 2)):
            # down clear
            print("entered DOWN")
            if (detectedMap.surface[self.x+1][self.y] == 2):
                possibleMove = DOWN
            else:
                nextMove = DOWN
        if (self.y < 19 and nextMove==-1 and (detectedMap.surface[self.x][self.y + 1] == 0  or detectedMap.surface[self.x][self.y + 1] == 2)):
            # right clear
            print("entered RIGHT")
            if(detectedMap.surface[self.x][self.y + 1] == 2):
                possibleMove =  RIGHT
            else:
                nextMove = RIGHT

        if(nextMove==-1):
            nextMove=possibleMove

        return nextMove


    def stuckHelper(self,detectedMap):
        print("Entered stuck helper")

        possibleMove = -1
        nextMove = -1

        if (self.lastMoves[-1] != UP and self.x > 0 and nextMove == -1 and (
                detectedMap.surface[self.x - 1][self.y] == 0 or detectedMap.surface[self.x - 1][self.y] == 2)):
            # top clear
            print("entered UP")
            if (detectedMap.surface[self.x - 1][self.y] == 2 and possibleMove==-1):
                possibleMove = UP
            else:
                nextMove = UP
        if (self.lastMoves[-1] != LEFT and self.y > 0 and nextMove == -1 and (
                detectedMap.surface[self.x][self.y - 1] == 0 or detectedMap.surface[self.x][self.y - 1] == 2)):
            # left clear
            print("entered LEFT")
            if (detectedMap.surface[self.x][self.y - 1] == 2 and possibleMove==-1):
                possibleMove = LEFT
            else:
                nextMove = LEFT
        if (self.lastMoves[-1] != DOWN and self.x < 19 and nextMove == -1 and (
                detectedMap.surface[self.x + 1][self.y] == 0 or detectedMap.surface[self.x + 1][self.y] == 2)):
            # down clear
            print("entered DOWN")
            if (detectedMap.surface[self.x + 1][self.y] == 2 and possibleMove==-1):
                possibleMove = DOWN
            else:
                nextMove = DOWN
        if (self.lastMoves[-1] != RIGHT and self.y < 19 and nextMove == -1 and (
                detectedMap.surface[self.x][self.y + 1] == 0 or detectedMap.surface[self.x][self.y + 1] == 2)):
            # right clear
            print("entered RIGHT")
            if (detectedMap.surface[self.x][self.y + 1] == 2 and possibleMove==-1):
                possibleMove = RIGHT
            else:
                nextMove = RIGHT

        if (nextMove == -1):
            nextMove = possibleMove

        return nextMove


    def calculateWeights(self):

        weights=[0,0,0,0]

        for x in (len(self.lastMoves)-10,len(self.lastMoves)-1):
            weights[self.lastMoves[x]] += 1


        return weights

    def getBestDirection(self,detectedMap,nextMove):

        bestDirection = -1
        bestWeight = 99999

        weights = self.calculateWeights()

        for x in range (0,len(weights)):
            if(weights[x] < bestWeight and detectedMap.isWallForward(self.x,self.y,nextMove) and not(detectedMap.isWallForward(self.x,self.y,weights[x]))):
                bestWeight = weights[x]
                bestDirection = x

        print(bestDirection)
        return bestDirection

    def moveDirection(self,nextMove):

        passed = False

        if nextMove == UP and self.x>0:
            self.x = self.x - 1
            passed = True
        elif nextMove == LEFT and self.y>0:
            self.y = self.y - 1
            passed = True
        elif nextMove == DOWN and self.x<19:
            self.x = self.x + 1
            passed = True
        elif nextMove == RIGHT and self.y<19:
            self.y = self.y + 1
            passed = True

        if passed:
            self.lastMoves.append(nextMove)

    def moveReversed(self,nextMove):
        if nextMove == UP:
            self.x = self.x + 1
        elif nextMove == LEFT:
            self.y = self.y + 1
        elif nextMove == DOWN:
            self.x = self.x - 1
        elif nextMove == RIGHT:
            self.y = self.y - 1



    def moveSmart(self, detectedMap):

        print("Entered DFS")
        print(detectedMap.surface[self.x][self.y])
        print("Stack bellow")
        print(self.lastMoves)


        detectedMap.markAsVisited(self.x,self.y)

        nextMove = self.getNextMove(detectedMap)

        self.lastMoves.append(nextMove)

        if(len(self.lastMoves)>10 and self.lastMoves[-1] == self.lastMoves[-3] and self.lastMoves[-1]!=self.lastMoves[-2]):
            nextMove = self.getBestDirection(detectedMap,nextMove) #self.stuckHelper(detectedMap)

        self.moveDirection(nextMove)

    def printUpdateFrame(self,nextMove):
        print("Next moves below")
        print(self.lastMoves)
        print()
        print("Current coordinates: x=" + str(self.x) + " y=" + str(self.y))
        print("Next move: " + str(nextMove))
        print()



    def moveDFS(self, detectedMap):

        detectedMap.markAsVisited(self.x, self.y)


        nextMove = detectedMap.emptyDirection(self.x,self.y)

        self.printUpdateFrame(nextMove)

        if(nextMove!=-1):
            self.moveDirection(nextMove)
        else:
            nextMove = self.lastMoves.pop()
            self.moveReversed(nextMove)

        if(len(self.lastMoves)==0):
            self.x = None
            self.y = None