#include <bits/stdc++.h>

using namespace std;
const int MAX=1e5;
const int INF=INT_MAX;

int a[MAX];
int st[4*MAX+1];
void build(int si,int ss, int se){
    if(ss==se) {
        st[si]=a[ss];
        return;
    }
    int mid=(ss+se)/2;
    // cout<<mid<<endl;
    build(2*si,ss,mid);
    build(2*si+1,mid+1,se);

    st[si]=min(st[2*si],st[2*si+1]);
}

int query(int si,int ss,int se,int l,int r){
   if(ss>r or se<l) return INF;
   if(ss>=l and se<=r) return st[si];

    int mid=(ss+se)/2;
    return min(query(2*si,ss,mid,l,r),query(2*si+1,mid+1,se,l,r));

}


int main(){
    int n,q,l,r;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<query(1,1,n,l+1,r+1)<<endl;
    }
    return 0;
}