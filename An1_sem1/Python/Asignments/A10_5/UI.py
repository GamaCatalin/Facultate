from Module import Board
from Services import Game
from AI import RandomAI
from AI import RandAIPopulate



class UI:
    def __init__(self,game):
        self._loop=True
        self._game=game
    
    def printBoard(self):
        print (self._game.player_board())

    def printHitBoard(self):
        print (self._game.hit_board())

    def printAIBoard(self):
        print (self._game.AI_board())
    
    def start(self):
        playerTurn=True
        self._game.playerPlace()
        self.printBoard()
        while self._loop==True :
            try:
                if game.gameWon()!=None:
                    print(game.gameWon())
                    self._loop=False
                    break
                if playerTurn==True:
                    self.printHitBoard()
                    while True:
                        command=input("Enter hit location: ")
                        cmd=command.split()
                        if len(cmd)==2:
                            if int(cmd[0])>=1 and int(cmd[0])<=self._game.boardSize() and int(cmd[1])>=1 and int(cmd[0])<=self._game.boardSize():
                                if self._game.hitStatus(int(cmd[0])-1,int(cmd[1])-1)==0:
                                    break
                                else:
                                    print("Zone already hit!")
                            else:
                                print("Move not on board!")
                        else:
                            print("Invalid input!")
                    self._game.playerMove(int(cmd[0])-1,int(cmd[1])-1)
                    self.printBoard()
                    
                else:
                    self._game.computerMove()
                playerTurn = not playerTurn
            except (ValueError,IndexError):
                continue

while True:
    command=input("Enter board size and plane nr: ")
    cmd=command.split()
    if len(cmd)==2:
        if int(cmd[0])>5:
            if int(cmd[1])*2<int(cmd[0]):
                break
            else:
                print("Too many planes!")
        else:
            print("Board too small!")
    else:
        print("Invalid input!")


boardPlayer=Board(int(cmd[0]))
boardAI=Board(int(cmd[0]))

algorithm=RandomAI(int(cmd[0]))

pop=RandAIPopulate(boardAI,int(cmd[1]))

game=Game(boardPlayer,boardAI,algorithm,int(cmd[1]))

ui=UI(game)

ui.start()