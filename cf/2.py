def test():
    x1,y1,z1=map(int,input().split())
    x2,y2,z2=map(int,input().split())

    sum=0
    if z2>x1:
        if z2-x1 > z1 :
            sum -= 2 *(z2-x1-z1)
        else:
            if z1-z2+x1 > y2:
                sum+=2*y2
            else:
                sum+=2*(z1-z2+x1)
    else:
        if z1 > y2:
            sum+=2*y2
        else:
            sum+=2*z1

    print(sum)


for _ in range(int(input())):
    test()