#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define cout(x) cout<<x<<endl
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z


using namespace std;

//5,10,11,16,21,22,27,33,38,39
int32_t main(){
    ios;
    int t;
    vector<int>arr(21,0);
    arr[5]=arr[10]=arr[11]=arr[16]=1;
    cin>>t;
    while(t--){
        int m,y;
        cin2(m,y);
        int m2,y2;
        cin2(m2,y2);
        int nos;
        if(y==y2){
            nos=(arr[y] and m==2);
        }
        
        if(y2<5){
            nos=0;
        }else{
            nos=0;
            for(int i=y-1;i<=y2;i++){
                nos+=arr[i];
            }
            if(m>2 and arr[y]) nos--;
            if(m<2 and arr[y2]) nos--;
        }
        cout(nos);
    }
    return 0;
}