#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n*k+1);
    for(int i=1;i<=n*k;i++) cin >> a[i];
    int ans = 0;
    sort(a.begin()+1,a.end());
    int pr;
    int m_idx = ceil(1.0*n/2);
    int reject = k*(m_idx-1);
    int adv = n-(m_idx-1);
    for(int i = reject+1;i<=n*k;i+=adv) ans+=a[i];
    
    cout << ans << endl;

}

int32_t main(){
    int t;
    scanf("%lld",&t);
    while(t--) solve();
    return 0;
}