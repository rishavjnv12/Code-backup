#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>> g;
vector<bool> vis;
vector<int> ppp;
int cnt = 0;
void dfs(int i){
    cnt++;
    vis[i] = true;
    for(int ch:g[i]){
        if(vis[ch]==false)
            dfs(ch);
    }
}
int find(){
    int a_sum = accumulate(ppp.begin(),ppp.end(),0LL);
    int a_sum_sq = a_sum*a_sum;
    int isq = 0;
    for(int x:ppp)
        isq+=(x*x);
    return (a_sum_sq-isq)/2;
}
int32_t main(){
    int n,m;
    cin >> n >> m;
    g.resize(n+1);
    vis.resize(n+1,false);
    while(m--){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            cnt = 0;
            dfs(i);
            ppp.push_back(cnt);
        }
    }
    int ans = find();
    cout << ans << endl;
    return 0;
}