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
    ios;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<int,int> hor,ver;
        for(int i=0;i<4*n-1;i++){
            int x,y;
            cin2(x,y);
            hor[x]++;
            ver[y]++;
        }
        int x,y;
        for(auto i=hor.begin();i!=hor.end();i++){
            if(i->second%2){
                x=i->first;
                break;
            }
        }
        for(auto i=ver.begin();i!=ver.end();i++){
            if(i->second%2){
                y=i->first;
                break;
            }
        }
        printf("%lld %lld\n",x,y);
    }
    return 0;
}