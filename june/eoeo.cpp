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

template <typename T> vector<T> read_vector(int n) { vector<T> r(n); for (auto& a : r) cin >> a; return r; }
template <typename T> vector<T> read_vector() { int n; cin >> n; return read_vector<T>(n); }
bool emulate(int js,int ts){
    while(1){
        if(js%2 and ts%2) return false;
        else if(js%2==0 and ts%2==0) {
            js/=2;
            ts/=2;
        }else if(js%2==1 and ts%2==0){
            return false;
        }else return true;
    }
}

int32_t main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int i=0;
        while((n&(1<<i))==0) i++;
        int ans=n/(1<<(i+1));
        cout<<ans<<endl;
    }
    
        

    return 0;
}