#include <bits/stdc++.h>
#define int long long

using namespace std;
const int mx = 3*1e5;
const int mod = 4294967295;
int mx_level = 0;
int n,q;
vector<int> tree[mx+1];

vector<vector<int>> lvl;
vector<int> memo[mx+1];
int w[mx+1],par[mx+1],level[mx+1],vis[mx+1],ans[mx+1],till[mx+1],idx[mx+1];
bool known[mx+1];
int add(int a,int b){return (a+b)&mod;}
int mul(int a,int b){return (a*b)&mod;}
void dfs(int node,int p,int l,int s){
    till[node] = add(s,mul(w[node],w[node]));
    par[node] = p;
    vis[node] = 1;
    level[node] = l;
    mx_level = max(mx_level,l);
    for(int ch:tree[node]){
        if(!vis[ch]){
            dfs(ch,node,l+1,till[node]);
        }
    }
}
int query(int u,int v){
    int ans = 0;
    while(u!=v and !known[u]){
        ans = add(ans,mul(w[u],w[v]));
        u = par[u];
        v = par[v];
    }
    if(u==v)
        ans = add(ans,till[u]);
    else 
        ans = add(ans, memo[level[u]][idx[u]*lvl[level[u]].size() + idx[v]]);
    
    return ans;
}

main(){
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&w[i]);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%lld%lld",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,-1,0,0);
    lvl = vector<vector<int>> (mx_level+1);
    for(int i=1;i<=n;i++){
        lvl[level[i]].push_back(i);
    }

    //PRECOMPUTING
    int blk = sqrt(n);
    for(int i=0;i<=mx_level;i+=blk){
        int lv = i, sz = lvl[i].size();
        for(int j=i;j<=min(i+blk, mx_level); j++){
            if(lvl[j].size() < sz){
                sz = lvl[j].size();
                lv = j;
            }
        }
        int id = 0;
        for(int x:lvl[lv]){
            idx[x] = i;
            i++;
        }
        for(int x:lvl[lv]){
            for(int y:lvl[lv]){
                if(idx[x]<= idx[y]) 
                    memo[lv].push_back(query(x,y));
                else 
                    memo[lv].push_back(memo[lv][idx[y]*sz + idx[x]]);
            }
            known[x] = true;
        }

    }
    while(q--){
        int u,v;
        scanf("%lld%lld",&u,&v);
        printf("%lld\n",query(u,v));
    }

    return 0;
}