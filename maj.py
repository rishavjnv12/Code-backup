def majority(a):
    maj=a[0]
    count=1
    for i in a[1:]:
        if i==maj:
            count=count+1
        else:
            count=count-1
        
        if count==0:
            maj=i
            count=1
    
    if a.count(maj) > len(a)/2:
        return maj
    
    return -1

a=[1,1,2,1,1,1,2,1,3]
print(majority(a))
