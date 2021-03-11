def show_list(RList,IList):

    '''
    Calls the print function for the whole list
    
    '''
    


    
    x=0
    y=len(RList)

    print()
    print_sequence(x,y,RList,IList)


        
def clear_list(RList,IList):
    '''
    Clears the list of numbers

    '''

    RList.clear()
    IList.clear()

    print()



    

def pop_numbers(RList,IList):

    '''
    Populates a list of test numbers
    
    '''
    
    TempR=[-3,2,7,-3,10,-10,-10,30,-21,8]
    TempI=[5,10,0,9,10,10,10,0,6,-1]    

    for i in TempR:
        RList.append(i)
    for i in TempI:
        IList.append(i)

    print()
    

def add_number(RList,IList):

    '''
    Adds a number to the list
    
    '''

    print()
    
    Rpart=[]
    Ipart=[]
    x=input("Insert a complex number: ")
    lenght=len(x)
    if x[lenght-1]!='i':
        RList.append(int(x))
        IList.append(0)
    else:
        Rpart.append(x[0])
        for i in range(1,lenght):
            try:
                k=int(x[i])
                Rpart.append(k)
            except ValueError:
                sign_pos=i
                break
        for i in range(sign_pos,lenght-1):
            if(x[i]!="+"):
                Ipart.append(x[i])
        R=""
        I=""
    
        for i in Rpart:
            R+=i

        for i in Ipart:
            I+=i
            
        RList.append(int(R))
        IList.append(int(I))

        print()


def print_sequence(x,y,RList,IList):

    '''
    Prints the sequence of numbers given 2 pointers
    
    '''
    
    
    for i in range(x,y):

        if(RList[i]==0):
            print((IList[i]),'i')
        elif(IList[i]>0):
            print((RList[i]),'+',(IList[i]),'i')
        elif(IList[i]==0):
            print(RList[i])    
        else:
            print((RList[i]),'-',abs((IList[i])),'i')
        

        



def prop_5(RList,IList):

    '''
    Finds the largest sequence of real numbers
    
    '''
    
    lenght=len(RList)
    k=0
    l=0
    x=0
    y=0
    z=0
    for i in range(0,lenght):
        if (IList[i]==0):
            if (l==0):
                z=i
            l=l+1
        else:
            if(l>k):
                x=z
                y=i
                k=l
            l=0
    if(IList[lenght-1]==0 and l>=k):
        x=z
        y=lenght
    print()

    print_sequence(x,y,RList,IList)    



def prop_6(RList,IList):

    '''
    Finds the largest sequence of distinct numbers
    
    '''
    
    lenght=len(RList)-1
    x=0
    y=0
    z=0
    k=0
    l=0
    for i in range(0, lenght):
        if(RList[i]==RList[i+1] and IList[i]==IList[i+1]):
            if(l>k):
                x=z
                y=i+1
                k=l
            l=0
        else:
            if(l==0):
                z=i
            l=l+1    

    print()

    print_sequence(x,y,RList,IList)


def prop_1(RList,IList):

    '''
    Finds the largest sequence of numbers that have an increasingly real part
    
    '''

    lenght=len(RList)-1
    k=0
    l=0
    x=0
    y=0
    z=0
    for i in range(0,lenght):
        if (RList[i+1]>RList[i]):
            if (l==0):
                z=i
            l=l+1
        else:
            if(l>k):
                x=z
                y=i+1
                k=l
            l=0
    if(RList[lenght]>RList[lenght-1] and l>=k):
        x=z
        y=lenght+1
        


    print()

    print_sequence(x,y,RList,IList)    
     


            

def menu():

    '''
    Prints a menu
    
    '''
    
    while True:
        print (80*"*")
        print("Menu: ")
        print("1. Show list")
        print("2. Populate with base numbers")
        print("3. Add a number")
        print("4. Clear the list")
        print("5. Check for real numbers")
        print("6. Check for distinct numbers")
        print("7. Check for numbers with an increasingly real part")
        print()
        print("0. Exit")
        print (80*"*")
        print()
        choice=int(input(''))
        if choice==1:
            show_list(RList,IList)
        elif choice==2:
            pop_numbers(RList,IList)
        elif choice==3:
            add_number(RList,IList)
        elif choice==4:
            clear_list(RList,IList)
        elif choice==5:
            prop_5(RList,IList)
        elif choice==6:
            prop_6(RList,IList)
        elif  choice==7:
            prop_1(RList,IList)



            
        elif choice==0:
            return
        else:
            print("Unavailable option")
            


        
        print()
        print()



RList=[]
IList=[]
menu()

