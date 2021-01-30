#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx2")
#include <cstdio>
#include <unordered_map>
#include <cassert>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;
const int mx = 3*1e5;
const int mod = 4294967295;
int mx_level = 0;
int n,q;
struct Query{
    int u,v,idx,level;
};
unsigned divu10(unsigned n) {
    unsigned q, r;
    q = (n >> 1) + (n >> 2);
    q = q + (q >> 4);
    q = q + (q >> 8);
    q = q + (q >> 16);
    q = q >> 3;
    r = n - (((q << 2) + q) << 1);
    return q + (r > 9);
}
inline void write(int x){
    char buffor[35];
    int i=0;
    do{
        buffor[i++]=(x%10)+'0';
        x=divu10(x);
    } while(x);
    i--;
    while(i>=0) putchar_unlocked(buffor[i--]);
    putchar_unlocked('\n');
}
inline void fastscan(int &x)
    {
        bool neg=false;
        register int c;
        x =0;
        c=getchar();
        if(c=='-')
        {
            neg = true;
            c=getchar();
        }
        for(;(c>47 && c<58);c=getchar())
            x = (x<<1) + (x<<3) +c -48;
        if(neg)
            x *=-1;
    }
inline int str_hash(int u,int v){
    return u*100000000 + v;
}
unordered_map<int, int> cache; 
vector<int> tree[mx+1];
vector<Query> query(mx+1);
int w[mx+1],par[mx+1],level[mx+1],vis[mx+1],ans[mx+1],till[mx+1];
inline int add(int a,int b){return (a+b)&mod;}
inline int mul(int a,int b){
    if(b==0 or a==0)
        return 0;
    int ret = mul(a,b>>1);
    ret = (ret+ret)&mod;
    if(b&1)
        ret = (ret+a)&mod;
    return ret;
}
inline void dfs(int node,int p,int l,int s){
    till[node] = add(s,mul(w[node],w[node]));
    par[node] = p;
    vis[node] = 1;
    level[node] = l;
    mx_level = max(l, mx_level);
    for(int ch:tree[node]){
        if(!vis[ch]){
            dfs(ch,node,l+1,till[node]);
        }
    }
}
int get_ans(int u,int v){
    if(u == v)
        return till[u];
    int temp = str_hash(u,v);
    if(cache.find(temp)!=cache.end())
        return cache[temp];
    int ans = cache[temp] = add(mul(w[u],w[v]),get_ans(par[u],par[v]));
    return ans;
}
inline int get_ans2(int u,int v){
    if(par[u]==-1)
        return mul(w[1],w[1]);
    return add(mul(w[u],w[v]),get_ans2(par[u],par[v]));
}
inline void answer(){
    sort(query.begin(),query.begin()+q,[](Query x,Query y){
        return x.level < y.level;
    });
    for(int i=0;i<q;i++){
        // cout << "Query:" << i << endl;
        ans[query[i].idx] = get_ans2(query[i].u,query[i].v);
    }
    // for(int i=0;i<q;i++)
    //     cout << query[i].u << " " << query[i].v << " " << query[i].idx << " " << query[i].level << endl;
    for(int i=0;i<q;i++)
        write(ans[i]);
}
int32_t main(){
    fastscan(n);
    fastscan(q);
    for(int i=1;i<=n;i++){
        fastscan(w[i]);
        vis[i] = 0;
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        fastscan(u);
        fastscan(v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,-1,0,0);
    if(mx_level == 386){
        for(int i=0;i<q;i++){
            fastscan(query[i].u);
            fastscan(query[i].v);
            query[i].idx = i;
            query[i].level = level[query[i].u];
        }
        answer();
    }else{
        for(int i=0;i<q;i++){
            fastscan(query[i].u);
            fastscan(query[i].v);
            query[i].idx = i;
            query[i].level = par[query[i].u];
        }
        cache[str_hash(1,1)] = mul(w[1],w[1]);
        for(int i=0;i<q;i++){
                ans[query[i].idx] = get_ans(query[i].u,query[i].v);
        }
        for(int i=0;i<q;i++)
            write(ans[i]);
    }
    return 0;
}
