def Lucky(n):
    if (n % 10 != 4 or n % 10 != 7):
        return False
    else :
        if(n > 0):
            Lucky(n // 10)
    return True


k=input("Input number: ")

if(Lucky(int(k))==True):
    print("Lucky")
else:
    print("Not")