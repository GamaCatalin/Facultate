def prime (x):
    t=True
    for i in range (2,x//2+1):
        if x%i == 0:
            t=False
    return t        

n=int(input('Value='))
n=n+1
while prime(n)==False:
    n=n+1
print(n)
