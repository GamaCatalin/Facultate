a=int(input('First value= '))
b=int(input('Second value= '))
x=[0,0,0,0,0,0,0,0,0]
y=[0,0,0,0,0,0,0,0,0]
t=True
for i in range (9):
    x[i]=0
    y[i]=0
while a>0:
    x[a%10]=1
    a=a//10
while b>0:
    y[b%10]=1
    b=b//10
for i in range(9):
    n=int(x[i])
    m=int(y[i])
    if (m!=n):
        t=False

if (t==True):
    print("Property P is valid")
else:
    print("Property P is not valid")
