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
#define nl cout<<"\n"


using namespace std;
int fact(int t){
    if(t==0) return 1;
    return t*fact(t-1);
}
int32_t main(){
    int t=10;
    vector<int32_t> ar(t);
    for(int i=0;i<t;i++){
        ar[i] = i+1;
    }
    cout<<10<<endl;
    int i=0;
    for(int i=0;i<10;i++){
        cout<<t<<" "<<200<<endl;;
        for(int i=0;i<t;i++){
            cout<<ar[i]<<" ";
        }
        nl;
        random_shuffle(ar.begin(), ar.end());
    }
    return 0;
}