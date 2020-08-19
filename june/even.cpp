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
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> m(n,vector<int>(n));
        int x=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m[i][j]=x;
                x++;
            }
        }
        if(n%2==0){
            for(int i=1;i<n;i+=2){
                for(int j=0;j<n;j+=2){
                    swap(m[i][j],m[i][j+1]);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}