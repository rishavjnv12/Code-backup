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
        string a,b;
        cin>>a;
        cin>>b;
        int q;
        cin>>q;
        vector<pair<string,int>> ar(q);
        for(int i=0;i<q;i++){
            string s;
            int n;
            cin>>s>>n;
            ar[i]=make_pair(s,n);
        }
        vector<string> text;
        for(int i=0;i<=a.size();i++){
            for(int j=1;j<=a.size()-i;j++){
                string part1=a.substr(i,j);
                for(int k=0;k<b.size();k++){
                    for(int l=1;l<=b.size()-k;l++){
                        string part2=b.substr(i,j);
                        text.push_back(part1+part2);
                    }
                }
            }
            
        }
        for(int i=0;i<text.size();i++){
            cout<<text.at(i)<<endl;
        }
    }
    return 0;
}