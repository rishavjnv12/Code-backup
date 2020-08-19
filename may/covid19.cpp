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
// 1 2 5 6 7
//  1 3 1 1 
int32_t main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        vector<int> dist;
        for(int i=1;i<n;i++){
            dist.push_back(abs(ar[i]-ar[i-1]));
        }
        // for(auto i=0;i<dist.size();i++){
        //     cout<<dist[i]<<" ";
        // }
        int mm = LLONG_MAX,mx = LLONG_MIN;
        int x=0;
        for(int i=0;i<dist.size();i++){
            if(dist[i]<=2)
                x++;
            else {
                mm = min(x,mm);
                mx = max(x,mx);
                x=0;
            }
        }
        mm = min(x,mm);
        mx = max(x,mx);
        cout<<mm+1<<" "<<mx+1<<endl;
    }
    
    
    return 0;
}