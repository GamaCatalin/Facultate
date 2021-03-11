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
        return None
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
        
def sublist(List):
    List.prim=List.prim.urm
    return List

def firstElement(List):
    return List.prim.e

def determine(List):
    if(List.prim == None):
        return 0
    element=firstElement(List)
    if(element % 2 == 0):
        return element + determine(sublist(List))
    else:
        return -1*element + determine(sublist(List))



'''
program pentru test
'''
        
def main():
    list = creareLista()
    #tipar(list)

    print(determine(list))
    
main() 