mx = 100001
mod = 4294967295
tree = [[] for i in range(mx)]
till = [0 for i in range(mx)]
vis = [0 for i in range(mx)]
par = [0 for i in range(mx)]
level = [0 for i in range(mx)]
cache = dict()
def dfs(node,p,l,s):
    till[node] = (s+(w[node]*w[node]))&mod
    par[node] = p
    vis[node] = 1
    level[node] = l
    for ch in tree[node]:
        if vis[ch] is 0:
            dfs(ch,node,l+1,till[node])

def str_hash(u,v):
    return str(u)+" "+str(v)

def get_ans(u,v):
    if u == v:
        return till[u]
    temp = str_hash(u,v)
    ans = 0
    if temp in cache:
        return cache[temp]
    else:
        ans = cache[temp] = ((w[u]*w[v])+get_ans(par[u],par[v]))&mod
        # except:
        #     print(u,v,len(w),len(par))
    return ans



n,q = map(int,input().split())
w = [0] + list(map(int,input().split()))
for i in range(n-1):
    u,v = map(int,input().split())
    tree[u].append(v)
    tree[v].append(u)
dfs(1,-1,0,0)
# for i in range(1,n+1):
#     print(till[i])

for i in range(q):
    u,v = map(int,input().split())
    print(get_ans(u,v))