import unittest

'''
1.Write a Client class
    -Constructor takes id,name and age parameters
    -id, name and age are properties(id is read only)
    -name at least 3 characters, age >18
    -raise ValueError in case of bad params

2.Write Client unit test

3.Write a UI and a Service
    UI -> Service -> Domain
    UI
        -handle the untire UI of the progra,
    Service
        -program functions using parameters/return/exceptions
    Repository
        -manage the list of domain entities
    Domain
        -domain entities

To run the program (V1):
    Domain: Client
    Repo: ClientRepository
    Service: ClientService
    +UI class

'''



class Client:
    def __init__(self,id,age,name):
        if id==None:
            raise ValueError("Client ID cannot be None!")
        self.id=id
        self.age=age
        self.name=name

    @property
    def id(self):
        return self.id

    @property
    def name(self):
        return self.name

    @name.setter
    def name(self,value):
        if value == None or len(value)<3:
            raise ValueError("Name is not good")
        else:
            pass

    @property
    def age(self):
        return self.age


    @age.setter
    def age(self,value):
        if value <18:
            raise ValueError("Client is too young")
        else:
            pass  







class TestClient(unittest.TestCase):
    def test_client(self):
        c = Client(1,"Pop Maria",20)
        assert c.id == 1
        assert c.name == "Pop Maria"
        assert c.age == 20

    def test_client_again(self):
        c = Client(1,"Pop Maria",20)
        try:
            c.age=15
            assert False
        except ValueError:
            assert True


        try:
            c.age == 15
            assert False
        except ValueError:
            assert True
        except Exception:
            assert False



'''
    How can we improve writing and running tests?
    What is wrong with them?
        -We need to remember to call them
        -Testing is terminated at first error
        -How many tests were run?
        -Testing report at end?
    => To do all that we use unittest.TestCases
    -> Better used in PyCharm, Eclipse        
'''
