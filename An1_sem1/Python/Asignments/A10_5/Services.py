class Game:
    def __init__(self,boardPlayer,boardAI,algorithm,planeNr):
        self._boardPlayer=boardPlayer
        self._boardAI=boardAI
        self._algorithm=algorithm
        self._player=1
        self._board=self._boardPlayer
        self._planeNr=planeNr
    
    def playerMove(self,x,y):
        self._boardAI.move(x,y)

    def boardSize(self):
        return self._board.getSize()

    def hitStatus(self,x,y):
        return self._board.getHitStatus(x,y)

    def computerMove(self):
        nextMove=self._algorithm.nextMove(self._boardPlayer)
        self._boardPlayer.move(nextMove[0],nextMove[1])

    def player_board(self):
        return self._boardPlayer.printBoard()

    def hit_board(self):
        return self._boardAI.printBoardHit()

    def AI_board(self):
        return self._boardAI.printBoard()

    def gameWon(self):
        if self._boardPlayer.getHeadCount()==self._planeNr:
            return "Computer Won!"
        elif self._boardAI.getHeadCount()==self._planeNr:
            return "Player Won!"
        return None


    def playerPlace(self):
        k=self._planeNr
        dict={"N":2,"E":3,"S":4,"W":5}
        while k>0:
            print(self.player_board())
            command=input("Enter row, column,direction: ")
            cmd=command.split()
            if self._boardPlayer.placePlane(int(cmd[0])-1,int(cmd[1])-1,dict[cmd[2]])==1:
                k -= 1