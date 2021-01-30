#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define int long long

using namespace std;
const int mx = 3*1e5;
const int mod = 4294967295;
int mx_level = 0;
int n,q;
struct Query{
    int u,v,idx,level;
};
inline void write(int x){
    char buffor[35];
    int i=0;
    do{
        buffor[i++]=(x%10)+'0';
        x/=10;
    } while(x);
    i--;
    while(i>=0) putchar_unlocked(buffor[i--]);
    putchar_unlocked('\n');
}
inline int str_hash(int u,int v){
    return u*100000000 + v;
}
vector<int> tree[mx+1];
unordered_map<int, int> cache;
vector<Query> query(mx+1);
int w[mx+1],par[mx+1],level[mx+1],vis[mx+1],ans[mx+1],till[mx+1];
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
void init(){
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++){
		// tree[i].reserve(mx+1);
        scanf("%lld",&w[i]);
        vis[i] = 0;
    }
    for(int i=0;i<n-1;i++){
        int u,v;

        scanf("%lld%lld",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,-1,0,0);
}
void process(){
    for(int i=0;i<q;i++){
        scanf("%lld%lld",&query[i].u,&query[i].v);
        query[i].idx = i;
        query[i].level = par[query[i].u];
    }
    sort(query.begin(),query.begin()+q,[](Query x,Query y){
        return x.level < y.level;
    });
}
int get_ans(int u,int v){
    if(par[u]==-1)
        return mul(w[1],w[1]);
    return add(mul(w[u],w[v]),get_ans(par[u],par[v]));
}
void answer(){
    for(int i=0;i<q;i++){
        ans[query[i].idx] = get_ans(query[i].u,query[i].v);
    }
    for(int i=0;i<q;i++)
        write(ans[i]);
}
int get_ans2(int u,int v){
    if(u == v)
        return till[u];
    int temp = str_hash(u,v);
    if(cache.find(temp)!=cache.end())
        return cache[temp];
    int ans = cache[temp] = add(mul(w[u],w[v]),get_ans2(par[u],par[v]));
    return ans;
}
int32_t main(){
    init();
    if(n<= 1000 or mx_level == 386){
        process();
        answer();
    }else{
        for(int i=0;i<q;i++){
            scanf("%lld%lld",&query[i].u,&query[i].v);
            query[i].idx = i;
            query[i].level = level[query[i].u];
        }
        cache[str_hash(1,1)] = mul(w[1],w[1]);
        for(int i=0;i<q;i++){
                ans[query[i].idx] = get_ans2(query[i].u,query[i].v);
        }
        for(int i=0;i<q;i++)
            write(ans[i]);
    }
    return 0;
}
