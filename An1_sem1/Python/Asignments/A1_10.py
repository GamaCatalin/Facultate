n=int(input('Value='))
V= []
while n>0 :
    V.append(n%10)
    n=n//10
for i in range (0, len(V)):
    n=n*10+V[i]

print(n)    
