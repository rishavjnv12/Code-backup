#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> g(n),a(n),b(n);
    for(int &x:g) cin >> x;
    for(int &x:a) cin >> x;
    for(int &x:b) cin >> x;
    int ans = 0;
    int curr_open;
    vector<int> dp(n,0);
    if(n == 2){
        ans = abs(b[1]-a[1])+2+g[1]-1;
        cout << ans << endl;
        return;
    }
    curr_open = abs(a[1]-b[1]);
    // cout << curr_open << " " ;
    for(int i=1;i<n-1;i++){
        curr_open+=2;
        // cout << curr_open << " " ;
        ans = max(ans, curr_open+g[i]-1);
        if(a[i+1]==b[i+1]){
            curr_open = 0;
        }else if(a[i+1]<b[i+1]){
            curr_open += (a[i+1]-1);
            curr_open += (g[i]-b[i+1]);
            curr_open = max(curr_open,abs(b[i+1]-a[i+1]));
        }else{
            curr_open += (b[i+1]-1);
            curr_open += (g[i]-a[i+1]);
            curr_open = max(curr_open,abs(b[i+1]-a[i+1]));
        }
        
    }
    ans = max(ans, curr_open+g.back()-1+2);
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