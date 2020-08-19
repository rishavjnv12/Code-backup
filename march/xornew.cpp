#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
//#define int long long
#define cout(x) cout<<x<<"\n"
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z
#define endl "\n"


using namespace std;
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
int32_t main()
{
    ios;
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin2(n,q);
        int odd=0,even=0;
        for(int i=0;i<n;i++){
            int temp;
            fastscan(temp);
            cout<<temp<<" ";
            if(__builtin_popcount(temp)%2) odd++;
            else even++;
        }
        cout<<endl;
        while(q--){
            int p;
            fastscan(p);
            if(__builtin_popcount(p)%2==0){
                cout<<even<<" "<<odd<<endl;
            }else{
                cout<<odd<<" "<<even<<endl;
            }
        }
        
    }
    return 0;
}