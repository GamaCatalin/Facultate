'''
TicTacToe

Player vs. Computer (player majes first move)
        -validate everything
Computer
    -Lvl 1: random but valid moves
    -Lvl 2: take 1-move win opportunities
    -Lvl 3: prevent player 1-move wins
    -Lvl 4: minmax

'''
from texttable import Texttable

'''
Domain
'''


class GameWonException(Exception):
    pass

class GameDrawException(Exception):
    pass



class Board:
    def __init__(self):
        # 0 - empty square
        # 1 - X
        # -1 - O   
        # self._data = [0] * 9
        self._data=[[0] * 3, [0] * 3, [0] * 3]
        self._moves = 0

    # information expert

    def get(self,x,y):
        #obs: exposes the internal state of the board
        return self._data[x][y]



    def _IsWon(self):
        #rows
        for i in range(3):
            if abs(sum(self._data[i])) == 3:
                return True
        #columns
        d = self._data
        for i in range(3):
            if abs(d[0][i] + d[1][i] + d[2][i]) == 3:
                return True
        #diagonal rows
        if abs(d[0][0]+d[1][1]+d[2][2]) == 3:
            return True
        if abs(d[0][2]+d[1][1]+d[2][0]) == 3:
            return True
        return False

    def _IsTied(self):
        return self._IsWon() == False and self._moves == 9



    def move(self,x,y,symbol):
        #ensure x,y in board
        if x not in [0,1,2] or y not in [0,1,2]:
            raise ValueError("Move outside board!")
        # check that we do not overwrite moves
        if self._data[x][y] != 0:
            raise ValueError("Invalid square for move!")
        if symbol not in ['X','O']:
            raise ValueError('Incorrect symbol!')

        d = {'X':1,'O':-1}
        self._data[x][y]=d[symbol]
        self._moves += 1

        if self._IsWon():
            raise GameWonException()
        if self._IsTied():
            raise GameDrawException()



        '''
        After each move, check for win or tie
        raise GameWonException
        raise GameDrawException
        '''



    def __str__(self):
        t = Texttable()
        d = {0:" ",1:"X",-1:"O"}
        for i in range(3):
            row = self._data[i][:]
            for j in range(3):
                row[j] = d[row[j]]
            t.add_row(row)
        return t.draw()



'''
Services
'''
class MoveAlgorithmLv1:
    # take the first unocupied square
    def nextMove(self, board):
        # return the computer's next move
        for i in range (3):
            for j in range(3):
                if board.get(i,j) == 0:
                    return (i,j)
        # this is bad, because the computer has to make a move on a full board
        raise ValueError("Computer cannot make a move!")

import random
class MoveAlgorithmLv2:
    # take the first unocupied square
    def nextMove(self, board):
        # return the computer's next move
        candidates = []
        for i in range (3):
            for j in range(3):
                if board.get(i,j) == 0:
                    candidates.append((i,j))
        # this is bad, because the computer has to make a move on a full board
        raise ValueError("Computer cannot make a move!")  


class Game:
    def __init__(self, board, algorithm):
        self._board = board
        self._algorithm = algorithm

    def playerMove(self,x,y):
        self._board.move(x,y,'X')

    def computerMove(self):
        square = self._algorithm.nextMove(self._board)
        self._board.move(square[0],square[1],'O')

    def getBoard(self):
        return self._board


'''
UI
'''
class UI:
    def __init__(self,game):
        self._game = game

    def _readPlayerMove(self):
        cmd = input(">").split(" ")
        return (int(cmd[0]), int(cmd[1]))
    
    def start(self):
        # program UI starts here
        b = self._game.getBoard()
        
        playerMove = True
        
        while True:
            # game on!

            print(b)
            try:
                if playerMove == True:
                    square = self._readPlayerMove()
                    self._game.playerMove(square[0],square[1])
                else:
                    self._game.computerMove()
                playerMove = not playerMove
            except GameWonException:
                if playerMove == True:
                    print("You won!")
                else:
                    print("You lose!")
                return
            except GameDrawException:
                print("Game is a draw!")
            except (ValueError, IndexError):
                # bad move, user!
                continue

# Example of dependency injection

b = Board()

# Strategy behavioural pattern

#ai = MoveAlgorithmLv1()
ai = MoveAlgorithmLv2()
g = Game(b,ai)
ui = UI(g)
ui.start()

