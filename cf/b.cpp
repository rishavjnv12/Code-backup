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
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        int m,n,o;
        //0 1 2
        //0 1 2
        cin>>a>>b>>c;
        cin>>m>>n>>o;
        int _21=min(c,n);
        c-=_21;
        n-=_21;
        int ans=2*_21;

        int _10=min(b,m);
        b-=_10;
        m-=_10;

        int _00=min(a,m);
        a-=_00;
        m-=_00;

        int _01=min(a,n);
        a-=_01;
        n-=_01;

        int _02=min(a,o);
        a-=_02;
        o-=_02;

        int _11=min(b,n);
        b-=_11;
        n-=_11;

        int _22=min(c,o);
        c-=_22;
        o-=_22;

        int _20=min(c,m);
        c-=_20;
        m-=_20;

        

        int _12=min(b,o);
        b-=_12;
        o-=_12;
        ans-=2*_12;

        assert(!a and !b and !c and !o and !m and !n);
        

        cout(ans);
    }
    return 0;
}