'''
class Field
2 matrices
    1. data model(mine location, mine adjacency)
    2. data revealed ti the user



1.create the board class
    -lay mines
    -which fields are revealed
    -count adjacent mines
    -reveal a field

2.create the game class
'''
from texttable import Texttable
import random


class Field:
    def __init__(self):
        self._isMine=0
        self.Revealed=False
        self._proxy=0

    def __str__(self):
        if self.Revealed==False:
            return '?'
        if self.Proximity==0:
            return " "
        return str(self._proxy)

    @property
    def Mine(self):
        return self._isMine
    @Mine.setter
    def Mine(self,value):
        self._isMine = value
    @property
    def Proximity(self):
        return self._proxy
    @Proximity.setter
    def Proximity(self,value):
        self._proxy = value
    @property
    def Revealed(self):
        return self._revealed

    @Revealed.setter
    def Revealed(self,val):
        self._revealed = val


class SteppedOnMineException(Exception):
    pass



class Board:
    def __init__(self,width,height,mines):
        self._w = width
        self._h = height
        self._m = mines

        self._data=[]
        for i in range(self._h):
            line= []
            for j in range(self._w):
                line.append(Field())
            self._data.append(line)
        self._layMines()


    def step(self,x,y):
        if x<0 or y<0 or x>self._h or y>self._w:
            raise ValueError("Must walk in minefield!")

        field=self._data[x][y]

        if field.Mine == True:
            raise SteppedOnMineException()
        #Not on a mine, but close by
        if field.Proximity != 0:
            field.Revealed=True
            return 
        #No mines in sight
        d=self._data
        stack=[]
        stack.append((x,y))
        
        while len(stack)>0:
            c = stack.pop()
            for nCoord in self._neighbours(c[0],c[1]):
                field = d[nCoord[0]][nCoord[1]]
                if field.Revealed == True:
                    continue
                if field.Proximity==0:
                    stack.append(nCoord)
                field.Revealed==True


    def _layMines(self):

        indice = range(0,self._w * self._h)
        indices=random.sample(indice,self._m)
        indices=[2,6,7,8]
        #print(indices)

        for i in indices:
            x=i//self._w
            y=i%self._w
            self._data[x][y].Mine = True

            for c in self._neighbours(x,y):
                if self._data[c[0]][c[1]].Mine==False:
                    self._data[c[0]][c[1]].Proximity += 1


    def _neighbours(self,x,y):
        '''
        return neighbour coordinates of (x,y)

        '''

        res = [(x-1,y-1),(x-1,y),(x-1,y+1),(x,y-1),(x,y+1),(x+1,y-1),(x+1,y),(x+1,y+1)]
        poz=0

        while poz < len(res):
            c = res[poz]
            if c[0]<0 or c[1]<0 or c[0]>=self._h or c[1]>=self._w:
                res.remove(c)
            else:
                poz += 1




        return res


    def __str__(self):
        t = Texttable()
        for i in range(self._h):
            t.add_row(self._data[i])
        return t.draw()


b = Board(6,4,1)
b.step(3,4)

print(b)
#print(b._neighbours(3,5))