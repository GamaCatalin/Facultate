from tkinter import *
from Repository import *
from Services import *
from datetime import datetime



class GUI:
    def __init__(self):
        pass
        

    def printPersons(self,prslist):
        print()
        if len(prslist)==0:
            print("No person found")
        else:
            for i in prslist:
                print(str(i.id)+" "+i.name+" "+i.phone)

    def printActivities(self,actlist):
        print()
        if len(actlist)==0:
            print("No activities found")
        else: 
            for i in actlist:
                print(str(i.aid)+" "+str(i.pid)+" "+i.date+" "+i.time+" "+i.description)




root=Tk()

root.title("Assignement 06-08")

def printPersons(prslist):
    print()
    if len(prslist)==0:
        print("No person found")
    else:
        for i in prslist:
            print(str(i.id)+" "+i.name+" "+i.phone)

def printActivities(actlist):
    print()
    if len(actlist)==0:
        print("No activities found")
    else: 
        for i in actlist:
            print(str(i.aid)+" "+str(i.pid)+" "+i.date+" "+i.time+" "+i.description)

textBox = Text(root,height=15,width=100)
textBox.grid(rowspan=15,column=2)

label_1 = Label(root,text="Test label")
label_1.grid(row=1,column=0)



root.mainloop()