for _ in range(int(input())):
    text=input()
    pat=input()

    t,p=dict(),dict()
    for i in pat:
        if i in p:
            p[i]+=1
        else:
            p[i]=1

    for i in text:
        if i in t:
            t[i]+=1
        else:
            t[i]=1

    for i in p:
        t[i]-=p[i]

    ans=''
    ans2=''
    for ch in range(ord('a'),ord(pat[0])+1):
        if chr(ch) in t:
            for x in range(t[chr(ch)]):
                ans+=chr(ch)

    for ch in range(ord('a'),ord(pat[0])):
        if chr(ch) in t:
            for x in range(t[chr(ch)]):
                ans2+=chr(ch)
    
    ans2+=pat
    ans+=pat
    for ch in range(ord(pat[0])+1,ord('z')+1):
        if chr(ch) in t:
            for x in range(t[chr(ch)]):
                ans+=chr(ch)
    
    for ch in range(ord(pat[0]),ord('z')+1):
        if chr(ch) in t:
            for x in range(t[chr(ch)]):
                ans2+=chr(ch)

    if ans<ans2:
        print(ans)
    else:
        print(ans2)
        
    
    