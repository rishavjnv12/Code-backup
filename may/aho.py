mydic={}
MAXS=1000
MAXC=26
out=[0]*MAXC
f=[0]*MAXC
g=[[0]*MAXC]*MAXS
alph={}
# # def init():
#     for i in range('a',27):
#         print(i)
        
        
def build_matching_machine():
    global f
    global out
    global g
    global mydic

    for i in range(len(out)):
        out[i]=0
        
    g=[[-1]*26]*1000
        
    states=1
    counter=0
    for i in mydic:
        curr_state=0
        for j in range(len(i)):
            ch=ord(i[j])-ord('a')
            if g[curr_state][ch] == -1:
                g[curr_state][ch] = states
                states=states+1
            curr_state=g[curr_state][ch]
            
        out[curr_state] = out[curr_state] | (1 << counter)
    
    for i in f:
        i=-1

    for ch in range(26):
        if g[0][ch] == -1:
            g[0][ch] = 0
    
    q=[]
    for ch in range(26):
        if g[0][ch] != 0:
            f[g[0][ch]] = 0
            q.append(g[0][ch])
    print(q)
    while len(q)!=0:
        state=q[0]
        q.pop(0)
        for ch in range(27):
            print(q)
            if g[state][ch]!=-1:
                failure=f[state]
                while g[failure][ch] ==-1:
                    failure=f[failure]
                
                failure=g[failure][ch]
                f[g[state][ch]]=failure
                out[g[state][ch]]=out[g[state][ch]] | out[failure]
                q.append(g[state][ch])
                try:
                    q.remove(0)
                except:
                    print(q)
                
    return states

def findnextstae(current_state,next_input):
    global g
    global f
    answer=current_state
    ch=ord(next_input)-ord('a')
    while g[answer][ch] == -1:
        answer = f[answer]
    
    return g[answer][ch]

def search_word(text):
    global f
    global out
    global g
    global mydic
    ans=0
    k=mydic.size()
    curr_state=0
    for i in range(len(text)):
        curr_state=findnextstae(curr_state,text[i])
        if out[curr_state] == 0:
            continue
        counter=0
        for j in mydic:
            if out[curr_state] & (1<<counter):
                ans = ans + mydic[j]
                counter = counter + 1                
    return ans

    
            
        
    
for _ in range(int(input())):
    a=input()
    b=input()
    # init()
    q=int(input())
    mydic.clear()
    for i in range(q):
        temp,val=input().split()
        intval=int(val)
        mydic[temp]=intval
        
    print(mydic)
    build_matching_machine()