def perfect(x):
    s=0
    for j in range (1, x//2+1):
        if (x%j==0) :
            s=s+j
    if (s==x):
        return True
    return False

n=int(input('Value='))
d=0
t=True
while d==0:
    if n<=6:
        t=False
        d=1
    for i in range(n, 0, -1):
        if(perfect(i)==True):
            d=i
            break
if t==True:
    print (d)
else:
    print("It does not exist")
