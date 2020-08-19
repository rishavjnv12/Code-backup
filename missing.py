for _ in range(int(input())):
    hor={}
    ver={}
    n=int(input())
    total=4*n-1
    for i in range(total):
        x,y=map(int,input().split())
        try:
            hor[x]=hor[x]+1
        except:
            hor[x]=1
        
        try:
            ver[y]=ver[y]+1
        except:
            ver[y]=1
            
    
    ansx=0
    ansy=0
    for key in hor:
        if hor[key]%2:
            ansx=key
            break
            
    for key in ver:
        if ver[key]%2:
            ansy=key
            break
      
    # print(hor)
    # print(ver)      
    print(str(ansx)+" "+str(ansy))
