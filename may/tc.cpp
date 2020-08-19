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
    t=100;
    cout(t);
    while(t--){
        int x=rand()%150;
        int y=rand()%150;
        int l=0;
        int r=abs(max(x,y)-(rand()%50));
        // int r=0;
        cout<<x<<" "<<y<<" "<<l<<" "<<r<<endl;
        
    }
    return 0;
}