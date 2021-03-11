import unittest
from Client import *

class Repository():
    def __init__(self):
        pass

    def store(self):
        pass

    def find(self,c):
        pass

    def delete(self,ID):
        pass


def testRepo(self):
    r = Repository()
    self.assertEqual(0,len(r))
    r.store( (c := Client(1,"Ana",19) ) )
    self.assertEqual(1,len(r))
    self.assertEqual(c,r[0])
    r.store( (c2 := Client(2, "Marius", 20) ) )
    self.assertEqual(2,len(r))
    self.assertEqual(c,r[0])
    self.assertEqual(c2,r[1])
    self.assertEquals()

    self.assertEqual(1,r.find(2))
    self.assertRaises(RepositoryException, r.store, c2)

    r.delete(1)
    r.delete(2)

    self.assertEqual(0,len(r))