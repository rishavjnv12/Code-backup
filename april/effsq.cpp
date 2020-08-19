#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define cout(x) cout<<x<<"\n"
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
        vector<pair<int,int>> idx;
        idx.push_back(make_pair(0,-1));
        for(int i=0;i<n;i++){
            cin(s[i]);
            s[i]=abs(s[i]);
            s[i]%=4;
            if(s[i]==0){
                idx.push_back(make_pair(0,i));
            }
            if(s[i]==2){
                idx.push_back(make_pair(2,i));
            }
        }
        idx.push_back(make_pair(0,n));
        int ans=n*(n+1)/2;
        for(unsigned int i=1;i<idx.size()-1;i++){
            if(idx[i].first==2)
                ans-=((idx[i].second-idx[i-1].second)*(idx[i+1].second-idx[i].second));
        }
        cout(ans);
    }
    return 0;
}