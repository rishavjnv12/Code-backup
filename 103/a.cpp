#include <bits/stdc++.h> 
#define int long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
const int mod = 1e9+7;
using namespace std;
void solve(){
    int n,k;
    cin >> n >> k;
    if(n<k){
        cout << ceil(1.0*k/n) << endl;
    }else{
        if(n%k==0)
            cout << 1 << endl;
        else cout << 2 << endl;
    }
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(true);
    cin.tie(0);
    cin >> t;
    while(t--) solve();
    return 0;
}