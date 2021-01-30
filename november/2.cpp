#include <bits/stdc++.h> 
const int mod = 1e9+7;
const int mx = 4*1e6;
using namespace std;
vector<bool> prime(mx+1,true);
vector<int> p;
void init(){
    prime[1]=false;
    prime[2]=true;
    for(int i=2;i*i<=mx;i++){
        if(prime[i]){
            for(int j=i;i*j<=mx;j++){
                prime[i*j]=false;
            }
        }
    }
    for(int i=2;i<=mx;i++){
        if(prime[i])
            p.push_back(i);
    }
}
void solve(){
    int n;
    cin >> n;
    vector<int> b(n+1);
    unordered_map<int,vector<int>> mp;
    for(int i=1;i<=n;i++){
        cin >> b[i];
        mp[b[i]].push_back(i);
    }
    vector<int> ans(n+1);
    int i = 0;
    for(auto &pp:mp){
        auto & idx = pp.second;
        for(int &x:idx)
            ans[x] = p[i];
        i++; 
    }

    for(int i=1;i<=n;i++)
        cout << ans[i] << " ";
    cout << endl;
}

int32_t main(){
    init();
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}