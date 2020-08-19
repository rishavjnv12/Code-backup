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
        int n,q;
        cin2(n,q);
        string s;
        cin(s);
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        
        for(int i=0;i<q;i++){
            int no,ans=0;
            cin(no);
            for(auto i=mp.begin();i!=mp.end();i++){
                if(i->second > no){
                    ans+=(i->second-no);
                }
            }
            cout(ans);
        }
    }
    return 0;
}