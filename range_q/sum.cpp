#include <bits/stdc++.h>
#define vi vector<int> 
const int MAXN = 1000;

using namespace std;

int t[4*MAXN];
void build(vi a,int v,int tl,int tr){
    if(tl==tr){
        t[v]=a[tl];
    }else{
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
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
int main(){
    vi a={1,3,-2,8,-7};
    build(a,1,0,a.size()-1);

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<"Sum"<<":"<<"("<<i<<","<<j<<"):"<<sum(1,0,4,i,j)<<endl;
        }
    }
    return 0;
}