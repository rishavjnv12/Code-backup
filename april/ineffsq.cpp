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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin(n);
        vector<int> s(n);
        for(int i=0;i<n;i++){
            cin(s[i]);
            s[i]=abs(s[i]);
            s[i]%=4;
            //cout<<s[i]<<" ";
        }
        //cout<<endl;
        int ans=0;
        for(int i=0;i<=n-1;i++){
            int mul=1;
            for(int j=i;j<=n-1;j++){
                mul=mul*s[j];
                mul%=4;
                if(mul!=2)
                    ans++;
            }
        }
        cout(ans);
        
    }
    return 0;
}