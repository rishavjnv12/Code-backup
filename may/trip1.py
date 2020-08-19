#!/usr/bin/python3

visited=[0]*200002

def fun(cycles,final):
    for j in range(len(cycles)):
        for i in range(1,len(cycles[j]),2):
            final.append(cycles[j][0])
            final.append(cycles[j][i])
            final.append(cycles[j][i+1])
            
    return final


def find_cycle(a,start):
    global visited
    ans=[]
    ans.append(start)
    j=a[start]
    visited[start]=1
    while a[j]!=a[start]:
        visited[j]=1
        ans.append(j)
        j=a[j]
        
    visited[a[j]]=1
    return ans


for _ in range(int(input())):
    for i in range(len(visited)):
        visited[i] = 0
    n,k=map(int,input().split())
    ar=list(map(int,input().split()))
    ar=[0]+ar
    odd,even=[],[]
    ans=0
    final=[]
    for i in range(1,n+1):
        if visited[i]==0:
            temp=find_cycle(ar,i)
            # print(temp)
            if len(temp)%2==0:
                even.append(temp)
            else:
                odd.append(temp)   
                
    # print(odd)
    # print(even)   
    if len(even)%2==1:
        print(-1)
        continue
    # print(even)
    for i in range(0,len(even),2):
        final.append(even[i][0])
        final.append(even[i][1])
        final.append(even[i+1][0])
        ans=ans+1 
        temp=[]
        temp.append(even[i][0])
        for j in range(1,len(even[i+1])):
            temp.append(even[i+1][j])
        temp.append(even[i+1][0])
        for j in range(2,len(even[i])):
            temp.append(even[i][j])
        
  
        odd.append(temp)
    for i in range(len(odd)):
        ans = ans+ len(odd[i])//2
    
    final=fun(odd,final)
    # print(final)
    # print(final)
    print(ans)
    for i in range(0,len(final),3):
        print(str(final[i])+" "+str(final[i+1])+" "+str(final[i+2]))
    
            
        
        
        