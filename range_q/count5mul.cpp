// https://practice.geeksforgeeks.org/problems/count-multiples-of-five/
#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define cout(x) cout<<x<<endl
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z
#define vi vector<int>
using namespace std;
const int MAXN=100000;
int t[4*MAXN];
void build(vi a,int v,int tl,int tr){
    if(tl==tr){
        t[v]=(a[tl]%5==0);
    }else{
        int tm=(tl+tr)/2;
        build(a,2*v,tl,tm);
        build(a,2*v+1,tm+1,tr);
        t[v]=t[2*v]+t[2*v+1];
    }
}
int sum(int v, int tl, int tr, int l, int r) {
    if(l>r)
        return 0;
    if(l==tl and r==tr)
        return t[v];
    int tm=(tl+tr)/2;
    return sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
}

int32_t main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n,q;
        cin2(n,q);
        vi a(n);
        vi qr(2*q);
        for(int i=0;i<n;i++){
            cin(a[i]);
        }
        build(a,1,0,n-1);
        for(int i=0;i<2*q;i++){
            cin(qr[i]);
        }
        // for(int i=1;i<2*n;i++){
        //     cout<<t[i]<<" ";
        // }
        cout<<"\n";
        for(int i=0;i<q;i++){
            cout<<sum(1,0,n-1,qr[i*2]-1,qr[i*2+1]-1)<<" ";
        }
        cout<<"\n";
    }
    return 0;
}