import os
import random
import sys
import time
import datetime
from itertools import islice

class Graph():
    def __init__(self):

        self._verticesNr=0
        self._edgesNr=0

        self._graphIn={}
        self._graphOut={}
        self._graphCost={}
        self._edgeID=[]
        self._edgeCost=[]


    def getVerticesNr(self):
        '''

        Gets the number of vertices

        '''
        return self._verticesNr

    def getVertices(self):

        '''

        Gets the vertices

        '''

        return self._graphOut.keys()

    def getEdgesNr(self):

        '''

        Gets the number of edges

        '''
        return self._edgesNr

    def checkEdge(self,x,y):

        '''

        Checks if a given edge is valid

        '''


        for i in self._graphOut[x]:
            if i==y:
                return True
        return False
    
    def checkEdgeID(self,n):

        '''

        Checks if the given edge ID is valid

        '''


        try:
            if type(self._edgeID[n])==type([]):
                pass
        except:
            return False
        return True

    def getEdgeID(self,x,y):

        '''

        Gets the edge ID of the given edge

        '''


        for i in range (0,len(self._edgeID)):
            if self._edgeID[i][0]==x and self._edgeID[i][1]==y:
                return i
        return 0

    def getEndpoints(self,x):
        List=[]
        List.append(self._edgeID[x][0])
        List.append(self._edgeID[x][1])
        return List

    def checkVertex(self, x):

        '''

        Checks if a given vertex is valid

        '''


        try:
            if type(self._graphOut[x])==type([]):
                return True
        except:
            return False

    def addVertex(self,x):

        '''

        Adds a vertex

        '''

        self._graphOut[x]=[]
        self._graphIn[x]=[]
        self._verticesNr += 1

    def removeVertex(self,x):

        '''

        Removes a vertex and it's coresponding edges

        '''




        for i in range(0,len(self._graphIn)):
            for j in range(0, len(self._graphIn[i])):
                if self._graphIn[i][j]==x:
                    i.pop(j)

        for i in range(0, len(self._edgeID)):
            if self._edgeID[0]==x or self._edgeID[1]==x:
                self._edgeID.pop(i)
                self._edgeCost.pop(i)
        self._verticesNr -= 1


        del self._graphOut[next(islice(self._graphOut,1,None))]
        del self._graphIn[next(islice(self._graphIn,1,None))]


    def getInDegree(self,x):
        '''

        Gets the in degree of a vertex

        '''

        return len(self._graphIn[x])

    def getOutDegree(self,x):
        '''

        Gets the out degree of a vertex

        '''

        return len(self._graphOut[x])

    def addEdge(self,x,y,cost):

        '''

        Adds an edge between 2 vertices 

        '''


        temp=[]
        temp.append(x)
        temp.append(y)
        self._edgeID.append(temp)
        self._edgeCost.append(cost)

        self._graphOut[x].append(y)
        self._graphIn[y].append(x)

        self._edgesNr += 1

    def removeEdge(self,n):

        '''

        Removes an edge given it's ID

        '''


        x=self._edgeID[0]
        y=self._edgeID[1]

        self._edgeID.pop(n)
        self._edgeCost.pop(n)

        for i in range(0, self._graphOut[x]):
            if self._graphOut[x][i]==y:
                self._graphOut[x].pop(i)

        for i in range(0, self._graphIn[y]):
            if self._graphOut[y][i]==x:
                self._graphOut[y].pop(i)
        self._edgesNr -= 1
    

    def getID(self,x,y):

        '''

        Gets the ID of an edge

        '''


        for i in range(0,self._edgesNr):
            if self._edgeID[i][0]==x and self._edgeID[i][1]==y:
                return i

    def printGraph(self):
        strPrint=""
        for i in range(0,self._edgesNr):
            strPrint=strPrint+str(self._edgeID[i][0])+" "
            strPrint=strPrint+str(self._edgeID[i][1])+" "
            strPrint=strPrint+str(self._edgeCost[i])+"\n"

        return strPrint

    def parseOut(self,x):

        '''

        Parses the outbound edges of the given vertex

        '''


        List=[]
        for i in self._graphOut[x]:
            List.append(i)
        return List
    
    def parseIn(self,x):

        '''

        Parses the inbound edges of the given vertex

        '''


        List=[]
        for i in self._graphIn[x]:
            List.append(i)
        return List

    def parseNeighbours(self,x):
        '''
        Parses the neighbours of the given vertex
        '''

        neighbours={}
        for i in self._graphOut[x]:
            neighbours[i]=0
        for i in self._graphIn[x]:
            neighbours[i]=0

        List=[]

        for i in neighbours.keys():
            List.append(i)

        return List            


    def parseVertices(self):
        '''

        Parses the vertices

        '''

        List=[]

        for i in self._graphIn.keys():
            List.append(i)

        return List

    def getCost(self,x):

        '''

        Gets the cost of a given edge

        '''


        return self._edgeCost[x]

    def changeCost(self,x,cost):

        '''

        Changes the cost of a given edge

        '''

        self._edgeCost[x]=cost

    def readGraph(self):
        '''

        Reads the graph from the input.txt file

        '''

        f=open("input.txt","r")
        temp=f.readline()
        input1=temp.split()
        self._verticesNr=int(input1[0])
        self._edgesNr=int(input1[1])

        self._graphIn={}
        self._graphOut={}
        self._graphCost={}
        self._edgeID=[]
        self._edgeCost=[]


        for i in range(0,self._verticesNr):
            self._graphIn[i]=[]
            self._graphOut[i]=[]

        

        for i in f:
            line=i.split()

            x=int(line[0])
            y=int(line[1])
            cost=int(line[2])
            
            self._graphOut[x].append(y)
            self._graphIn[y].append(x)


            tmp=[]
            tmp.append(x)
            tmp.append(y)

            self._edgeID.append(tmp)
            self._edgeCost.append(cost)

        f.close()



    def writeGraph(self):
        '''

        Writes the graph to an output file

        '''
        if os.path.exists("graphOut.txt"):
            os.remove("graphOut.txt")

        file=open("graphOut.txt","a")


        strPrint=str(self._verticesNr)+" "+str(self._edgesNr)+"\n"
        for i in range(0,self._edgesNr):
            strPrint=strPrint+str(self._edgeID[i][0])+" "
            strPrint=strPrint+str(self._edgeID[i][1])+" "
            strPrint=strPrint+str(self._edgeCost[i])+"\n"

        file.write(strPrint)
        file.close()

    def generateRandom(self,verticesNr,edgesNr):
        '''

        Generates a random graph given the vertices and edges number

        '''
        self._graphIn.clear()
        self._graphOut.clear()
        self._graphCost.clear()
        self._edgeID=[]
        self._edgeCost=[]

        self._verticesNr=verticesNr
        self._edgesNr=0

        for i in range(0,self._verticesNr+1):
            self._graphIn[i]=[]
            self._graphOut[i]=[]

        for i in range(0,edgesNr):
            while True:
                startingVertex=random.randint(0,self._verticesNr)
                endingVertex=random.randint(0,self._verticesNr)
                cost=random.randint(0,self._verticesNr)
                if (self.checkEdge(startingVertex,endingVertex)==False):
                    self.addEdge(startingVertex,endingVertex,cost)
                    break

    def getPaths(self, a, b, visited, path,pathList): 
  
       
        visited[a]= True
        path.append(a) 
  
        if a == b: 
            pathList.append([])
            for i in range (0,len(path)):
                pathList[len(pathList)-1].append(path[i])
        else: 
            for i in self.parseOut(a): 
                if visited[i]==False: 
                    self.getPaths(i, b, visited, path,pathList) 
                      
        path.pop() 
        visited[a]= False
   
    def printMinPath(self,a, b): 
  
        visited =[False]*(self._verticesNr) 
  
        path = [] 
        pathList=[]
  
        self.getPaths(a, b,visited, path,pathList) 

        minLenght=9999
        pathIndex=0

        if (len(pathList)==0):
            print("Can't generate path from {} to {}".format(a,b))
        else:
            for i in range(0,len(pathList)):
                if len(pathList[i])<minLenght:
                    pathIndex=i
                    minLenght=len(pathList[i])
            print(pathList[pathIndex],end=" - ")
            print(minLenght-1)


    def breadthFirstSearch_minPath(self, a, b):
        
        visited = []
        queue = [[a]]
        
        while queue:
            path = queue.pop(0)
            node = path[-1]
            if node not in visited:
                children = self.parseOut(node)
                for child in children:
                    new_path = list(path)
                    new_path.append(child)
                    queue.append(new_path)
                    if child == b:
                        return "{} - {}".format(new_path,len(new_path)-1)
                visited.append(node)

        return "Can't generate path from {} to {}".format(a,b)
    

    def lowestCostWalkFord(self, a,b):

        start=time.time()

        distance, predecessor = dict(), dict()
        
        for node in range(0,self.getVerticesNr()):
            distance[node], predecessor[node] = float('inf'), None
        distance[a] = 0

        modified=True
        while modified:
            modified=False
            for node in range(0,self.getVerticesNr()):
                for neighbour in self.parseOut(node):
                    edge=self.getEdgeID(node,neighbour)
                    if distance[neighbour] > distance[node] + self.getCost(edge):
                        distance[neighbour], predecessor[neighbour] = distance[node] + self.getCost(edge), node
                        modified=True

        for node in range(0,self.getVerticesNr()):
            for neighbour in self.parseOut(node):
                edge=self.getEdgeID(node,neighbour)
                if distance[neighbour] > distance[node] + self.getCost(edge):
                    print ("Negative weight cycle.")
                    return

        tempWalk=[]
        walk=[]
        t=b

        if(distance[b]==float("inf")):
            print("Can't find a walk from {} to {}".format(a,b))
            return

        while(distance[t]!=0):
            tempWalk.append(t)
            t=predecessor[t]

        tempWalk.append(a)

        for i in range(len(tempWalk)-1,0,-1):
            walk.append(tempWalk[i])

        walk.append(b)

        print("Shortest walk: {}".format(walk))
        print("Distance: {}".format(distance[b]))

        end=time.time()

        total_time=end-start

        timeOperation=str(datetime.timedelta(seconds=total_time))

        print("Time: {}".format(timeOperation))

    def depthFirstSearch(self,vertex,visited,successors):
        visited[vertex]=1
       
        for i in self.parseOut(vertex):
            if(visited[i]==2):
                pass
            if(visited[i]==1):
                return False
            if(visited[i]==0):
                visited[i]=1
                if not self.depthFirstSearch(i,visited,successors):
                    return False
        
        visited[vertex]=2
        successors.append(vertex)
        return True

    def isCycle(self,vertex,visited,stack):
        visited[vertex]=True
        stack[vertex]=True

        for successor in self.parseOut(vertex):
            if(visited[successor]==False):
                if(self.isCycle(successor,visited,stack)==True):
                    return True
            elif (stack[successor]==True):
                return True 
        
        stack[vertex]=False
        return False

    def topologicalSortPredecesors(self):
        sorted=[]
        queue=[]
        count={}
        for i in self.parseVertices():
            count[i]=self.getInDegree(i)
            if count[i]==0:
                queue.append(i)

        while len(queue)>0:
            vertex=queue.pop()
            sorted.append(vertex)
            for x in self.parseOut(vertex):
                count[x] -= 1
                if count[x]==0:
                    queue.append(x)

        if(len(sorted)<self.getVerticesNr()):
            sorted=[]

        return sorted


    def topologicalSortDFS(self):
        visited = [0] * self.getVerticesNr()
        count={}
        for i in self.parseVertices():
            count[i]=0
        path = []

        for i in range(self.getVerticesNr()):
            if visited[i] == 0:
                if not self.depthFirstSearch(i,visited,path):
                    return []
        return path[::-1]
                

    def longestPath(self,a,b,topo):
        distance={} 

        for i in self.parseVertices():
            distance[i]=  -99999999
        distance[a]=0

        for vertex in topo:
            if(vertex==b):
                break
            for u in self.parseOut(vertex):
                edge=self.getEdgeID(vertex,u)
                if distance[u] < distance[vertex] + self.getCost(edge):
                    distance[u]=distance[vertex]+self.getCost(edge)

        return distance[b]
    

    def checkIfDAG(self,a,b):

        topological_sort=self.topologicalSortPredecesors()

        print(topological_sort)

        if(topological_sort==[]):
            print("Graph contains a cycle!")
            return


        highestCost= self.longestPath(a,b,topological_sort)


        print("The highest cost between {} and {} is: {}".format(a,b,highestCost))

        return True


    def coloring(self):
        '''
        Colors the graph with the least amount of colors
        ''' 

        colors={}
        for i in self.parseVertices():
            colors[i]=0
        
        highestColor=0
        #Go through each edge and change the second endpoint based on it's value in relation to it's neighbours
        for i in range (0,self.getEdgesNr()):
            
            endpoints=self.getEndpoints(i)
            x=endpoints[0]
            y=endpoints[1]


            #Checks if 2 neighbouring vertices have the same color
            if(colors[x]==colors[y]):

                #If the second vertex's color is not the highest value, it checks all it's neighbours for an available color
                if(colors[y]!=highestColor):
                    
                    changed=False
                    neighbourList=self.parseNeighbours(y)
                    for j in range(0,highestColor):
                        counter=0
                        for neighbour in neighbourList:
                            if(colors[neighbour]==j):
                                break
                            else:
                                counter+=1
                        if counter==len(neighbourList):
                            colors[y]=j
                            changed=True
                            break
                    
                    #If no available color less than the highest value can be found, then the highest value is given if no neighbour has the same color
                    if changed==False:
                        neighbourList=self.parseNeighbours(y)
                        counter=0
                        for neighbour in neighbourList:
                            if(colors[neighbour]==highestColor):
                                break
                            else:
                                counter+=1
                        if counter==len(neighbourList):
                            colors[y]=highestColor
                            changed=True
                        else:
                            highestColor+=1
                            colors[y]=highestColor
                            changed=True
               
                #If the second vertex has the highest color, it add another one higher and changes it
                else:
                    highestColor+=1
                    colors[y]=highestColor
           


        for i in self.parseVertices():
            print("Vertex {} has color {}".format(i,colors[i]))


graph=Graph()