class Nod:
    def __init__(self, e):
        self.e = e
        self.urm = None
    
class Lista:
    def __init__(self):
        self.prim = None
        

'''
crearea unei liste din valori citite pana la 0
'''
def creareLista():
    lista = Lista()
    lista.prim = creareLista_rec()
    return lista

def creareLista_rec():
    x = int(input("x="))
    if x == 0:
        return #None
    else:
        nod = Nod(x)
        nod.urm = creareLista_rec()
        return nod
    
'''
tiparirea elementelor unei liste
'''
def tipar(lista):
    tipar_rec(lista.prim)
    
def tipar_rec(nod):
    if nod != None:
        print (nod.e)
        tipar_rec(nod.urm)

def isEmpty(List):
    if List.prim == None:
        return True
    return False
        
def sublist(List):
    #print ("Sublist:" + str(List.prim.e))
    List.prim=List.prim.urm
    return List

def firstElement(List):
    #print("firstElement: " + str(List.prim.e))
    return List.prim.e

def addElement(List,element):
    node=Nod(element)
    node.urm=List.prim
    List.prim=node
    return List


def difference(currentElement,list1,list2,dList,bufferList,isSearching):
    #print(currentElement)
    if (isEmpty(list1) and isSearching==False):
        #print ("case 1")
        return dList
    if(currentElement==None):
        #print ("case 2")
        return difference(firstElement(list1),sublist(list1),list2,dList,bufferList,True)
    if (isEmpty(list1) and isEmpty(list2)):
        #print ("case 3")
        return difference(currentElement,list1,list2,addElement(dList,currentElement),bufferList,False)
    if (isEmpty(list2)):
        #print ("case 4")
        return difference(firstElement(list1),sublist(list1),bufferList,addElement(dList,currentElement),list2,True)
    checkElement=firstElement(list2)
    if (currentElement==checkElement):
        #print ("case 5")
        return difference(firstElement(list1),sublist(list1),list2,dList,bufferList,False)
    if (isSearching==False and isEmpty(bufferList)==False):
        #print ("case 6")
        return difference(currentElement,list1,addElement(list2,firstElement(bufferList)),dList,sublist(bufferList),False)
    if (isSearching==False and isEmpty(bufferList)==True):
        #print ("case 7")
        return difference(currentElement,list1,list2,dList,bufferList,True)
    if (isSearching and isEmpty(list2)==False):
        #print ("case 8")
        return difference(currentElement,list1,sublist(list2),dList,addElement(bufferList,checkElement),True)

'''
program pentru test
'''
        
def main():
    print("First list: ")
    list1 = creareLista()
    print("Second list: ")
    list2 = creareLista()
    dList=Lista()
    bufferList=Lista()
    tipar(difference(None,list1,list2,dList,bufferList,True))

    
main() 