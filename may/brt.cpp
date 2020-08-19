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
int arr[1000000];
int arr2[1000000];
int32_t main(){
    int t;
    cin>>t;
    memset(arr, -1, sizeof(arr));
    while(t--){
        int x,y,l,r;
        cin>>x>>y>>l>>r;
        int mx=-1;
        int mxx=INT_MIN;
        for(int i=l;i<=r;i++){
            if(((x&i)*(y&i))>mxx){
                mx=i;
                mxx=(x&i)*(y&i);
            }
        }
        arr[(x|y)&r]=mx;
        arr2[(x|y)|r]=mx;
        for(int i=0;i<10000;i++){

            cout<<arr[i]<<" "<<arr2[i]<<endl;
        }
    }
    return 0;
}