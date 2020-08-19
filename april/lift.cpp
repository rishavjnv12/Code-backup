#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define cout(x) cout<<x<<endl
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z


using namespace std;

int32_t main()
{
    ios;
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin2(n,q);
        int ans=0;
        int ar[2*q+1];
        ar[0]=0;
        int p=1;
        for(int i=0;i<q;i++){
            cin>>ar[p]>>ar[p+1];
            p+=2;
        }
        
        for(int i=1;i<=2*q;i++){
            ans+=abs(ar[i]-ar[i-1]);
        }
        cout(ans);
    }
    return 0;
}