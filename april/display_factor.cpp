#include <bits/stdc++.h>

#define MAX 100000001
#define int long long
using namespace std;
bool prime[MAX];
vector<int> a;
void sieve(){
    memset(prime,true,sizeof(prime));
    prime[1]=false;
    for(int i=2;i*i<=MAX;i++){
        if(prime[i]){
            for(int j=i*i;j<=MAX;j+=i){
                prime[j]=false;
            }
        }
    }
}
void displayfac(int n,vector<int> &a){
    vector<int> ans;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            ans.push_back(i);
            if(i!=sqrt(n))
            ans.push_back(n/i);
        }
    }
    sort(ans.begin(), ans.end());
    int pcount=0;
    for(size_t i=0; i<ans.size();i++){
        // cout<<ans[i]<<" ";
        if(prime[ans[i]])
            pcount++;
    }
    if(pcount==2 and ans.size()%2){
        // cout<<n<<":"<<ans.size()<<" "<<pcount<<endl;
        // a.push_back(ans.size());
        cout<<ans.size()<<",";

    }
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    vector<int> a;
    for(int i=0;i<=MAX;i++){
        displayfac(i,a);
    }
    // for(int i=0;i<a.size();i++){
    //     cout<<a[i]<<",";
    // }
    // cout<<endl;
    return 0;
}