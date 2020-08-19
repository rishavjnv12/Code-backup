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
    int n,f;
    cin2(n,f);
    // cout<<n<<" "<<f<<endl;
    int ar[n][n];
    vector<int> ver(n,0);
    vector<int> hor(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin(ar[i][j]);
            hor[i]+=ar[i][j];
            ver[j]+=ar[i][j];
        }
    }
    int k;
    cin(k);
    // for(auto i:hor){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // for(auto i:ver){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    int lshot=0;
    for(int i=0;i<n;i++){
        lshot+=ceil(hor[i]/f);
    }
    int ushot=0;
    for(int i=0;i<n;i++){
        ushot+=ceil(ver[i]/f);
    }
    
    int ans=0;
    cout<<lshot<<" "<<ushot<<endl;

    return 0;
}