#include <bits/stdc++.h>
using namespace std;

int ar[100001],st[400004];

void build(int v,int l,int r){
    if(l==r){
        st[v]=ar[l];
    }else{
        int tm=(l+r)/2;
        build(2*v,l,tm);
        build(2*v+1,tm+1,r);
        st[v]=min(st[v*2],st[2*v+1]);
    }
}
int query(int v, int tl, int tr, int l, int r){
    if(l>r)
        return INT_MAX;
    if(tl == l and tr == r)
        return st[v];
    int mid = (tl+tr)/2;
    return min(query(2*v,tl,mid,l,min(r,mid)),query(2*v+1,mid+1,tr,max(l,mid+1),r));
}
int main(){
    int n,q,l,r;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ar[i];
    }
    build(1,1,n);
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<query(1,1,n,l+1,r+1)<<endl;
    }
    return 0;
}
