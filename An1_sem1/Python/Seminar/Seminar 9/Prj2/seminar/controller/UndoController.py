
#1. Keep a reference to a function and it's parameters
#We use the command design pattern

class UndoController:
    def __init__(self):
        # History of the program's undoable operation
        self._history = []
        # keep the position in the undo/redo list
        self._index = 0

        self._duringUndo = False

    def recordOperation(self, operation):
        '''
        recod an aperation in the history for undo/redo
        params:
            operation - the operation that was carried out
        '''
        if self._duringUndo == True:
            return
        
        self._history.append(operation)
        self._index += 1

    def undo(self):
        if self._index == 0:
            raise ValueError("No more undos!")
        self._duringUndo = True
        self._index = 1
        self._history[self._index].undo()
    def redo(self):
        if self._index == len(self._history):
            raise ValueError("No more redos!")
        self._index += 1
        self._history[self._index].redo()



class FunctionCall:
    def __init__(self,function,*parameters):
        self._function = function
        self._params = parameters

    def __call__(self):
        self.call()

    def call(self):
        self._function(*self._params)

    #f( (a,b,c) )  self._params
    #f(a,b,c)  *self._params


class Operation:
    '''
    Store the function reference and params for both undo and redo
    '''

    def __init__(self,undoFunction,redoFunction):
        self._undo=undoFunction
        self._redo=redoFunction
    def undo(self):
        self._undo() # self._undo.call()
    def redo(self):
        self._redo() # self._redo.call()



class CascadingOperation:
    def __init__(self,*operations):
        self._oper = *operations
    def undo(self):
        pass
    def redo(self):
        pass






def fun(a,b):
    print("a=",a," b=",b)


fun(5,6)
x=FunctionCall(fun,99,98)
x.call() # use the call method
x() # use __call__, overdriven call operator





'''

    1. Remember what we need to do for undo/redo
        (remember = what function to call and with what parameters)
    2. Remember the order in which the operations were made
        (remember = keep a list of program operations)

    3. Carry out the operations when user requests undo(), redo()

'''