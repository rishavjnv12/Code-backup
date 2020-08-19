for _ in range(int(input())):
    n,k=map(int, input().split())
    a=list(map(int,input().split()))
    dp=[]
    for i in range(n):
        temp=[]
        for j in range(n):
            temp.append(0)
        dp.append(temp)
    fam=[]
    for i in range(102):
        fam.append(0)
    
    for i in range(n):
        for j in range(i,n):
            if j==0:
                fam[a[j]]+=1
            else:
                dp[i][j]=dp[i][j-1]
                if fam[a[j]==1]:
                    dp[i][j]+=2
                elif fam[a[j]>=2]:
                    dp[i][j]+=1
        fam=[]
        for i in range(102):
            fam.append(0)

    dp2=[]
    for i in range(101):
        temp=[]
        for j in range(n+2):
            temp.append(0)
        dp2.append(temp)
    
    for i in range(1,n+1):
        dp2[1][i]=dp[0][i-1]
    
    for i in range(2,101):
        for j in range(2,n+1):
            curr=10000000000
            for k in range(1,j):
                curr=min(curr,dp2[i-1][k]+dp[k][j-1])
            dp2[i][j]=curr
        
    res=10000000000
    for i in range(1,101):
        res=min(res,i*k+dp2[i][n])
    print(res)
