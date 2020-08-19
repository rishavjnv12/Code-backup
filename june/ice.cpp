#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define cout(x) cout<<x<<endl
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z


using namespace std;

template <typename T> vector<T> read_vector(int n) { vector<T> r(n); for (auto& a : r) cin >> a; return r; }
template <typename T> vector<T> read_vector() { int n; cin >> n; return read_vector<T>(n); }
int32_t main()
{
    ios;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> ar(n);
        for(int i=0;i<n;i++) cin>>ar[i];


        bool pos=true;
        int hsh[4]={0,0,0,0};
        
        for(int i=0;i<n;i++){
            if(ar[i]==5){
                hsh[1]++;
            }else if(ar[i]==10){
                if(hsh[1]==0){
                    pos=false;
                    
                    break;
                }else{
                    hsh[1]--;
                    hsh[2]++;
                }
            }else{
                if(hsh[2]>0){
                    hsh[2]--;
                    hsh[3]++;
                }else if(hsh[1]>1){
                    hsh[1]-=2;
                    hsh[3]++;
                }else{
                    pos=false;
                    break;
                }
            }
            
        } 
        if(pos) cout("YES");
            else cout("NO");
    }
    return 0;
}