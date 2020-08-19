#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
// #define int long long
#define mod 1000000007
#define INF 1000000000
#define cout(x) cout<<x<<endl
#define debug(x) cout<<x<<'\n\n'
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z


using namespace std;

template <typename T> vector<T> read_vector(int n) { vector<T> r(n); for (auto& a : r) cin >> a; return r; }
template <typename T> vector<T> read_vector() { int n; cin >> n; return read_vector<T>(n); }


int32_t m[61][61];
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        fflush(stdout);
        int n,p;
        cin>>n>>p;
        memset(m,0,sizeof m);
        unordered_map<int,int> rows;
        for(int i=1;i<=n;i++){
            int curr;
            printf("1 %d %d %d %d",i,1,i,n);
            cin>>curr;
            assert(curr!=-1);
            rows[i]=curr;
        }

        for(int i=1;i<=n;i++){
            int n=0;
            int exp=rows[i];
            for(int j=1;j<=n;j++){
                if(n==exp) break;
                printf("1 %d %d %d %d",i,j,i,j);
                cout<<endl;
                int x;
                cin>>x;
                assert(x!=-1);
                if(x==1) {
                    n++;
                    m[i][j]=1;
                }
            }
        }
        // vector<vector<int>> m(n,vector<int>(n,0));
        // printf("1 1 1 %d %d",n,n);
        // cout<<endl;
        // int total,c=0;
        // cin>>total;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         printf("1 %d %d %d %d",i+1,j+1,i+1,j+1);
        //         cout<<endl;
        //         int x;
        //         cin>>x;
        //         assert(x!=-1);
        //         if(x){
        //             c++;
        //             m[i][j]=1;
        //         }
        //         if(c==total) break;
        //     }
        // }
        cout(2);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
        int x;
        cin>>x;
        assert(x==1);
    }
    return 0;
}