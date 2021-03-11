import random
from itertools import islice
import time
import datetime

class Graph:

    def __init__(self):
        self._verticesNr=0
        self._edgesNr=0

        self._graphOut={}

    def verticesNr(self,verticesNr):
        self._verticesNr=verticesNr

    def edgesNr(self,edgesNr):
        self._edgesNr=edgesNr    

    def getVerticesNr(self):
        return self._verticesNr

    def getVertices(self):
        return self._graphOut.keys()

    def getEdgesNr(self):
        return self._edgesNr

    def checkEdge(self,x,y):
        for i in self._graphOut[x]:
            if i==y:
                return True
        return False

    def checkVertex(self, x):
        try:
            if type(self._graphOut[x])==type([]):
                return True
        except:
            return False

    def addVertex(self,x):
        self._graphOut[x]=[]
        self._verticesNr += 1

    def addEdge(self,x,y):
        self._graphOut[x].append(y)

        self._edgesNr += 1

    def parseNOut(self,x):
        List=[]
        for i in self._graphOut[x]:
            List.append(i)
        return List
    


def createRandom(graph,verticesNr):

    edgesNr=10*verticesNr
    for i in range(0,edgesNr-1):
        while True:
            startingVertex=random.randint(0,verticesNr)
            endingVertex=random.randint(0,verticesNr)
            if (graph.checkEdge(startingVertex,endingVertex)==False):
                graph.addEdge(startingVertex,endingVertex)
                break





g=Graph()

def start():
    verticesNr=int(input("Enter the number of vertices: "))

    for i in range(0,verticesNr+1):
        g.addVertex(i)

    start=time.time()
    createRandom(g,verticesNr)
    end=time.time()

    total_time=end-start

    timeOperation=str(datetime.timedelta(seconds=total_time))

    print("It took {0} to generate a graph with {1} vertices.".format(timeOperation,verticesNr))

start()