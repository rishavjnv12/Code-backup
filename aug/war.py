for _ in range(int(input())):
    h,p=map(int,input().split())
    if h <= p:
        print(1)
        continue

    while True:
        # attck 
        h-=p
        p//=2

        if p==0:
            if h==0:
                print(1)
            else:
                print(0)
            
            break

        if h<=p:
            print(1)
            break