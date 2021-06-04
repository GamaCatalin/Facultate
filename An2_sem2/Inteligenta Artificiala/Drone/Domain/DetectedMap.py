from Enviroment import *

class DMap():
    def __init__(self):
        self.__n = 20
        self.__m = 20
        self.surface = np.zeros((self.__n, self.__m))
        for i in range(self.__n):
            for j in range(self.__m):
                self.surface[i][j] = -1

    def getCell(self,x,y):
        return self.surface[x][y]

    def markAsVisited(self,x,y):
        self.surface[x][y]=2

    def markDetectedWalls(self, e, x, y):
        #   To DO
        # mark on this map the wals that you detect
        wals = e.readUDMSensors(x, y)

        i = x - 1
        if wals[UP] > 0:
            while (( i>=0) and (i >= x - wals[UP])):
                if(self.surface[i][y]!=2):
                    self.surface[i][y] = 0
                i = i - 1
        if (i>=0):
            self.surface[i][y] = 1

        i = x + 1
        if wals[DOWN] > 0:
            while ((i < self.__n) and (i <= x + wals[DOWN])):
                if(self.surface[i][y]!=2):
                    self.surface[i][y] = 0
                i = i + 1
        if (i < self.__n):
            self.surface[i][y] = 1

        j = y + 1
        if wals[LEFT] > 0:
            while ((j < self.__m) and (j <= y + wals[LEFT])):
                if(self.surface[x][j]!=2):
                    self.surface[x][j] = 0
                j = j + 1
        if (j < self.__m):
            self.surface[x][j] = 1

        j = y - 1
        if wals[RIGHT] > 0:
            while ((j >= 0) and (j >= y - wals[RIGHT])):
                if(self.surface[x][j]!=2):
                    self.surface[x][j] = 0
                j = j - 1
        if (j >= 0):
            self.surface[x][j] = 1

        return None

    def isWallForward(self,x,y,dir):
        if(dir==UP and x > 0 and self.surface[x-1][y]==-1):
            return True
        if(dir==DOWN and x < 19 and self.surface[x+1][y]==-1):
            return True
        if(dir==LEFT and y > 0 and self.surface[x][y-1]==-1):
            return True
        if(dir==RIGHT and y < 19 and self.surface[x][y+1]==-1):
            return True

        return False

    def emptyDirection(self,x,y):
        if(x > 0 and self.surface[x-1][y]==0):
            return UP
        if(y > 0 and self.surface[x][y-1]==0):
            return LEFT
        if(x < 19 and self.surface[x+1][y]==0):
            return DOWN
        if(y < 19 and self.surface[x][y+1]==0):
            return RIGHT

        return -1


    def image(self, x, y):


        imagine = pygame.Surface((420 ,420))
        brick = pygame.Surface((20 ,20))
        empty = pygame.Surface((20 ,20))
        visited = pygame.Surface((20 ,20))
        empty.fill(WHITE)
        brick.fill(BLACK)
        imagine.fill(GRAYBLUE)
        visited.fill(GREEN)

        for i in range(self.__n):
            for j in range(self.__m):
                if (self.surface[i][j] == 1):
                    imagine.blit(brick, ( j * 20, i * 20))
                elif (self.surface[i][j] == 0):
                    imagine.blit(empty, ( j * 20, i * 20))
                elif (self.surface[i][j]==2):
                    imagine.blit(visited ,( j *20 , i *20))

        drona = pygame.image.load("drona.png")
        imagine.blit(drona, (y *20, x * 20))
        return imagine
