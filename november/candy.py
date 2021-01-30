mod = int(1e9+7)
def add(a,b):
    return ((a%mod)+(b%mod))
def mul(a,b):
    return ((a%mod)*(b%mod))

def get_idx(r,n):
    if r%n is 0:
        prev = r//n - 1
        return prev,n-1
    else:
        prev = r//n
        return prev,r%n-1


def special(a):
    q = int(input())
    for i in range(q):
        x = int(input())
        print(x%mod)


def single(a):
    if a[0] is 1:
        special(a)
    else:
        preq = 0
        if a[0]%2==0:
            preq = a[0]-1
        else:
            preq = a[0]
        q = int(input())
        for i in range(q):
            x = int(input())
            ans = mul(preq,x-1)
            ans = add(ans,a[0])
            print(ans)

def first_one(a):
    n = len(a)
    q = int(input())
    for i in range(q):
        x = int(input())
        if(x%n):
            print(add(x//n,1)%mod)
        else:
            print((x//n)%mod)


def last_one(a):
    n = len(a)
    preq = 1
    for i in range(n-1):
        if a[i]%2:
            preq = add(preq,a[i]-1)
        else:
            preq = add(preq,a[i])
    rem = [0 for i in range(n)]
    curr = 0
    for i in range(n):
        x = a[i]
        curr = add(curr,x)
        rem[i] = curr 
        if x%2:
            curr-=1
            if curr < 0:
                curr+=mod
    
    q = int(input())
    for i in range(q):
        r = int(input())
        prev,idx = get_idx(r,n)
        ans = mul(prev,preq)
        ans = add(ans,rem[idx])
        print(ans)


def no_one(a):
    n = len(a)
    preq = 0
    for i in range(n):
        x = a[i]
        if i != -1:
            if x%2:
                x-=1
            preq = add(preq,x)
        else:
            if x%2 is 0:
                x-=1
            preq = add(preq,x)
    
    rem = [0 for i in range(n)]
    curr = 0
    for i in range(n):
        curr = add(curr,a[i])
        rem[i] = curr
        if a[i]%2:
            curr-=1
            if curr < 0:
                curr+=mod
    q = int(input())
    for i in range(q):
        r = int(input())
        prev,idx = get_idx(r,n)
        ans = mul(prev,preq)
        ans = add(ans,rem[idx])
        print(ans)

def yes_one(a):
    q = int(input())
    for i in range(q):
        print(-1)


def general(a):
    n = len(a)
    one_idx = -1
    for i in range(n):
        if a[i] is 1:
            one_idx = i
            break
    if one_idx is -1:
        no_one(a)
    else:
        yes_one(a,one_idx)
        








for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    if len(a) is 1:
        single(a)
    elif a[0] is 1:
        first_one(a)
    elif a[-1] is 1:
        last_one(a)
    else:
        general(a)
            

