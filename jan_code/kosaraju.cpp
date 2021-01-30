#include <bits/stdc++.h>

using namespace std;
stack<int> st;
vector<vector<int>> g;
vector<vector<int>> tg;
vector<int> vis;

void dfs(int node){
    vis[node] = true;
    for(int child:g[node]){
        if(vis[child] == false)
            dfs(child);
    }
    st.push(node);
}
void dfs2(int node){
    vis[node] = true;
    for(int child:tg[node]){
        if(vis[child] == false)
            dfs(child);
    }
}
int main(){
    int n,e;
    cin >> n >> e;
    g.resize(n+1);
    for(auto &v:g) v.clear();
    vis.resize(n+1,false);
    while(e--){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(vis[i] == false)
            dfs(i);
    }
    for(auto &v:tg) v.clear();
    vis.clear();
    vis.resize(n+1,false);
    for(int i=1;i<=n;i++){
        for(int x:g[i]){
            tg[x].push_back(i);
        }
    }
    int ans = 0;
    while(st.size()){
        int curr = st.top();
        if(vis[curr]==false){
            ans++;
            dfs2(curr);
        }
        st.pop();
    }
    cout << ans << endl;
    return 0;  
}