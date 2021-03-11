class ClientRepository:
    '''
    Manage the list of clients in the program

    Holds a private list of Client objects
    Functions to manage the list:
        -add a new client(raise exception if duplicate ID)
        -delete a client by ID
        -return the list of clients
        -find a client by ID

    '''
    def store(self,c):
        pass
    def find(self,x):
        pass
    def delete(self,x):
        pass    








import unittest
from Module import Client

class ClientRepoTest(unittest.TestCase):
    def test_repo(self):
        repo = ClientRepository()
        self.assertEqual(len(repo),0)

        repo.store((c:=Client(1,"Decebal Popescu",39)))
        self.assertEqual(len(repo),1)
        self.assertEqual(repo.find(1),c)

        #repo.store(c)
        #Command design pattern

        self.assertRaises(ValueError,repo.store,c)
       
        #should be <=> to above
        with self.assertRaises(ValueError):
            repo.store(c)
        self.assertEqual(repo[0].id,1)


        repo.delete(1)
        self.assertEqual(len(repo),0)
