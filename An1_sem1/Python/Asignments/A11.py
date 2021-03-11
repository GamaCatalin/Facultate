
class Data:
    def __init__(self,data):
        self.list=data
        self.current=0
        self.max=len(self.list)

    def __iter__(self):
        return iter(self.list)

    def __next__(self):
        if self.current>self.max:
            raise StopIteration
        else:
            self.current+=1
            return self.current-1
    def __setitem__(self,id,value):
        self.list[id]=value

    def __delitem__(self,value):
        del self.list[value]

    def combGap(self,gap):
        gap = (gap*10)//13
        if gap < 1:
            return 1
        return gap
    

    def sort(self,comparison):
        
        lenght = len(self.list)
        gap = self.combGap(lenght)

        swapped = True

        while gap!=1 or swapped == 1:
            gap = self.combGap(gap)

            swapped = False

            for i in range (0,lenght-gap):
                if comparison==1:
                    if self.list[i]>self.list[i+gap]:
                        self.list[i],self.list[i+gap]=self.list[i+gap], self.list[i]
                        swapped=True
                if comparison==-1:
                    if self.list[i]<self.list(i+gap):
                        self.list[i],self.list[i+gap]=self.list[i+gap], self.list[i]
                        swapped=True

    def filter(self,function):
        for i in range (len(self.list)):
            if self.list[i]==function:
                self.list.pop(i)

    def printList(self):
        print (self.list)

Dat=Data([1,4,2,6,5,77,10])
Dat.sort(-1)
Dat.printList()