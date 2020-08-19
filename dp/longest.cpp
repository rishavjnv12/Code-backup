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
int fun(string s){

    vector<pair<char,int>> v;
    int n=s.length();


    v.push_back(make_pair(')',-1));
    for(int i=0;i<n;i++){
        v.push_back(make_pair(s[i],i));
    }
    v.push_back(make_pair('(',n));


    stack<pair<char,int>> st;
    st.push(v[0]);
    for(int i=1;i<=n+1;i++){
        if(v[i].first==')' and st.top().first=='(') st.pop();
        else    st.push(v[i]);
    }


    v.clear();
    while(!st.empty()){
        v.push_back(st.top());
        st.pop();
    }
    int ans=INT_MIN;
    for(int i=0;i<v.size()-1;i++){
        ans=max(abs(v[i].second-v[i+1].second),ans);
    }
    return ans-1;
}

int32_t main(){
    string par;
    cin>>par;
    cout(fun(par));
    return 0;
}