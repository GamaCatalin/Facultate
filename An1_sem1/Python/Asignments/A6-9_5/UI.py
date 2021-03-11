from Services import *
from datetime import datetime
from Repository import Repository
from Repository import History



class UI:

    def __init__(self):
        self._loop=True
        self._command=""

    def start(self):
        print()
        print(80*"*")
        print(30*" "+"Menu")
        print()
        print("1.Show persons")
        print("2.Show activities")
        print("3.Add a person")
        print("4.Add an activity")
        print("5.Remove a person")
        print("6.Remove an activity")
        print("7.Update a person")
        print("8.Update an activity")
        print("9.Search for a person")
        print("10.Search for an activity")
        print("11.Statistics for a given date")
        print("12.Busiest days")
        print("13.Activities for a person")
        print("14.Undo")
        print("15.Redo")
        print()
        print("0.Exit")
        print(80*"*")
        print()
        self.menu()

    def get_command(self):
        self._command=input("Enter a command: ")

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



    def menu(self):

        self.get_command()
        cmd=self._command
        if cmd=="1":
            self.printPersons(repo.get_persons())
        elif cmd=="2":
            self.printActivities(repo.get_actvities())
        elif cmd=="3":
            command=input("Enter a person: ")
            repo.add_person(command)
        elif cmd=="4":
            command=input("Enter an activity: ")
            repo.add_activity(command)
        elif cmd=="5":
            command=input("Enter a person you want to remove: ")
            repo.remove_person(command)
        elif cmd=="6":
            command=input("Enter an activity you want to remove: ")
            repo.remove_activity(command)
        elif cmd=="7":
            command=input("Enter a person you want to update: ")
            repo.update_person(command)
        elif cmd=="8":
            command=input("Enter an activity you want to update: ")
            repo.update_activity(command)
        elif cmd=="add2":
            command=input("Enter a person: ")
            repo.add_person_2(command)
        elif cmd=="9":
            command=input("Enter name or phone number: ")
            self.printPersons(searchPerson(command))
        elif cmd=="10":
            command=input("Enter date, time or description: ")
            self.printActivities(searchActivity(command))
        elif cmd=="11":
            command=input("Enter a date: ")
            self.printActivities(statisticDate(command))
        elif cmd=="12":
            self.printActivities(statisticBusy())
        elif cmd=="13":
            command=input("Enter a person ID: ")
            self.printActivities(statisticPerson(command))
        elif cmd=="14":
            History.undo()
        elif cmd=="15":
            History.redo()
        elif cmd=="prsdate":
            command=input("Enter a date: ")
            self.printPersons(statisticPersonDate(command))
        elif cmd=="printhist":
            History.print_hist()
        elif cmd=="random":
            command=input("How many random operations: ")
            rand_commands(int(command))
        elif cmd=="0":
            self._loop=False
        else:
            print("Invalid command")


u=UI()


while u._loop==True:
    u.start()