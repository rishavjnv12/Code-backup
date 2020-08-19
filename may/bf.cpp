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
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                int y=(i&k)*(j&k);
                // int x=(i*j)&k;
                cout<<y<<' '<<endl;
            }
        }
    }
    return 0;
}