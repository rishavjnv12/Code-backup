#include <bits/stdc++.h> 
#define int long long
#define all(x) x.begin(),x.end()
const int mod = 1e9+7;
using namespace std;
int f(int x,int k,bool dec){
    if(dec)
        return x-1;
    return x+1;
}
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1);
    int x = 1;
    bool dec = false;
    for(int i=1;i<=n;i++){
        a[i] = x;
        if(x == k)
            dec = true;
        x=f(x,k,dec);
    }
    vector<int> ans(k+1,-1);
    iota(ans.begin(),ans.end(),0);
    x = k;
    // for(int i=1;i<=n;i++)
    //     cout << a[i] << " ";
    // cout << endl;
    for(int i=n;i>=k;i--){
        ans[a[i]] = x;
        x--;
    }
    for(int i=1;i<=k;i++)
        cout << ans[i] << " ";
    cout << endl;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}