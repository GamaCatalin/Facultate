from Services import *



def show_phones():
    for i in range(0,len(price)):
        print(manufacturer[i]+" "+model[i]+" "+str(price[i]))


def start():
    while True:
        print()
        print(80*"*")
        print(30*" "+"Menu")
        print()
        print("1.Add a phone")
        print("2.Show phones")
        print("3.Find a phone by manufacturer")
        print("4.Increase the price by an amount")
        print("5.increase the price by a percentage")
        print()
        print("0.Exit")
        print(80*"*")
        print()

        command=input("Enter a command: ")
        print()

        if command=="1":
            i=input("Enter phone specifications: ")
            add_phone(i)
        elif command=="2":
            show_phones()
        elif command=="3":
            i=input("Enter the manufacturer you want to find: ")
            find_manf(i)        
        elif command=="4":
            i=input("Enter the manufacturer, model and amount you want to increase the price: ")
            increase_amount(i)
        elif command=="5":
            i=input("Enter the percent you want to increase the prices by: ")
            increase_percent(i)
        elif command=="0":
            break           
        else:
            print()
            print("Wrong command") 


populate_phones()
start()