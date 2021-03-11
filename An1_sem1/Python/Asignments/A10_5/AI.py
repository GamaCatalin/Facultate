#from Module import *
import random

class RandAIPopulate:
    def __init__(self,board,places):
        self._board=board
        self._places=places
        k=0

        while(self._places>0 and k<100):
            direction = random.randint(1,5)
            if direction==2:
                x=random.randint(3,self._board.getSize()-1)
                y=random.randint(2,self._board.getSize()-3)
                if self._board.placePlaneAI(x,y,direction)==1:
                    self._places += -1
            elif direction==3:
                x=random.randint(2,self._board.getSize()-3)
                y=random.randint(0,self._board.getSize()-4)
                if self._board.placePlaneAI(x,y,direction)==1:
                    self._places += -1
            elif direction==4:
                x=random.randint(0,self._board.getSize()-4)
                y=random.randint(1,self._board.getSize()-3)
                if self._board.placePlaneAI(x,y,direction)==1:
                    self._places += -1
            elif direction==5:
                x=random.randint(2,self._board.getSize()-3)
                y=random.randint(3,self._board.getSize()-1)
                if self._board.placePlaneAI(x,y,direction)==1:
                    self._places += -1
            else:
                k += 1

    
class RandomAI:
    def __init__(self,size):
        self._size=size

    def nextMove(self,board):
        move=[]
        while True:
            x=random.randint(0,self._size-1)
            y=random.randint(0,self._size-1)
            if board.getHitStatus(x,y)==0:
                move.append(x)
                move.append(y)
                return move