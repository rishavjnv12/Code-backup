#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
void solve(){
    int n;
    cin >> n;
    map<int,int> mp;
    while(n--){
        int x;
        cin >> x;
        mp[x]++;
    }
    int ans = 0;
    for(auto p:mp) ans = max(ans,p.second);
    cout << ans << endl;
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(true);
    cin.tie(0);
    cin >> t;
    while(t--) solve();
    return 0;
}