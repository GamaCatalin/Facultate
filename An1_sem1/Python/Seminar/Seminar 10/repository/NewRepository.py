#from repository.Repository import *


'''
    Implement a new kind of car repository
    What do we want?
        1.Program uses it in the same way as existing Repository
            -has the same methods, and they do the same thing
            -program can use both types of repos
            =>repos are interchangeble and independent
        2.Use text-file based persistence
            -save/load cars from the text file
            -keep program status between runs

'''





class CarTextRepository():
    def __init__(self,fileName):
        #Repository.__init__(self)
        self._fileName=fileName
        self._loadFile()


    def store(self,object):
        #1. call repository.store to validate and store the object
        Repository.store(self,obj)

        #Repo.store call ands in one or or two ways:
        #   1. object is stored to repo and shoulb be saved to file
        #   2. RepoException raised, object is not saved in repo, file should not change, exception has to be propagated to outer layer
        
        self._saveFile()

    def _saveFile():
        '''
        1. Open text file for writing('w')
        2. For each car in the repository:
            a. transform it into a one-line string
            b. write it to the file
        3. Close file
        '''
        pass



    def _loadFile(self):
        '''
        This function is private, so you are not allowed to call it from outside this class.Why?

        1.It does something internal to the class,which is undocumented
        2.If it's private, it can be changed at any time
        3.If we call this directly, the memory-based repo will not work
        4.If you have an SQL repo, that will also not work
        5.Files, sql, memory are what we use to store data, services should not care about that
        '''

        #1. Open the input text file for reading
        #2. For each line in the input file
        #   a. split line into comma-separated values (CSV)
        #   b. create a Car object using the parameters
        #   c. call repo.store to add to list
        #3. Close the file
        pass

