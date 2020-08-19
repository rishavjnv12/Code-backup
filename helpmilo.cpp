#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define cout(x) cout<<x<<endl
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z
#define mod 1000000007


using namespace std;

int arr[1000];
int32_t main()
{
    ios;
    int t;
    //cin>>t;
    arr[0]=1;
    int x=1;
    for(int i=1;i<20;i++){
        //arr[i]=36*(arr[i-1]+1+i*x);
        arr[i]=(36%mod*(((arr[i-1]+1)%mod+(i%mod*x%mod)%mod)%mod)%mod)%mod;
        x=((x%mod)*(i%mod))%mod;
    }
    for(int i=0;i<20;i++){
        cout(arr[i]%mod);
    }
    return 0;
}