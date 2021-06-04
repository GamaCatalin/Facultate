from random import *
import numpy as np
import pickle
import copy


class Map():
    def __init__(self, n=20, m=20):
        self.n = n
        self.m = m
        self.surface = np.zeros((self.n, self.m))

    def randomMap(self, fill=0.2):
        for i in range(self.n):
            for j in range(self.m):
                if random() <= fill:
                    self.surface[i][j] = 1

    def saveMap(self, mapFile):
        with open(mapFile, 'wb') as f:
            pickle.dump(self, f)
            f.close()

    def loadMap(self, mapfile):
        with open(mapfile, "rb") as f:
            dummy = pickle.load(f)
            self.n = dummy.n
            self.m = dummy.m
            self.surface = dummy.surface
            f.close()

    def setSurface(self,newSurface):
        self.surface = newSurface

    def getSurface(self):
        return copy.copy(self.surface)

    def __str__(self):
        string = ""
        for i in range(self.n):
            for j in range(self.m):
                string = string + str(int(self.surface[i][j]))
            string = string + "\n"
        return string

    def seenArea(self,x,y):
        seenArea = 0
        yf = 0
        xf = 0

        # UP
        xf = x - 1
        while ((xf >= 0 and y<self.m and y >= 0) and (self.surface[xf][y] != 1)):
            if(self.surface[xf][y] == 0):
                print("pass up")
                seenArea += 1
            self.surface[xf][y] = 2
            xf = xf - 1

        # DOWN
        xf = x + 1
        while ((xf < self.n and y<self.m and y >= 0) and (self.surface[xf][y] != 1)):
            if (self.surface[xf][y] == 0):
                print("pass down")
                seenArea += 1
            self.surface[xf][y] = 2
            xf = xf + 1
        # LEFT
        yf = y + 1
        while ((yf < self.m and x<self.n and x>= 0) and (self.surface[x][yf] != 1)):
            if(self.surface[x][yf]==0):
                print("pass left")
                seenArea += 1
            self.surface[x][yf] = 2
            yf = yf + 1

        # RIGHT
        yf = y - 1
        while ((yf >= 0 and x<self.n and x>= 0) and (self.surface[x][yf] != 0)):
            if (self.surface[x][yf] == 0):
                print("pass right")
                seenArea += 1
            self.surface[x][yf] = 2
            yf = yf - 1

        print(f"Seen area: {seenArea}")

        return seenArea