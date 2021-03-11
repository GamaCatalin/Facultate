class Student:
    def __init__(self,id,name,group):
        self.id = id
        self.name = name
        self.group = group

Students=[]
memList=[]
lenList=[]

def get_id(n):
    return Students[n].id

def get_name(n):
    return Students[n].name

def get_group(n):
    return Students[n].group

def populate():
    pop_id=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    pop_name=["John", "Mark", "Ian", "Vicki", "Toby", "Cruz", "Jessie", "Delia", "William", "Jo"]
    pop_group=[123, 415, 415, 919, 919, 919, 340, 218, 919, 112]

    for i in range(0, len(pop_id)):
        stdnt = Student(pop_id[i],pop_name[i],pop_group[i])
        Students.append(stdnt)
    AddMem()


def AddMem():
    current = len(memList)
    lenList.append(len(Students))
    memList.append(0)
    memList[current]=lenList[current]*[0]
    
    for i in range (0, lenList[current]):
        memList[current][i]=Students[i]





