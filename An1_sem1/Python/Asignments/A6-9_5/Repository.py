from Module import *
from datetime import datetime

class Undo_controller():
    def __init__(self):
        self._commandHist=[]
        self._paramHist=[]
        self._remPersSpec=[]
        self._index=-1
        self._duringUndo=False

    def add_hist(self,cmd,Type,act):
        if self._duringUndo==True:
            return

        self._paramHist.append(cmd)
        self._commandHist.append(Type)
        self._remPersSpec.append(act)
        if act !=0:
            self._remPersSpec[len(self._remPersSpec)-1]=act
        

        self._index += 1

    def undo(self):
        if self._index==-1:
            raise ValueError("No more undos!")
        self._duringUndo=True

        if self._commandHist[self._index]=="add_person":
            cmd=self._paramHist[self._index].split()
            repo.remove_person(cmd[0])
        elif self._commandHist[self._index]=="add_activity":
            cmd=self._paramHist[self._index].split()
            repo.remove_activity(cmd[0])
        elif self._commandHist[self._index]=="remove_person":
            param=self._paramHist[self._index]
            prm=param.split()
            repo.add_person(param)
            for i in range (0,len(repo._activities)):
                ilist=self._remPersSpec[self._index]
                for j in range(0,len(self._remPersSpec[self._index])):
                    if i== ilist[j]:
                       repo._activities[i].pid.append(prm[0])
        elif self._commandHist[self._index]=="remove_activity":
            repo.add_activity(self._paramHist[self._index])
        elif self._commandHist[self._index]=="update_person":
            repo.update_person(self._remPersSpec[self._index])   
        elif self._commandHist[self._index]=="update_activity":
            repo.update_activity(self._remPersSpec[self._index])

        self._index += -1
        self._duringUndo=False


    def redo(self):
        if self._index==len(self._paramHist)-1:
            raise ValueError("No more redos!")
        self._duringUndo=True
        self._index += 1

        if self._commandHist[self._index]=="add_person":
            param=self._paramHist[self._index]
            prm=param.split()
            repo.add_person(param)
            for i in range (0,len(repo._activities)):
                ilist=self._remPersSpec[self._index]
                for j in range(0,len(self._remPersSpec[self._index])):
                    if i== ilist[j]:
                       repo._activities[i].pid.append(prm[0])
        elif self._commandHist[self._index]=="add_activity":
            repo.add_activity(self._paramHist[self._index])
        elif self._commandHist[self._index]=="remove_person":
            cmd=self._paramHist[self._index].split()
            repo.remove_person(cmd[0])
        elif self._commandHist[self._index]=="remove_activity":
            cmd=self._paramHist[self._index].split()
            repo.remove_activity(cmd[0])
        elif self._commandHist[self._index]=="update_person":
            repo.update_person(self._paramHist[self._index])   
        elif self._commandHist[self._index]=="update_activity":
            repo.update_activity(self._paramHist[self._index])

        
        self._duringUndo=False

    def print_hist(self):
        for i in range(0,len(self._paramHist)):
            prt=str(i)+"   "+self._commandHist[i]+"    "+self._paramHist[i]
            if i==self._index:
                prt=prt+"      <---"
            print(prt)


History=Undo_controller()


'''


                                      Normal Repository




'''


class Repository():

    def __init__(self):
        self._persons=[]
        self._activities=[]

    def add_person(self,command):
        T="add_person"
        cmd=command.split()
        for i in range (0, len(self._persons)):
            if (self._persons[i].id==cmd[0]):
                raise ValueError("ID already defined")
        prs=Person(cmd[0],cmd[1],cmd[2])
        self._persons.append(prs)
        History.add_hist(cmd[0],T,0)


    def add_person_2(self,command):
        T="add_person"
        cmd=command.split()
        k=0
        for i in range (0, len(self._persons)):
            if (self._persons[i].id==cmd[0]):
                raise ValueError("ID already defined")
        for i in range(0,len(self._persons)):
            if(cmd[1]==self._persons[i].name):
                k += 1
        if(k>0):
            cmd[1]=cmd[1]+"("+str(k+1)+")"
        prs=Person(cmd[0],cmd[1],cmd[2])
        self._persons.append(prs)
        History.add_hist(command,T,0)


    def add_activity(self,command):
        T="add_activity"
        cmd=command.split()
        for i in range (0, len(self._activities)):
            if (self._activities[i].aid==cmd[0]):
                raise ValueError("ID already defined")
        
        c=cmd[1]
        cmd[1]=[]
        cmd[1].append(c)
        k=1

        if len(cmd)>5:
            for i in range(2,len(cmd)-3):
                cmd[1].append(cmd[i])
                k += 1



        if k>1:
            cmd[2]=cmd[len(cmd)-3]
            cmd[3]=cmd[len(cmd)-2]
            cmd[4]=cmd[len(cmd)-1]



        act=Activity(cmd[0],cmd[1],cmd[2],cmd[3],cmd[4])
        self._activities.append(act)
        History.add_hist(command,T,0)

    def remove_person(self,command):
        k=0
        alist=[]
        T="remove_person"
        for i in range (len(self._persons)-1,-1,-1):
            if (self._persons[i].id==command):
                cmd=self._persons[i].id+" "+self._persons[i].name+" "+self._persons[i].phone
                for j in range(0,len(self._activities)):
                    for h in range(len(self._activities[j].pid)-1,-1,-1):
                        if (command==self._activities[j].pid[h]):
                            alist.append(j)
                            self._activities[j].pid.pop(h)
                        
                k=1
                self._persons.pop(i)    
        if k==0:
            raise ValueError("Person ID not found")
        History.add_hist(cmd,T,alist)

    def remove_activity(self,command):
        k=0
        T="remove_activity"
        for i  in range (len(self._activities)-1,-1,-1):
            if (self._activities[i].aid==command):
                cmd=self._activities[i].aid
                for j in self._activities[i].pid:
                    cmd=cmd+" "+str(j)
                cmd=cmd+" "+self._activities[i].date+" "+self._activities[i].time+" "+self._activities[i].description
                k=1
                self._activities.pop(i)
        if k==0:
            raise ValueError("Activity ID not found")
        History.add_hist(cmd,T,0)


    def update_person(self,command):
        k=0
        add=""
        T="update_person"
        cmd=command.split()
        for i in range(0, len(self._persons)):
            if(cmd[0]==self._persons[i].id):
                command=self._persons[i].id+" "+self._persons[i].name+" "+self._persons[i].phone
                if(cmd[1]=="name"):
                    k=1
                    add=self._persons[i].id+" name "+self._persons[i].name
                    self._persons[i].name=cmd[2]
                    command=self._persons[i].id+" name "+self._persons[i].name
                    break
                elif(cmd[1]=="phone"):
                    k=1
                    add=self._persons[i].id+" phone "+self._persons[i].phone
                    self._persons[i].phone=cmd[2]
                    command=self._persons[i].id+" phone "+self._persons[i].phone
                    break
                else:
                    raise ValueError("Parameter not found")
        if k==0:
            raise ValueError("Person not found")
        History.add_hist(command,T,add)


    def update_activity(self,command):
        k=0
        add=""
        T="update_activity"
        cmd=command.split()
        for i in range(0,len(self._activities)):
            if(cmd[0]==self._activities[i].aid):
                command=self._activities[i].aid
                for j in self._activities[i].pid:
                    command=command+" "+j
                command=command+self._activities[i].date+" "+self._activities[i].time+" "+self._activities[i].description    
                if(cmd[1]=="date"):
                    k=1
                    add=self._activities[i].aid+" date "+self._activities[i].date
                    self._activities[i].date=cmd[2]
                    command=command[i].aid+" date "+self._activities[i].date
                    break
                elif(cmd[1]=="time"):
                    k=1
                    add=self._activities[i].aid+" time "+self._activities[i].time
                    self._activities[i].time=cmd[2]
                    command=command[i].aid+" time "+self._activities[i].time
                    break
                elif(cmd[1]=="description"):
                    k=1
                    add=self._activities[i].aid+" description "+self._activities[i].description
                    self._activities[i].description=cmd[2]
                    command=self._activities[i].aid+" description "+self._activities[i].description
                    break
                else:
                    raise ValueError("Parameter not found")
        if k==0:
            raise ValueError("Activity not found")
        History.add_hist(command,T,add)

    def get_persons(self):
        prslist=[]
        for i in self._persons:
            prslist.append(i)
        return prslist

    def get_actvities(self):
        actlist=[]
        for i in self._activities:
            actlist.append(i)
        return actlist


def populate_persons():
    ids=[1,2,3,4,5,6,7,8,9,10]
    names=["Mark","Julie","Patric","Joe","Marie","Jo","Carl","Rick","Cass","Bruce"]
    phones=["0754326895","0256348958","024895331","0754298625","0214587682","0249874329","0741236994","0712365985","0763254990","0763445219"]

    for i in range(0,len(ids)):
        repo.add_person(str(ids[i])+" "+names[i]+" "+phones[i])



def populate_activities():
    aids=[1,2,3,4,5,6,7,8,9,10,11]
    pids=["1 3 5","2 4","4","1 10","5 6","7 8 9","1 9 5","10","8 9","4 5 6","4 5 3"]
    dates=["12/5","12/5","13/6","10/9","11/9","10/1","7/2","9/7","15/5","21/8","12/5"]
    times=["12:30","12:30","10:00","11:15","13:25","19:00","12:00","16:30","10:30","11:00","19:00"]
    descriptions=["activity1","activity2","activity3","activity4","activity5","activity6","activity7","activity8","activity9","activity10","activity11"]

    for i in range(0,len(aids)):
        repo.add_activity(str(aids[i])+" "+pids[i]+" "+dates[i]+" "+times[i]+" "+descriptions[i])



'''


                                    Text Repository




'''









class RepositoryText():
    def __init__ (self,personsFile,activitiesFile):
        self._personsFile=personsFile
        self._activitiesFile=activitiesFile
        self._persons=[]
        self._activities=[]

    def add_person(self,command):
        T="add_person"
        cmd=command.split()
        for i in range (0, len(self._persons)):
            if (self._persons[i].id==cmd[0]):
                raise ValueError("ID already defined")
        prs=Person(cmd[0],cmd[1],cmd[2])
        self._persons.append(prs)
        History.add_hist(cmd[0],T,0)
        self.updatePersonFiles()


    def add_person_2(self,command):
        T="add_person"
        cmd=command.split()
        k=0
        for i in range (0, len(self._persons)):
            if (self._persons[i].id==cmd[0]):
                raise ValueError("ID already defined")
        for i in range(0,len(self._persons)):
            if(cmd[1]==self._persons[i].name):
                k += 1
        if(k>0):
            cmd[1]=cmd[1]+"("+str(k+1)+")"
        prs=Person(cmd[0],cmd[1],cmd[2])
        self._persons.append(prs)
        History.add_hist(command,T,0)
        self.updatePersonFiles()


    def add_activity(self,command):
        T="add_activity"
        cmd=command.split()
        for i in range (0, len(self._activities)):
            if (self._activities[i].aid==cmd[0]):
                raise ValueError("ID already defined")
        
        c=cmd[1]
        cmd[1]=[]
        cmd[1].append(c)
        k=1

        if len(cmd)>5:
            for i in range(2,len(cmd)-3):
                cmd[1].append(cmd[i])
                k += 1



        if k>1:
            cmd[2]=cmd[len(cmd)-3]
            cmd[3]=cmd[len(cmd)-2]
            cmd[4]=cmd[len(cmd)-1]



        act=Activity(cmd[0],cmd[1],cmd[2],cmd[3],cmd[4])
        self._activities.append(act)
        History.add_hist(command,T,0)
        self.updateActivityFiles()

    def remove_person(self,command):
        k=0
        alist=[]
        T="remove_person"
        for i in range (len(self._persons)-1,-1,-1):
            if (self._persons[i].id==command):
                cmd=self._persons[i].id+" "+self._persons[i].name+" "+self._persons[i].phone
                for j in range(0,len(self._activities)):
                    for h in range(len(self._activities[j].pid)-1,-1,-1):
                        if (command==self._activities[j].pid[h]):
                            alist.append(j)
                            self._activities[j].pid.pop(h)
                        
                k=1
                self._persons.pop(i)    
        if k==0:
            raise ValueError("Person ID not found")
        History.add_hist(cmd,T,alist)
        self.updatePersonFiles()

    def remove_activity(self,command):
        k=0
        T="remove_activity"
        for i  in range (len(self._activities)-1,-1,-1):
            if (self._activities[i].aid==command):
                cmd=self._activities[i].aid
                for j in self._activities[i].pid:
                    cmd=cmd+" "+str(j)
                cmd=cmd+" "+self._activities[i].date+" "+self._activities[i].time+" "+self._activities[i].description
                k=1
                self._activities.pop(i)
        if k==0:
            raise ValueError("Activity ID not found")
        History.add_hist(cmd,T,0)
        self.updateActivityFiles()


    def update_person(self,command):
        k=0
        add=""
        T="update_person"
        cmd=command.split()
        for i in range(0, len(self._persons)):
            if(cmd[0]==self._persons[i].id):
                command=self._persons[i].id+" "+self._persons[i].name+" "+self._persons[i].phone
                if(cmd[1]=="name"):
                    k=1
                    add=self._persons[i].id+" name "+self._persons[i].name
                    self._persons[i].name=cmd[2]
                    command=self._persons[i].id+" name "+self._persons[i].name
                    break
                elif(cmd[1]=="phone"):
                    k=1
                    add=self._persons[i].id+" phone "+self._persons[i].phone
                    self._persons[i].phone=cmd[2]
                    command=self._persons[i].id+" phone "+self._persons[i].phone
                    break
                else:
                    raise ValueError("Parameter not found")
        if k==0:
            raise ValueError("Person not found")
        History.add_hist(command,T,add)
        self.updatePersonFiles()


    def update_activity(self,command):
        k=0
        add=""
        T="update_activity"
        cmd=command.split()
        for i in range(0,len(self._activities)):
            if(cmd[0]==self._activities[i].aid):
                command=self._activities[i].aid
                for j in self._activities[i].pid:
                    command=command+" "+j
                command=command+self._activities[i].date+" "+self._activities[i].time+" "+self._activities[i].description    
                if(cmd[1]=="date"):
                    k=1
                    add=self._activities[i].aid+" date "+self._activities[i].date
                    self._activities[i].date=cmd[2]
                    command=command[i].aid+" date "+self._activities[i].date
                    break
                elif(cmd[1]=="time"):
                    k=1
                    add=self._activities[i].aid+" time "+self._activities[i].time
                    self._activities[i].time=cmd[2]
                    command=command[i].aid+" time "+self._activities[i].time
                    break
                elif(cmd[1]=="description"):
                    k=1
                    add=self._activities[i].aid+" description "+self._activities[i].description
                    self._activities[i].description=cmd[2]
                    command=self._activities[i].aid+" description "+self._activities[i].description
                    break
                else:
                    raise ValueError("Parameter not found")
        if k==0:
            raise ValueError("Activity not found")
        History.add_hist(command,T,add)
        self.updateActivityFiles()

    def populatePersons(self):
        persons_file=open(self._personsFile,"r")
        lines=persons_file.readlines()
        persons_file.close()
        for i in lines:
            self.add_person(i)
        

    def populateActivities(self):
        activities_file=open(self._activitiesFile,"r")
        lines=activities_file.readlines()
        activities_file.close()
        for i in lines:
            self.add_activity(i)
        
    def updatePersonFiles(self):
        perFile = open(self._personsFile,"w")
        for i in self._persons:
            pers_append=i.id+" "+i.name+" "+i.phone+"\n"
            perFile.write(pers_append)
        perFile.close()

    def updateActivityFiles(self):
        actFile = open(self._activitiesFile,"w")
        for i in self._activities:
            act_append=i.aid+" "
            for j in i.pid:
                act_append=act_append+j+" "
            act_append=act_append+i.date+" "+i.time+" "+i.description+"\n"
            actFile.write(act_append)
        actFile.close()

    def get_persons(self):
        prslist=[]
        for i in self._persons:
            prslist.append(i)
        return prslist

    def get_actvities(self):
        actlist=[]
        for i in self._activities:
            actlist.append(i)
        return actlist


'''

###############################################################################################################


'''

class RepositoryBinary:
    pass



'''

###############################################################################################################


'''

class RepositoryText2():
    def __init__ (self,personsFile,activitiesFile):
        self._personsFile=personsFile
        self._activitiesFile=activitiesFile
        self._persons=[]
        self._activities=[]

    def add_person(self,command):
        T="add_person"
        cmd=command.split()
        for i in range (0, len(self._persons)):
            if (self._persons[i].id==cmd[0]):
                raise ValueError("ID already defined")
        prs=Person(cmd[0],cmd[1],cmd[2])
        self._persons.append(prs)
        History.add_hist(cmd[0],T,0)
        self.updatePersonFiles()


    def add_person_2(self,command):
        T="add_person"
        cmd=command.split()
        k=0
        for i in range (0, len(self._persons)):
            if (self._persons[i].id==cmd[0]):
                raise ValueError("ID already defined")
        for i in range(0,len(self._persons)):
            if(cmd[1]==self._persons[i].name):
                k += 1
        if(k>0):
            cmd[1]=cmd[1]+"("+str(k+1)+")"
        prs=Person(cmd[0],cmd[1],cmd[2])
        self._persons.append(prs)
        History.add_hist(command,T,0)
        self.updatePersonFiles()


    def add_activity(self,command):
        T="add_activity"
        cmd=command.split()
        for i in range (0, len(self._activities)):
            if (self._activities[i].aid==cmd[0]):
                raise ValueError("ID already defined")
        
        c=cmd[1]
        cmd[1]=[]
        cmd[1].append(c)
        k=1

        if len(cmd)>5:
            for i in range(2,len(cmd)-3):
                cmd[1].append(cmd[i])
                k += 1



        if k>1:
            cmd[2]=cmd[len(cmd)-3]
            cmd[3]=cmd[len(cmd)-2]
            cmd[4]=cmd[len(cmd)-1]



        act=Activity(cmd[0],cmd[1],cmd[2],cmd[3],cmd[4])
        self._activities.append(act)
        History.add_hist(command,T,0)
        self.updateActivityFiles()

    def remove_person(self,command):
        k=0
        alist=[]
        T="remove_person"
        for i in range (len(self._persons)-1,-1,-1):
            if (self._persons[i].id==command):
                cmd=self._persons[i].id+" "+self._persons[i].name+" "+self._persons[i].phone
                for j in range(0,len(self._activities)):
                    for h in range(len(self._activities[j].pid)-1,-1,-1):
                        if (command==self._activities[j].pid[h]):
                            alist.append(j)
                            self._activities[j].pid.pop(h)
                        
                k=1
                self._persons.pop(i)    
        if k==0:
            raise ValueError("Person ID not found")
        History.add_hist(cmd,T,alist)
        self.updatePersonFiles()

    def remove_activity(self,command):
        k=0
        T="remove_activity"
        for i  in range (len(self._activities)-1,-1,-1):
            if (self._activities[i].aid==command):
                cmd=self._activities[i].aid
                for j in self._activities[i].pid:
                    cmd=cmd+" "+str(j)
                cmd=cmd+" "+self._activities[i].date+" "+self._activities[i].time+" "+self._activities[i].description
                k=1
                self._activities.pop(i)
        if k==0:
            raise ValueError("Activity ID not found")
        History.add_hist(cmd,T,0)
        self.updateActivityFiles()


    def update_person(self,command):
        k=0
        add=""
        T="update_person"
        cmd=command.split()
        for i in range(0, len(self._persons)):
            if(cmd[0]==self._persons[i].id):
                command=self._persons[i].id+" "+self._persons[i].name+" "+self._persons[i].phone
                if(cmd[1]=="name"):
                    k=1
                    add=self._persons[i].id+" name "+self._persons[i].name
                    self._persons[i].name=cmd[2]
                    command=self._persons[i].id+" name "+self._persons[i].name
                    break
                elif(cmd[1]=="phone"):
                    k=1
                    add=self._persons[i].id+" phone "+self._persons[i].phone
                    self._persons[i].phone=cmd[2]
                    command=self._persons[i].id+" phone "+self._persons[i].phone
                    break
                else:
                    raise ValueError("Parameter not found")
        if k==0:
            raise ValueError("Person not found")
        History.add_hist(command,T,add)
        self.updatePersonFiles()


    def update_activity(self,command):
        k=0
        add=""
        T="update_activity"
        cmd=command.split()
        for i in range(0,len(self._activities)):
            if(cmd[0]==self._activities[i].aid):
                command=self._activities[i].aid
                for j in self._activities[i].pid:
                    command=command+" "+j
                command=command+self._activities[i].date+" "+self._activities[i].time+" "+self._activities[i].description    
                if(cmd[1]=="date"):
                    k=1
                    add=self._activities[i].aid+" date "+self._activities[i].date
                    self._activities[i].date=cmd[2]
                    command=command[i].aid+" date "+self._activities[i].date
                    break
                elif(cmd[1]=="time"):
                    k=1
                    add=self._activities[i].aid+" time "+self._activities[i].time
                    self._activities[i].time=cmd[2]
                    command=command[i].aid+" time "+self._activities[i].time
                    break
                elif(cmd[1]=="description"):
                    k=1
                    add=self._activities[i].aid+" description "+self._activities[i].description
                    self._activities[i].description=cmd[2]
                    command=self._activities[i].aid+" description "+self._activities[i].description
                    break
                else:
                    raise ValueError("Parameter not found")
        if k==0:
            raise ValueError("Activity not found")
        History.add_hist(command,T,add)
        self.updateActivityFiles()

    def populatePersons(self):
        persons_file=open(self._personsFile,"r")
        lines=persons_file.readlines()
        persons_file.close()
        for i in lines:
            self.add_person(i)
        

    def populateActivities(self):
        activities_file=open(self._activitiesFile,"r")
        lines=activities_file.readlines()
        activities_file.close()
        for i in lines:
            self.add_activity(i)
        
    def updatePersonFiles(self):
        perFile = open(self._personsFile,"w")
        for i in self._persons:
            pers_append=i.id+" "+i.name+" "+i.phone+"\n"
            perFile.write(pers_append)
        perFile.close()

    def updateActivityFiles(self):
        actFile = open(self._activitiesFile,"w")
        for i in self._activities:
            act_append=i.aid+" "
            for j in i.pid:
                act_append=act_append+j+" "
            act_append=act_append+i.date+" "+i.time+" "+i.description+"\n"
            actFile.write(act_append)
        actFile.close()

    def get_persons(self):
        prslist=[]
        for i in self._persons:
            prslist.append(i)
        return prslist

    def get_actvities(self):
        actlist=[]
        for i in self._activities:
            actlist.append(i)
        return actlist


with open("Users\gamac\OneDrive\Desktop\Python\Asignments\A6-9_5\settings.txt","r") as settings:

    repoSettings=settings.readlines()
    repoType=repoSettings[0].split()
    repoPersons=repoSettings[1].split()
    repoActivities=repoSettings[2].split()
    settings.close()
    if repoType[2]=="inmemory":
        repo=Repository()
        populate_persons()
        populate_activities()
    elif repoType[2]=="textfiles":
        repo=RepositoryText(repoPersons[2],repoActivities[2])
        repo.populatePersons()
        repo.populateActivities()
    elif repoType[2]=="binaryfiles":
        repo=RepositoryBinary(repoPersons[2],repoActivities[2])
    elif repoType[2]=="textfile2":
        repo=RepositoryText2(repoPersons[2],repoActivities[2])
        repo.populatePersons()
        repo.populateActivities()



