0,0
0,1
0,2
1,2
2,2

import numpy as np

def fun(a):
    ans,temp=[],[]
    n=len(a)-1
    if n==0:
        return a
    temp.append(a[0][0])
    i,j=0,0
    start_i,start_j=0,0
    while True:
        try:
            assert j-1 >= 0
            assert i+1 <=n
            temp.append(a[i+1][j-1])
            i=i+1
            j=j-1
        except:
            ans.append(temp)
            temp=[]
            if start_j!=n:
                start_j=start_j+1
            else:
                start_i=start_i+1
            
            i=start_i
            j=start_j
            temp.append(a[i][j])
        if i==n and j==n:
            ans.append([a[i][j]])
            break

    return ans

a=np.arange(25).reshape(5,5)

print(a)

print(fun(a))