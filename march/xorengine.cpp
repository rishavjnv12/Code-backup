#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define upto (1<<25)
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
int32_t main()
{
    ios;
    int t;
    cin>>t;
    auto start = high_resolution_clock::now();
    vector<unsigned> arr(upto+2);
    for(int i=0;i<arr.size();i+=2){
        arr[i]=__builtin_popcount(i);
        arr[i+1]=arr[i]+1;
    }
    
    cout(arr.size());
    while(t--){
        int n,q;
        cin2(n,q);
        int odd=0,even=0;
        for(int i=0;i<n;i++){
            unsigned temp;
            cin(temp);
            if((temp/upto+arr[temp%upto])%2) odd++;
            else even++;
        }
        while(q--){
            unsigned p;
            cin(p);
            if(arr[p]%2==0){
                cout<<even<<" "<<odd<<endl;
            }else{
                cout<<odd<<" "<<even<<endl;
            }
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end-start).count();
    cout<<"Exectiom time:"<<duration<<endl;
    return 0;
}