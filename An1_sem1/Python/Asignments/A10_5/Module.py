from texttable import Texttable
from AI import RandAIPopulate

class Board:
    def __init__(self,size):
        # 0 - empty box
        # 1 - plane part
        # 2 - plane head
        self._size=size
        self._data=[]
        self._hit=[]
        self._headCount=0
        for i in range (0,self._size):
            self._data.append([0]*self._size)
            self._hit.append([0]*self._size)

    def checkSpotAI(self,x,y,direction):
        print(str(x)+" "+str(y)+" "+str(direction))
        if direction==2:
            if self._data[x][y]!=0 or self._data[x-1][y]!=0 or self._data[x-1][y-1]!=0 or self._data[x-1][y-2]!=0 or self._data[x-1][y+1]!=0 or self._data[x-1][y+2]!=0 or self._data[x-2][y]!=0 or self._data[x-3][y]!=0 or self._data[x-3][y-1]!=0 or self._data[x-3][y+1]!=0:
                return 1
        elif direction==3:
            if self._data[x][y]!=0 or self._data[x][y+1]!=0 or self._data[x-1][y+1]!=0 or self._data[x-2][y+1]!=0 or self._data[x+1][y+1]!=0 or self._data[x+2][y+1]!=0 or self._data[x][y+2]!=0 or self._data[x][y+3]!=0 or self._data[x-1][y+3]!=0 or self._data[x+1][y+3]!=0:
                return 1
        elif direction==4:
            if self._data[x][y]!=0 or self._data[x+1][y]!=0 or self._data[x+1][y-1]!=0 or self._data[x+1][y-2]!=0 or self._data[x+1][y+1]!=0 or self._data[x+1][y+2]!=0 or self._data[x+2][y]!=0 or self._data[x+3][y]!=0 or self._data[x+3][y+1]!=0 or self._data[x+3][y-1]!=0:
                return 1
        elif direction==5:
            if self._data[x][y]!=0 or self._data[x][y-1]!=0 or self._data[x-1][y-1]!=0 or self._data[x-2][y-1]!=0 or self._data[x+1][y-1]!=0 or self._data[x+2][y-1]!=0 or self._data[x][y-2]!=0 or self._data[x][y-3]!=0 or self._data[x-1][y-3]!=0 or self._data[x+1][y-3]!=0:
                return 1

    
    def getStatus(self,x,y):
        return self._data[x][y]

    def getSize(self):
        return self._size

    def getHitStatus(self,x,y):
        return self._hit[x][y]
    
    def getHeadCount(self):
        return self._headCount

    def printBoard(self):
        t = Texttable()
        dict={0:" ",1:"■",2:"v",3:"<",4:"^",5:">",-1:"X"}
        for i in range(self._size):
            row = self._data[i][:]
            for j in range (self._size):
                row[j]=dict[row[j]]
            t.add_row(row)
        return (t.draw())

    def printBoardHit(self):
        t = Texttable()
        dict={0:" ",-1:"X",1:"O"}
        for i in range(self._size):
            row = self._hit[i][:]
            for j in range (self._size):
                row[j]=dict[row[j]]
            t.add_row(row)
        return (t.draw())


    def checkSpot(self,x,y,direction):
        if x<0 or x>self._size-1 or y<0 or y>self._size-1:
            return 1
        if direction==2:
            if y<3 or y>self._size-1 or x<3 or x>self._size-1 or self._data[x][y]!=0 or self._data[x-1][y]!=0 or self._data[x-1][y-1]!=0 or self._data[x-1][y-2]!=0 or self._data[x-1][y+1]!=0 or self._data[x-1][y+2]!=0 or self._data[x-2][y]!=0 or self._data[x-3][y]!=0 or self._data[x-3][y-1]!=0 or self._data[x-3][y+1]!=0:
                return 1
        elif direction==3:
            if x<2 or x>self._size-3 or y>self._size-3 or y<2 or self._data[x][y]!=0 or self._data[x][y+1]!=0 or self._data[x-1][y+1]!=0 or self._data[x-2][y+1]!=0 or self._data[x+1][y+1]!=0 or self._data[x+2][y+1]!=0 or self._data[x][y+2]!=0 or self._data[x][y+3]!=0 or self._data[x-1][y+3]!=0 or self._data[x+1][y+3]!=0:
                return 1
        elif direction==4:
            if x>self._size-3 or y<2 or y>self._size-3 or x<0 or self._data[x][y]!=0 or self._data[x+1][y]!=0 or self._data[x+1][y-1]!=0 or self._data[x+1][y-2]!=0 or self._data[x+1][y+1]!=0 or self._data[x+1][y+2]!=0 or self._data[x+2][y]!=0 or self._data[x+3][y]!=0 or self._data[x+3][y+1]!=0 or self._data[x+3][y-1]!=0:
                return 1
        elif direction==5:
            if x<2 or x>self._size-3 or y <3 or y>self._size-1 or self._data[x][y]!=0 or self._data[x][y-1]!=0 or self._data[x-1][y-1]!=0 or self._data[x-2][y-1]!=0 or self._data[x+1][y-1]!=0 or self._data[x+2][y-1]!=0 or self._data[x][y-2]!=0 or self._data[x][y-3]!=0 or self._data[x-1][y-3]!=0 or self._data[x+1][y-3]!=0:
                return 1

    def placePlane(self,x,y,direction):
        if self.checkSpot(x,y,direction)==1:
            print("Can't place plane there!")
            return 0

        self._data[x][y]=direction
        if direction==2:
            self._data[x-1][y]=1
            self._data[x-1][y-1]=1
            self._data[x-1][y-2]=1
            self._data[x-1][y+1]=1
            self._data[x-1][y+2]=1
            self._data[x-2][y]=1
            self._data[x-3][y]=1
            self._data[x-3][y-1]=1
            self._data[x-3][y+1]=1

        elif direction==3:
            self._data[x][y+1]=1
            self._data[x-1][y+1]=1
            self._data[x-2][y+1]=1
            self._data[x+1][y+1]=1
            self._data[x+2][y+1]=1
            self._data[x][y+2]=1
            self._data[x][y+3]=1
            self._data[x-1][y+3]=1
            self._data[x+1][y+3]=1

        elif direction==4:
            self._data[x+1][y]=1
            self._data[x+1][y+1]=1
            self._data[x+1][y+2]=1
            self._data[x+1][y-1]=1
            self._data[x+1][y-2]=1
            self._data[x+2][y]=1
            self._data[x+3][y-1]=1
            self._data[x+3][y+1]=1
            self._data[x+3][y]=1

        elif direction==5:
            self._data[x][y-1]=1
            self._data[x-1][y-1]=1
            self._data[x-2][y-1]=1
            self._data[x+1][y-1]=1
            self._data[x+2][y-1]=1
            self._data[x][y-2]=1
            self._data[x-1][y-3]=1
            self._data[x+1][y-3]=1
            self._data[x][y-3]=1
        return 1

    def placePlaneAI(self,x,y,direction):
        if self.checkSpot(x,y,direction)==1:
            return 0

        self._data[x][y]=direction
        if direction==2:
            self._data[x-1][y]=1
            self._data[x-1][y-1]=1
            self._data[x-1][y-2]=1
            self._data[x-1][y+1]=1
            self._data[x-1][y+2]=1
            self._data[x-2][y]=1
            self._data[x-3][y]=1
            self._data[x-3][y-1]=1
            self._data[x-3][y+1]=1

        elif direction==3:
            self._data[x][y+1]=1
            self._data[x-1][y+1]=1
            self._data[x-2][y+1]=1
            self._data[x+1][y+1]=1
            self._data[x+2][y+1]=1
            self._data[x][y+2]=1
            self._data[x][y+3]=1
            self._data[x-1][y+3]=1
            self._data[x+1][y+3]=1

        elif direction==4:
            self._data[x+1][y]=1
            self._data[x+1][y+1]=1
            self._data[x+1][y+2]=1
            self._data[x+1][y-1]=1
            self._data[x+1][y-2]=1
            self._data[x+2][y]=1
            self._data[x+3][y-1]=1
            self._data[x+3][y+1]=1
            self._data[x+3][y]=1

        elif direction==5:
            self._data[x][y-1]=1
            self._data[x-1][y-1]=1
            self._data[x-2][y-1]=1
            self._data[x+1][y-1]=1
            self._data[x+2][y-1]=1
            self._data[x][y-2]=1
            self._data[x-1][y-3]=1
            self._data[x+1][y-3]=1
            self._data[x][y-3]=1
        return 1

    def move(self,x,y):
        if x > self._size or x  < 0 or y > self._size or y < 0:
            raise ValueError("Move not on board!")
        if self._data[x][y]==-1:
            raise ValueError("Zone already hit!")
        if self.getHitStatus(x,y)==0:
            if self._data[x][y]>=2:
                #hit plane head
                self.hitHead(x,y,self._data[x][y])
                self._data[x][y]=-1
                self._hit[x][y]=-1
                self._headCount+=1
                print("Head hit!")
            elif self._data[x][y]==1:
                self._data[x][y]=-1
                self._hit[x][y]=-1
                print("Body hit!")
            else:
                print("You miss!")
                self._hit[x][y]=1
        else:
            print("Zone already hit!")

    
    def hitHead(self,x,y,direction):
        if direction==2:
            self._data[x-1][y]=-1
            self._data[x-1][y-1]=-1
            self._data[x-1][y-2]=-1
            self._data[x-1][y+1]=-1
            self._data[x-1][y+2]=-1
            self._data[x-2][y]=-1
            self._data[x-3][y]=-1
            self._data[x-3][y-1]=-1
            self._data[x-3][y+1]=-1
            
            self._hit[x-1][y]=-1
            self._hit[x-1][y-1]=-1
            self._hit[x-1][y-2]=-1
            self._hit[x-1][y+1]=-1
            self._hit[x-1][y+2]=-1
            self._hit[x-2][y]=-1
            self._hit[x-3][y]=-1
            self._hit[x-3][y-1]=-1
            self._hit[x-3][y+1]=-1

        elif direction==3:
            self._data[x][y+1]=-1
            self._data[x-1][y+1]=-1
            self._data[x-2][y+1]=-1
            self._data[x+1][y+1]=-1
            self._data[x+2][y+1]=-1
            self._data[x][y+2]=-1
            self._data[x][y+3]=-1
            self._data[x-1][y+3]=-1
            self._data[x+1][y+3]=-1

            self._hit[x][y+1]=-1
            self._hit[x-1][y+1]=-1
            self._hit[x-2][y+1]=-1
            self._hit[x+1][y+1]=-1
            self._hit[x+2][y+1]=-1
            self._hit[x][y+2]=-1
            self._hit[x][y+3]=-1
            self._hit[x-1][y+3]=-1
            self._hit[x+1][y+3]=-1

        elif direction==4:
            self._data[x+1][y]=-1
            self._data[x+1][y+1]=-1
            self._data[x+1][y+2]=-1
            self._data[x+1][y-1]=-1
            self._data[x+1][y-2]=-1
            self._data[x+2][y]=-1
            self._data[x+3][y-1]=-1
            self._data[x+3][y+1]=-1
            self._data[x+3][y]=-1

            self._hit[x+1][y]=-1
            self._hit[x+1][y+1]=-1
            self._hit[x+1][y+2]=-1
            self._hit[x+1][y-1]=-1
            self._hit[x+1][y-2]=-1
            self._hit[x+2][y]=-1
            self._hit[x+3][y-1]=-1
            self._hit[x+3][y+1]=-1
            self._hit[x+3][y]=-1

        elif direction==5:
            self._data[x][y-1]=-1
            self._data[x-1][y-1]=-1
            self._data[x-2][y-1]=-1
            self._data[x+1][y-1]=-1
            self._data[x+2][y-1]=-1
            self._data[x][y-2]=-1
            self._data[x-1][y-3]=-1
            self._data[x+1][y-3]=-1
            self._data[x][y-3]=-1

            self._hit[x][y-1]=-1
            self._hit[x-1][y-1]=-1
            self._hit[x-2][y-1]=-1
            self._hit[x+1][y-1]=-1
            self._hit[x+2][y-1]=-1
            self._hit[x][y-2]=-1
            self._hit[x-1][y-3]=-1
            self._hit[x+1][y-3]=-1
            self._hit[x][y-3]=-1
