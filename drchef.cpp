#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define mod 1000000007
#define INF 1000000000
#define endl '\n'
#define cout(x) cout<<x<<'\n'
#define debug(x) cout<<x<<'\n\n'
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z


using namespace std;


int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        //for sub1 only
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        int ans=0;
        if(a[0]<=x){
            cout(n);
            continue;
        }
        while(x<=a[0]){
            x*=2;
            ans++;
        }
        if(x/2==a[0]) cout(ans+n-1);
        else cout(ans+n);
    }
    return 0;
}