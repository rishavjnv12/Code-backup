#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define cout(x) cout<<x<<endl
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z


using namespace std;

int32_t main()
{
    ios;
    int x,y;
    cin2(x,y);
    vector<string>arr(x);
    for(int i=0;i<x;i++){
        cin(arr[i]);
    }
    for(int i=0;i<x;i++){
        int count=0;
        for(int j=0;j<y;j++){
            if(arr[i][j]=='#')
                count++;
        }
        if(count==1){
            cout(1);
            break;
        }
        if(count==2){
            cout(0);
            break;
        }
    }
    return 0;
}