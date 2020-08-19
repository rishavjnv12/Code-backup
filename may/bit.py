from math import floor,log2

def fun(x,y,z):
    return (x&z)*(y&z)

def fun2(v,x,y,l,r):
    ans=fun(x,y,v[0])
    idx=v[0]
    for i in range(1,len(v),1):
        temp=fun(x,y,v[i])
        if temp > ans:
            ans=temp
            idx=v[i]
        elif fun(x,y,v[i])==ans and v[i]<idx:
            ans=temp
            idx=v[i]
    
    return idx
    


for _ in range(int(input())):
    x,y,l,r=map(int,input().split())
    if x==0 or y==0:
        print(l)
        continue

    if l==r:
        print(r)
        continue
        
    ans=x|y

    # print(ans)
    if ans <=r:
        print(ans)
        continue
    
    if r>0:
        max_bit=floor(log2(r))
    else:
        max_bit=0
    
    if ans==0:
        print(l)
        continue
        
    if ans>0:
        ans_bit=floor(log2(ans))
    else:
        ans_bit=0

    i=ans_bit
    while i>max_bit:
        check=(1<<i)
        if (ans & check) != 0:
            ans = ans - check
        
        i=i-1
    
    if ans <=r:
        # print(ans)
        # print("Hello")
        if ans&x==0 or ans&y==0 :
            print(0)
        else:
            print(ans)
        continue
    
    pos=[0]
    i=max_bit
    for i in range(max_bit,-1,-1):
        check=(1<<i)
        if((r&check)!=0  and (ans&check)!=0):
            temp=ans-check
            if temp<=r :
                pos.append(temp)
        elif (r&check)==0  and (ans&check)!=0:
            ans = ans - check
            if ans <= r:
                pos.append(ans)         
    print(fun2(pos,x,y,l,r))
    # print(pos)