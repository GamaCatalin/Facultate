n=int(input("Enter n: "))
print("Enter the list with {} elements: ".format(n))
nList=[]
temp=input()
Temp=temp.split()
for i in Temp:
    nList.append(int(i))

def backtrack(List,start,end,div):
    if start==end:
        return 0
    summ=0
    for i in range (0,len(List)):
        summ+=List[i]
    if summ%div==0 and len(List)>0:
        print(List)
    if start<end:
        for i in range(start,end):
            List.append(nList[i])
            backtrack(List,start+1,end,div)
            List.pop()
List=[]
backtrack(List,0,n,n)

