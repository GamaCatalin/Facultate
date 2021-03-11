from datetime import datetime
import random
from Repository import Repository
from Repository import repo

'''
def repoType():
    with open('A6-9_5/settings.txt', 'r') as settingFile:
        line1 = settingFile.readline()
        type=line1.split()
        print(type[2])
        if type[2]=="inmemory":
            from Repository import Repository
            from Repository import repo
        elif type[2] == "textfiles" :
            from RepositoryText import Repository
            repo=Repository()
        elif type[2] == "binaryfiles":
            from RepositoryBinary import Repository
            repo=Repository()

repoType()

'''
def searchPerson(prs):
    prslist=[]
    for i in repo._persons:
        if(i.name==prs or i.phone==prs):
            prslist.append(i)
    return prslist        

def searchActivity(act):
    actlist=[]
    for i in repo._activities:
        if(i.date==act):
            actlist.append(i)
        elif(i.time==act):
            actlist.append(i)
        elif(i.description==act):
            actlist.append(i)
    return actlist

def searchPersonId(pid):
    for i in repo._persons:
        if(int(i.id)==int(pid)):
            return i


def statisticDate(date):
    actlist=[]
    for i in repo._activities:
        if i.date==date:
            actlist.append(i)
    for i in range(len(actlist)-1):
        for j in range( i+1, len(actlist) ):
            A=actlist[i].time
            B=actlist[j].time
            a=A.split(":")
            b=B.split(":")
            a[0]=int(a[0])
            a[1]=int(a[1])
            b[0]=int(b[0])
            b[1]=int(b[1])
            if b[0]<a[0]:
                temp=actlist[j]
                actlist[j]=actlist[i]
                actlist[i]=temp
            elif b[0]==a[0] and b[1]<a[1]:
                temp=actlist[j]
                actlist[j]=actlist[i]
                actlist[i]=temp
    return actlist

def statisticBusy():
    actlist=[]
    busy=[]
    for i in range(0,372):
        busy.append(0)
    for i in range(0,len(repo._activities)):
        actlist.append(repo._activities[i])
        date=datetime.strptime(actlist[i].date, "%d/%m")
        busy[(date.month-1)*31+date.day] += 1

    for i in range(0,len(actlist)-1):
        date1=datetime.strptime(actlist[i].date, "%d/%m")
        for j in range(i+1,len(actlist)):
            date2=datetime.strptime(actlist[j].date, "%d/%m")
            if busy[(date1.month-1)*31+date1.day]<busy[(date2.month-1)*31+date2.day]:
                x=actlist[i]
                actlist[i]=actlist[j]
                actlist[j]=x
            
    return actlist
     
def statisticPersonDate(date):
    goinglist=[]
    times=[]
    prslist=[]
    
    for i in range(0,len(repo._persons)):
        goinglist.append(0)
        times.append(0)

    for i in repo._activities:
        if i.date == date:
            for j in range(0, len(i.pid)):
                goinglist[int(i.pid[j])] += 1
    
    for i in range(0,len(goinglist)):
        if goinglist[i]>0:
            if times[goinglist[i]]==0:
                times[goinglist[i]]=[]
                times[goinglist[i]].append(i)
            else:
                times[goinglist[i]].append(i)
    for i in range(len(times)-1,0,-1):
        if times[i]!=0:
            for j in range (0,len(times[i])):
                prs=searchPersonId(times[i][j])
                prslist.append(prs)
    return prslist          


def statisticPerson(prs):
    actlist=[]
    for i in repo._activities:
        for j in i.pid:
            if (j==prs):
                actlist.append(i)
    return actlist


















def rand_commands(nr):
    randAddPers=["9001 Mark 1234567890","9002 Julie 0987654321","9003 Anthony 0783294190","9004 Jack 0887939543","9005 Marcus 9993231239"]
    randRemovePers=["9",'5','3','1','6']
    randAddAct=["9001 4 1 2 14/5 13:00 activity9001","9002 8 9 5 5/10 9:30 activity9002","9003 7 5 6 19/6 7:15 activity9003","9004 9 4 2 29/8 20:00 activity9004","9005 7 4 3 30/8 9:30 activity9005"]
    randRemoveAct=['11','4','2','6','1']
    randUpdatePerson=["10 name James","8 phone 12fg567890","5 name John","1 name Aurelian","2 name Phil"]
    randUpdateActivity=["1 description works1","10 description works10","8 description works8","5 description UpdatedDescription5","11 description UpdatedDescription11"]
    indexAddPrs=0
    indexRemovePrs=0
    indexAddAct=0
    indexRemoveAct=0
    indexPrs=0
    indexAct=0  
    for i in range(1,nr+1):
        randCommand=random.randint(1,6)
        if randCommand==1:
            print(str(i)+" add_person")
            indexAddPrs += 1
            repo.add_person(randAddPers[indexAddPrs])
        elif randCommand==2:
            print(str(i)+" remove_person")
            indexRemovePrs += 1
            repo.remove_person(randRemovePers[indexRemovePrs])
        elif randCommand==3:
            print(str(i)+" add_activity")
            indexAddAct += 1
            repo.add_activity(randAddAct[indexAddAct])
        elif randCommand==4:
            print(str(i)+" remove_activity")
            indexRemoveAct += 1
            repo.remove_activity(randRemoveAct[indexRemoveAct])
        elif randCommand==5:
            print(str(i)+" update_person")
            indexPrs += 1
            repo.update_person(randUpdatePerson[indexPrs])
        elif randCommand==6:
            print(str(i)+" update_activity")
            indexAct += 1
            repo.update_activity(randUpdateActivity[indexAct])

