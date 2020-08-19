#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define cout(x) cout<<x<<"\n"
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z
#define endl "\n"

using namespace std;
using namespace std::chrono;
void fastscan(int &x){
    bool neg=false;
    register int c;
    x =0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}
void fastscan2(vector<int> &a,int i){
    bool neg=false;
    register int c;
    a[i] = 0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        a[i] = (a[i]<<1) + (a[i]<<3) +c -48;
    if(neg)
        a[i] *=-1;
}
int32_t main()
{
    ios;
    int t;
    auto start = high_resolution_clock::now();
    fastscan(t);
    while(t--){
        int n;
        fastscan(n);
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            fastscan2(arr,i);
        }
        int xl=accumulate(arr.begin(),arr.end(),0,bit_xor<int>());
        cout(xl);
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end-start).count();
    cout<<"Exectiom time:"<<duration<<endl;
    return 0;
}