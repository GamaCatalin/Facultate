from Module import *
from datetime import datetime



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
