#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<string> g;
bool vis[1001][1001];
void dfs(int i,int j){
    if(i==0 or i>n or j==0 or j>m or g[i][j] == '#' or vis[i][j])
        return;
    vis[i][j] = true;
    dfs(i-1,j);
    dfs(i+1,j);
    dfs(i,j-1);
    dfs(i,j+1);
}
int main(){
    cin >> n >> m;
    g.resize(n+1," ");
    for(int i=1;i<=n;i++){
        string temp;
        cin >> temp;
        g[i]+=temp;
    }
    memset(vis,false,sizeof vis);
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]=='.' and vis[i][j]==false){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}