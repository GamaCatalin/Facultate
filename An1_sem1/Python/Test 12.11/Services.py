manufacturer=[]
model=[]
price=[]




def add_phone(phn):
    '''
        Adds a phone to the list if all requirements are met
    '''

    phone=phn.split()

    t=1

    if(len(phone)>3):
        for i in range(1,len(phone)-2):
            phone[1]=phone[1]+" "+phone[i+1]
        phone[2]=phone[len(phone)-1]

    for i in manufacturer:
        if i == phone[1]:
            t=0
            

    if t==0:
        print("Model is already in the list")
    elif len(phone[0])<3:
        print("Manufacturer field is less than 3 characters long")
    elif len(phone[1])<3:
        print("Model field is less than 3 characters long")
    elif len(phone[2])<3:
        print("Price field is less than 3 characters long")
    else:
        manufacturer.append(phone[0])
        model.append(phone[1])
        price.append(phone[2])
        price[len(price)-1]=int(price[len(price)-1])


def test_add():

    phone="Huawey P20 Pro 10"

    tphone=phone.split()

    if(len(tphone)>3):
        for i in range(1,len(tphone)-2):
            tphone[1]=tphone[1]+" "+tphone[i+1]
        tphone[2]=int(tphone[len(tphone)-1])

    assert tphone[2]>99, "Price too low"



def populate_phones():
    '''
        Populates the list with 5 phone models at aplication start
    '''
    pop_list=["Samsung Note 9 3000","Apple Iphone 10 7000","Samsung A10 6000","Huawey Mate 10 2000","Apple Iphone 8 5000"]

    for i in pop_list:
        add_phone(i)

def find_manf(manf):
    '''
        Finds the given manufacturer in the phone list
    '''
    pass

    for i in range(0,len(manufacturer)-1):
        if manf==manufacturer[i]:
            print(manufacturer[i]+" "+model[i]+" "+str(price[i]))
    

def increase_amount(inc):
    '''
        Increases the model price by an amount
    '''
    increase=inc.split()

    if(len(increase)>3):
        for i in range(1,len(increase)-2):
            increase[1]=increase[1]+" "+increase[i+1]
        increase[2]=increase[len(increase)-1]

    t=0

    for i in range (0, len(price)-1):
        if manufacturer[i]==increase[0] and model[i]==increase[1]:
            price[i]=price[i]+int(increase[2])
            t=1

    if t==0:
        print("Manufacturer/model not found")


def increase_percent(n):
    ''' 
        Increases the price of all phones by a given percent
    '''

    n=int(n)
    if n < -50 or n > 100:
        print("Percent value is not in the required bounds (-50...100)")
    else:
        for i in range (0, len(price)-1):
            price[i]=int(price[i]+((price[i]/100)*n))

    
