'''
                                                                            Family Expenses

'''

import datetime
from copy import deepcopy
import copy
global current
current = 0




def add_hist():
    
    '''
    adds the current expenses to the history list

    '''



    global current

    Vlisthist.append(0)
    Dlisthist.append(0)
    Clisthist.append(0)
    
    Llist.append(len(Vlist))
    
    Vlisthist[current]=[0]*(len(Vlist))
    Dlisthist[current]=[0]*(len(Vlist))
    Clisthist[current]=[0]*(len(Vlist))


    for i in range (0,len(Vlist)):
        Vlisthist[current][i]=Vlist[i]
        Dlisthist[current][i]=Dlist[i]
        Clisthist[current][i]=Clist[i]

    current += 1

def populate():
    '''
    :return: populates the list with elements
    '''

    Vtemp = ["100", "50", "100", "20", "25", "150", "100", "50", "25", "100"]
    Ctemp = ["housekeeping", "food", "internet", "internet", "food", "transport", "food", "others", "clothing",
             "housekeeping"]
    Dtemp = ["2", "3", "5", "7", "8", "13", "15", "15", "20", "28"]

    for i in Vtemp:
        Vlist.append(i)

    for i in Dtemp:
        Dlist.append(i)

    for i in Ctemp:
        Clist.append(i)

    global current

    Vlisthist.append(0)
    Dlisthist.append(0)
    Clisthist.append(0)
    
    Llist.append(len(Vlist))

    Vlisthist[current]=[0]*(len(Vlist))
    Dlisthist[current]=[0]*(len(Vlist))
    Clisthist[current]=[0]*(len(Vlist))


    for i in range (0,len(Vlist)):
        Vlisthist[current][i]=Vlist[i]
        Dlisthist[current][i]=Dlist[i]
        Clisthist[current][i]=Clist[i]
        


    current += 1




def add(summ, category):
    '''
    Adds an expense to the list

    '''

    today = datetime.datetime.now()

    Vlist.append(summ)
    Clist.append(category)
    Dlist.append(today.strftime("%d"))



    add_hist()
    

    print()




def remove(p1, p2, p3):
    '''

    removes elements given the right parameters


    '''

    if (len(p1) > 2):
        for i in range(len(Clist) - 1, -1, -1):
            if Clist[i] == p1:
                Clist.pop(i)
                Dlist.pop(i)
                Vlist.pop(i)
    elif p3 != 0:
        for i in range(len(Clist) - 1, -1, -1):
            if int(Dlist[i]) >= int(p1) and int(Dlist[i]) <= int(p3):
                Clist.pop(i)
                Dlist.pop(i)
                Vlist.pop(i)
    else:
        for i in range(len(Clist) - 1, -1, -1):
            if Dlist[i] == p1:
                Clist.pop(i)
                Dlist.pop(i)
                Vlist.pop(i)

        
    add_hist()
    




def insert(date, summ, category):
    '''
    Inserts an expense to the list for a given date

    '''

    Vlist.append(summ)
    Clist.append(category)
    Dlist.append(date)


    add_hist()


def list_all():
    '''
    Lists all the expenses of the month
    
    '''

    lenght = len(Vlist)
    for i in range(0, lenght):
        print(Dlist[i], " ", Vlist[i], " ", Clist[i])


def list_spec(p1, p2, p3):
    '''

    :param p1: category of the returned list
    :param p2: sign of the value
    :param p3: value of the returned list
    :return: lists all the elements given the parameters
    '''

    lenght = len(Vlist)
    for i in range(0, lenght - 1):
        if (Clist[i] == p1):
            if (p2 == 0):
                print(Dlist[i], " ", Vlist[i], " ", Clist[i])
            elif (p2 == "<"):
                if (int(Vlist[i]) < int(p3)):
                    print(Dlist[i], " ", Vlist[i], " ", Clist[i])
            elif (p2 == ">"):
                if (int(Vlist[i]) > int(p3)):
                    print(Dlist[i], " ", Vlist[i], " ", Clist[i])
            elif (p2 == "="):
                if (int(Vlist[i]) == int(p3)):
                    print(Dlist[i], " ", Vlist[i], " ", Clist[i])


def sum(p1):

    '''
    add the values based on the given criteria


    '''


    S = 0
    for i in range(0, len(Vlist) - 1):
        if (Clist[i] == p1):
            S = S + int(Vlist[i])
    print(S)


def max():

    '''
    writes the day with the maximum expenses

    '''

    Maxv = []
    Vmax = 0
    Dmax = 0
    for i in range(0, 31):
        Maxv.append(0)
    for i in range(0, len(Clist) - 1):
        Maxv[int(Dlist[i])] = Maxv[int(Dlist[i])] + int(Vlist[i])
    for i in range(1, 31):
        if Maxv[i] > Vmax:
            Vmax = Maxv[i]
            Dmax = i
    print(Dmax)


def sort(p1):

    '''
    sorts the list based on the category
    '''


    Sortc = []
    Sortd = []
    Sortv = []

    if (len(p1) > 2):
        for i in range(0, len(Clist) - 1):
            if (Clist[i] == p1):
                Sortc.append(Clist[i])
                Sortd.append(Dlist[i])
                Sortv.append(Vlist[i])
    else:
        for i in range(0, len(Clist) - 1):
            if (Dlist[i] == p1):
                Sortc.append(Clist[i])
                Sortd.append(Dlist[i])
                Sortv.append(Vlist[i])

    for i in range(0, len(Sortc) - 1):
        for j in range(i + 1, len(Sortc)):
            if int(Sortv[i]) > int(Sortv[j]):
                tmp = Sortv[i]
                Sortv[i] = Sortv[j]
                Sortv[j] = tmp
                tmp = Sortd[i]
                Sortd[i] = Sortd[j]
                Sortd[j] = tmp
                tmp = Sortc[i]
                Sortc[i] = Sortc[j]
                Sortc[j] = tmp

    for i in range(0, len(Sortc)):
        print(Sortd[i], " ", Sortv[i], " ", Sortc[i])


def filter(p1, p2, p3):

    '''
    eliminates the elements not matching the criteria
    '''



    if (p3 != 0):
        for i in range(len(Clist) - 1, -1, -1):
            if Clist[i] != p1:
                Clist.pop(i)
                Dlist.pop(i)
                Vlist.pop(i)
            elif (Clist[i] == p1 and p2 == "<" and int(Vlist[i]) >= int(p3)):
                Clist.pop(i)
                Dlist.pop(i)
                Vlist.pop(i)
            elif (Clist[i] == p1 and p2 == "=" and int(Vlist[i]) != int(p3)):
                Clist.pop(i)
                Dlist.pop(i)
                Vlist.pop(i)
            elif (Clist[i] == p1 and p2 == ">" and int(Vlist[i]) <= int(p3)):
                Clist.pop(i)
                Dlist.pop(i)
                Vlist.pop(i)
    else:
        for i in range(len(Clist) - 1, -1, -1):
            if (Clist[i] != p1):
                Clist.pop(i)
                Dlist.pop(i)
                Vlist.pop(i)

    add_hist()

        
def reset():
    Vlist.clear()
    Dlist.clear()
    Clist.clear()


def undo():

    '''

    

    '''

    global current


    if(current>1):
        reset()
        current += -1
        for i in range (0,Llist[current-1]):            
            Vlist.append(Vlisthist[current-1][i])
            Clist.append(Clisthist[current-1][i])
            Dlist.append(Dlisthist[current-1][i]) 
        Vlisthist.pop()
        Clisthist.pop()
        Dlisthist.pop()
    else:
        print("Can't undo")



def start():
    print(80 * "*")
    print("Use the commands:")
    print()
    print("-add <sum> <category>")
    print("-insert <day> <sum> <category>")
    print("-populate")
    print()
    print("-remove <day>")
    print("-remove <start day> to <end day>")
    print("-remove <category>")
    print()
    print("-list")
    print("-list <category>")
    print("-list <category> [ < | = | > ] <value>")
    print()
    print("-sum <category>")
    print("-max <day>")
    print("-sort <day>")
    print("-sort <category>")
    print()
    print("-filter <category>")
    print("-filter <category> [ < | = | > ] <value>")
    print()
    print("-undo")
    print()
    print("-exit")

    print(80 * "*")

    while True:

        print()

        print()

        comm = input()
        print()

        command = comm.split()

        if (command[0] == "add"):
            add(command[1], command[2])


        elif (command[0] == "insert"):
            insert(command[1], command[2], command[3])


        elif (command[0] == "remove"):
            if (len(command) == 2):
                command.append(0)
                command.append(0)
            remove(command[1], command[2], command[3])


        elif (command[0] == "list"):
            try:
                if (command[1] == "0"):
                    pass
            except:
                list_all()
            else:
                if (len(command) == 2):
                    command.append(0)
                    command.append(0)

                list_spec(command[1], command[2], command[3])


        elif (command[0] == "sum"):
            sum(command[1])


        elif (command[0] == "max"):
            max()


        elif (command[0] == "sort"):
            sort(command[1])


        elif (command[0] == "filter"):
            if (len(command) == 2):
                command.append(0)
                command.append(0)
            filter(command[1], command[2], command[3])



        elif (command[0] == "undo"):
            undo()


        elif (command[0] == "populate"):
            populate()


        elif (command[0] == "exit"):
            break
        else:
            print("Wrong command")


Llist = []
Vlisthist = []
Clisthist = []
Dlisthist = []
Vlist = []
Clist = []
Dlist = []



start()
