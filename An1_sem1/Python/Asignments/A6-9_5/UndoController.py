
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