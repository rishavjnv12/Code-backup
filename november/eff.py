mod = 4294967295
mx = int(1e5+1)
n,q = map(int,input().split())
w = [0] + list(map(int,input().split()))
tree = [[] for i in range(mx)]
par = [0 for i in range(mx)]
# level = [0 for i in range(mx)]
vis = [False for i in range(mx)]
till = [0 for i in range(mx)]


def dfs(node,p,l,s):
    till[node] = (s+((w[node]*w[node])&mod))&mod
    par[node],vis[node],level[node] = p,True,l
    for ch in tree[node]:
        if vis[ch] is False:
            dfs(ch,node,l+1,till[node])



queries = []
for i in range(n-1):
    u,v = map(int,input().split())
    tree[u].append(v)
    tree[v].append(u)

dfs(1,-1,0,0)
for i in range(q):
    u,v = map(int,input().split())
    queries.append([u,v])

def get_ans(u,v):
    if u is v:
        return till[u]
    return ((w[u]*w[v])+get_ans(par[u],par[v]))&mod

for q in queries:
    print(get_ans(q[1],q[2]))
