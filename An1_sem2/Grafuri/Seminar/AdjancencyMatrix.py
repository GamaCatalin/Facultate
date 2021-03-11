import random
from itertools import islice
import time
import datetime

class Graph:

    def __init__(self,verticesNr):
        self._verticesNr=verticesNr
        self._edgesNr=0

        self._graphMatrix=[[0 for i in range(0,self._verticesNr)] for j in range(0,self._verticesNr)]

    def verticesNr(self,verticesNr):
        self._verticesNr=verticesNr

    def edgesNr(self,edgesNr):
        self._edgesNr=edgesNr    

    def getVerticesNr(self):
        return self._verticesNr

    def getEdgesNr(self):
        return self._edgesNr

    def checkEdge(self,x,y):
        if self._graphMatrix[x][y]==1:
            return True
        return False

    def checkVertex(self, x):
        try:
            if type(self._graphOut[x])==type([]):
                return True
        except:
            return False

    def addEdge(self,x,y):
        self._graphMatrix[x][y]=1
        self._graphMatrix[y][x]=1
        self._edgesNr += 1


def createRandom(graph,verticesNr):

    edgesNr=10*verticesNr
    for i in range(0,edgesNr-1):
        while True:
            startingVertex=random.randint(0,verticesNr)
            endingVertex=random.randint(0,verticesNr)
            if (graph.checkEdge(startingVertex,endingVertex)==False):
                graph.addEdge(startingVertex,endingVertex)
                break




def start():
    verticesNr=int(input("Enter the number of vertices: "))

    g=Graph(verticesNr+1)

    start=time.time()
    createRandom(g,verticesNr)
    end=time.time()

    total_time=end-start

    timeOperation=str(datetime.timedelta(seconds=total_time))

    print("It took {0} to generate a graph with {1} vertices.".format(timeOperation,verticesNr))

start()