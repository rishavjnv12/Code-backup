import math
import os

vect=[0]*500

def setBitNumber(n):
     k=int(math.log(n,2))
     return 2**k
def firstSetBit(n):
    j=math.log2(n&(-n))+1
    return 2**j


def result(max1,max2,z1,z2):
     if(max1>max2):
         return z1
     elif(max2>max1):
         return z2
     else:
        return(min(z1,z2))


t=int(input())
while(t>0):
    t-=1
    for i in range(len(vect)):
        vect[i] = 0
    x,y,l,r=map(int,input().split())
    w=x|y
    w=int(w)
    max1=0
    max2=0
    z1=0
    z2=0
    if ((w >=l) and (w<=r)):
        # print(w)
        # print("here")
        continue
    elif w>r:
        while(w>=r):
            d=setBitNumber(w)
            #print(x)
            w=w-d
            v=0
            v=w
            #v=int(v)
            u=0
            u=w
            #u=int(u)
            while(v>=l):
                d=setBitNumber(w)
                if ((v >=l) and (v<=r)):
                    z=(x & v)*(y & v)
                    if(z>max1):
                        max1=z
                        z1=v
                v=v-d
            while(u>=l):
                d=firstSetBit(w)
                z=(x & int(u))*(y & int(u))
                if(z>max2):
                    max2=z
                    z2=v
                u=u-d
    print(str(max1)+" "+str(max2)+" "+str(z1)+" "+str(z2));
    h=result(max1,max2,z1,z2)
    print(h)
                    
            
       # print('inwhile')
   # print(w)
   # else:
        
   
        
        
        
        
    
