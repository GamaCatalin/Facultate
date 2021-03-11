from Services import AddStudent
from Services import filter
from Services import undo
from Module import populate
from Module import get_id
from Module import get_group
from Module import get_name
from Module import Students



def List():
    print()
    for i in range(0, len(Students)):
        id=get_id(i)
        name=get_name(i)
        group=get_group(i)
        print(str(id)+"  "+name+"  "+str(group))

def start():

    while True:
        print()
        print(80*"*")

        print(30*" "+"Menu")
        print()
        print("1.Add a new student")
        print("2.Populate the student list")
        print("3.List the students")
        print("4.Filter the students based on group")
        print("5.Undo")
        print()
        print("0.Exit")
        print(80*"*")

        choice=input("Enter a command: ")


        if(choice=="1"):
            stud=input("Enter a student: ")
            AddStudent(stud)
        elif(choice=="2"):
            populate()
        elif(choice=="3"):
            List()
        elif(choice=="4"):
            filter(int(input("Insert a group to filter: ")))
        elif(choice=="5"): 
            undo()
        elif(choice=="0"):
            break
        else:
            print()
            print("Invalid command") 
            print()  



start()        