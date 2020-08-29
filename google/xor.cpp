#include <bits/stdc++.h>

using namespace std;
struct Query{
    int x,m,id;
};
bool comp(Query p,Query q){
    return p.m<q.m;
}

void solve(){

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i;i<n;i++){
        cin>>a[i];
    }
    
    int nq;
    cin>>nq;
    vector<Query> q(nq);
    for(int i=0;i<nq;i++){
        cin>>q[i].x>>q[i].m;
        q[i].id=i;
    }

    sort(a.begin(),a.end());
    sort(q.begin(),q.end(),comp);
    vector<int> ans(nq);
    int i=0,j=0;
    for(;j<nq;j++){
        int temp=INT_MIN;
        i=0;
    
        while(i<n and a[i]<=q[j].m){
            int curr=a[i]^q[j].x;
            if(curr > temp){
                temp=curr;
                ans[q[j].id]=a[i];
            }
            i++;
        }
        if(temp==INT_MIN){
            ans[q[j].id]=-1;
        }
    }
    for(auto i:ans){
        cout<<i<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
}