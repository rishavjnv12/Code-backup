#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define cout(x) cout<<x<<endl
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z
#define MAX 1000001

using namespace std;

int arr[MAX];
void sieve(){
    arr[1]=1;
    for(int i=2;i<MAX;i+=2){
        arr[i]=2;
    }
    for(int i=3;i*i<MAX;i++){
        if(arr[i]==i){
            for(int j=i*i;j<MAX;j+=i)
                if(arr[j]==j)
                    arr[j]=i;
        }
    }
}
vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    cout("Here also");
    while (x!=1){ 
        ret.push_back(arr[x]); 
        x/=arr[x]; 
    } 
    for(auto i:ret){
        cout(i);
    }
    return ret; 
} 
int fun(int x){
    return 1-1/x;
}
int32_t main()
{
    ios;
    int t;
    cin>>t;
    sieve();
    cout("Here");
    while(t--){
        int n;
        cin(n);
        vector<int>temp=getFactorization(n);
        for(auto i:temp){
            cout(i);
        }
        int ans=n;
        for(int i=0;i<temp.size();i++){
            int a=0;
            while(n%temp[i]==0 and n!=1){
                a++;
                n/=temp[i];  
            }
            ans=ans*(a-1)/a;
        }
        cout(ans);
        
    }
    return 0;
}