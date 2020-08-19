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
        int n,k;
        cin>>n>>k;
        
        vector<vector<int>>p(k,vector<int>(n));
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                cin(p[i][j]);
            }
        }
        //cout("Hello");
        vector<int>g(n+1,0);
         
        
        int ans=0;
        for(int i=1;i<=n;i++){
            if(g[i]!=0)
                ans++;
        }
        cout(n-ans);
        for(int i=1;i<=n;i++){
            cout<<g[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}