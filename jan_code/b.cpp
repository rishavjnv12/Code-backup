#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,k;
    scanf("%lld%lld",&n,&k);
    vector<int> a(n);
    vector<int>pref(n);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    sort(a.rbegin(),a.rend());
    partial_sum(a.begin(),a.end(),pref.begin());
    for(int x:pref) cout << x << endl;
    int ans = lower_bound(pref.begin(),pref.end(),k) - pref.begin();
    cout << ans << endl;

}

int32_t main(){
    int t;
    scanf("%lld",&t);
    while(t--) solve();
    return 0;
}