import numpy as np

def spiral(n):
    if n==1:
        return [[1]]
    a,temp=[],[]
    for i in range(n):
        for j in range(n):
            temp.append(0)
        a.append(temp)
        temp=[]

    for i in range(1,n+1):
        a[0][i-1]=i

    curr=n
    step=n-1
    x,y=0,n-1
    while True:
        for i in range(step):
            x+=1
            curr+=1
            a[x][y]=curr

        for i in range(step):
            y-=1
            curr+=1
            a[x][y]=curr

        step-=1
        if step==0:
            break

        for i in range(step):
            x-=1
            curr+=1
            a[x][y]=curr

        for i in range(step):
            y+=1
            curr+=1
            a[x][y]=curr

        step-=1
        if step==0:
            break



    return a


ans=np.array(spiral(7))
print(ans)