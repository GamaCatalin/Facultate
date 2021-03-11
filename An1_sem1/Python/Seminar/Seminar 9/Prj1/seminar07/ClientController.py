from UndoController import *
from Client import Client
class ClientController:
    def __init__(self, validator, repository):
        self.__validator = validator
        self.__repository = repository

    def create(self, clientId, clientCNP, clientName):
        client = Client(clientId, clientCNP, clientName)
        self.__validator.validate(client)
        self.__repository.store(client)
        return client

    def delete(self, clientId):
        '''
        1.Delete client
        '''
        client = self.__repository.delete(clientId)
        
        undo=FunctionCall(self.create, clientId,client.cnp, client.name)
        redo=FunctionCall(self.delete, clientId)
        op = Operation(undo, redo)
        self._undoController.recordOperation(op)

        '''
        2.Delete client rentals
        '''


    def update(self, client):
        self.__repository.update(client)
       
    def getClientCount(self):
        return len(self.__repository)
        
    
        
            
        
