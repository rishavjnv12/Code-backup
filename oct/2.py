for _ in range(int(input())):
    n,k,x,y=map(int,input().split())
    st = set()
    curr = x
    found = False
    while True:
        if curr is y:
            found = True
            break
        if curr in st:
            break
        st.add(curr)
        curr=(curr+k)%n

    if found:
        print('YES')
    else:
        print('NO')