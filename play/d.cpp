#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    vector<int> g(n+1);
    for(int i=1;i<=n;i++)
        cin >> g[i];
    bool all_equal = true;
    for(int i =1;i<n;i++)
        if(g[i]!=g[i+1]){
            all_equal = false;
            break;
        }
    if(all_equal){
        printf("NO\n");
        return;
    }
    printf("YES\n");
    unordered_map<int,vector<int>> mp;
    for(int i=1;i<=n;i++)
        mp[g[i]].push_back(i);
    
    vector<pair<int,vector<int>>> v;
    for(auto pp:mp)
        v.push_back(pp);
    int sz = v[0].second.size();
    int start = v[0].second[0];
    for(int i = 1;i < v.size();i++){
        for(int x:v[i].second)
            printf("%d %d\n",start,x);
    }
    int to = v[1].second[0];
    for(int i = 1;i<sz;i++)
        printf("%d %d\n",v[0].second[i],to);

}

int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}