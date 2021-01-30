#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<long long> a(n),b(m);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<m;i++) scanf("%lld",&b[i]);
    long long av = accumulate(a.begin(),a.end(),0LL);
    long long bv = accumulate(b.begin(),b.end(),0LL);
    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend());
    int ans = 0,i=0,j=0;
    while(av<=bv and i<n and j<m){
        av-=a[i];
        av+=b[j];
        bv-=b[j];
        bv+=a[i];
        i++;
        j++;
        ans++;
    }
    if(av>bv)
        cout << ans << endl;
    else 
        cout << -1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}