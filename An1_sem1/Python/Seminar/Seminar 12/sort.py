'''
merge sort
    -split the list into halves
    -sort the halves
    -merge the halves (merge=interclasare)

'''

def merge(left,right):
    res=[]
    while len(left)>0 and len(right)>0:
        if left[0] > right[0]:
            #res.append(right[j])
            res.append(right.pop(0))
        else:
            #res.append(left[i])
            res.append(left.pop(0))
        
        
    res.extend(left) # take each element of left[i:] and append it to res
    #res.append(left[i:]) # adds the left[i:] list as the final element of res
    res.extend(right)

    return res


def mergeSort(data):
    if len(data) == 1:
        return data     
    m = len(data) // 2
    right = mergeSort(data[:m])
    left = mergeSort(data[m:])
    return merge(left,right)

'''
insert sort
    -
'''

def bs(data,val):
    if len(data) == 1:
        if data[0] == val:
            return 0 
        else:
            return 1
    
    m = len(data) // 2

    if data[m] < val:
        return m + bs(data[m:],val)
    else:
        return bs(data[:m],val)


def insertSort(data):
    for i in range (1,len(data)):
        data.insert(bs(data[0:i],data[i]),data[i])
        data.pop(i+1)

        # for j in range (i):
        #     if data[i] <= data[j]:
        #         data.insert(j,data[i])
        #         data.pop(i+1)
    return data











import random

data = list(range(10))
random.shuffle(data)
print (data)
data = insertSort(data)
print (data)