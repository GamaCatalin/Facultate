# import the pygame module, so you can use it
import pickle, pygame, time
from pygame.locals import *
from random import random, randint
import numpy as np
import time

# Creating some colors
BLUE = (0, 0, 255)
GRAYBLUE = (50, 120, 120)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

# define directions
UP = 0
DOWN = 2
LEFT = 1
RIGHT = 3

# define indexes variations
v = [[-1, 0], [1, 0], [0, 1], [0, -1]]


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

    def __str__(self):
        string = ""
        for i in range(self.n):
            for j in range(self.m):
                string = string + str(int(self.surface[i][j]))
            string = string + "\n"
        return string

    def saveMap(self, numFile="test.map"):
        with open(numFile, 'wb') as f:
            pickle.dump(self, f)
            f.close()

    def loadMap(self, numfile):
        with open(numfile, "rb") as f:
            dummy = pickle.load(f)
            self.n = dummy.n
            self.m = dummy.m
            self.surface = dummy.surface
            f.close()

    def markVisited(self,x,y):
        if(self.surface[x][y] != -1 and self.surface[x][y] != 10):
            self.surface[x][y]=2

    def markSearched(self,x,y):
        if (self.surface[x][y] != -1 and self.surface[x][y] != 10):
            self.surface[x][y] = 5

    def colorSearched(self,visitedArray):
        while(len(visitedArray)>0):
            position = visitedArray.pop()
            (posX,posY)=position.position
            self.markSearched(posX,posY)



    def markStart(self,x,y):
        self.surface[x][y]=-1

    def markEnd(self,x,y):
        self.surface[x][y] = 10

    def image(self, colour=BLUE, background=WHITE):
        imagine = pygame.Surface((400, 400))
        brick = pygame.Surface((20, 20))
        brick.fill(BLUE)
        brickStart = pygame.Surface((20, 20))
        brickStart.fill(BLACK)
        visited = pygame.Surface((20, 20))
        visited.fill(GREEN)
        finish = pygame.Surface((20, 20))
        finish.fill(GRAYBLUE)
        searched = pygame.Surface((20, 20))
        searched.fill(RED)
        imagine.fill(WHITE)
        for i in range(self.n):
            for j in range(self.m):
                if (self.surface[i][j] == 1):
                    imagine.blit(brick, (j * 20, i * 20))
                if (self.surface[i][j] == -1):
                    imagine.blit(brickStart, (j * 20, i * 20))
                if (self.surface[i][j] == 2):
                    imagine.blit(visited, (j * 20, i * 20))
                if (self.surface[i][j] == 10):
                    imagine.blit(finish, (j * 20, i * 20))
                if(self.surface[i][j]==5):
                    imagine.blit(searched,(j * 20, i * 20))

        return imagine


class Node:
    def __init__(self, position:(), parent:()):
        self.position = position
        self.parent = parent
        self.g = 0 # Distance from start node
        self.h = 0 # Distance to goal node
        self.f = 0 # Total cost

    def __eq__(self, other):
        return self.position == other.position

    def __lt__(self, other):
         return self.f < other.f



class Drone():
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def moveKeys(self, detectedMap):
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


    def move(self,detectedMap,nextMove):
        if self.x > 0:
            if nextMove==UP and detectedMap.surface[self.x - 1][self.y] == 0:
                self.x = self.x - 1
        if self.x < 19:
            if nextMove==DOWN and detectedMap.surface[self.x + 1][self.y] == 0:
                self.x = self.x + 1

        if self.y > 0:
            if nextMove==LEFT and detectedMap.surface[self.x][self.y - 1] == 0:
                self.y = self.y - 1
        if self.y < 19:
            if nextMove==RIGHT and detectedMap.surface[self.x][self.y + 1] == 0:
                self.y = self.y + 1


    def moveByArray(self,inputPosArray,map):
        nextPos = inputPosArray.pop()

        map.markVisited(self.x,self.y)

        (nextX,nextY) = nextPos

        self.x = nextX
        self.y = nextY




    def mapWithDrone(self, mapImage):
        drona = pygame.image.load("drona.png")
        mapImage.blit(drona, (self.y * 20, self.x * 20))

        return mapImage

