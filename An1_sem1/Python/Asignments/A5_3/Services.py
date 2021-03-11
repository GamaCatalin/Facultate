from copy import deepcopy
from Module import Students
from Module import AddMem
from Module import get_group
from Module import Student
from Module import get_id
from Module import memList
from Module import lenList




def AddStudent(stud):
    s=stud.split()

    assert int(s[0])>0,"Id must be > 0"
    assert int(s[2])>0,"Group must be > 0"
    assert int(s[2])>99 and int(s[2])<1000,"Group must be between 100 and 999"

    lenght=len(Students)
    t=1
    if lenght>0:
        for i in range (0, lenght):
            if s[0]==get_id(i):
                print("Duplicate ID!")
                t=0
            
    if t==1:
        stdnt = Student(s[0],s[1],s[2])
    Students.append(stdnt)
    AddMem()



def testAdd():
    AddStudent("1 Ian 999")   
    AddStudent("12 Mike -1")   
    AddStudent("2 John 10003")   
    AddStudent("3 Adelle 999")   

def filter(del_group):
    assert del_group>99 and del_group<1000, "Selected group must be between 100 and 999"
    for i in range(len(Students)-1, 0, -1):
        if get_group(i)==del_group:
            Students.pop(i)
    AddMem()



def undo():
    current=len(memList)-1
    if current > 0 :
        Students.clear()  
        for i in range (0, lenList[current-1]):
                Students.append(memList[current-1][i])
        memList.pop()
    else:
        print()
        print("Can't undo")       
