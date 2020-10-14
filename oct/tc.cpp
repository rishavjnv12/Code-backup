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

int32_t main(){
    int t = 50;
    cout<<50<<endl;
    while(t--){
        int n=10;
        int x = rand()%50;
        int p = rand()%n;
        int k = rand()%n;
        cout<<n<<" "<<x<<" "<<p<<" "<<k<<endl;
        while(n--){
            cout<<rand()%50<<" ";
        }
        cout<<endl;
    }
    return 0;
}