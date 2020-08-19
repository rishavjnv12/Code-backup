#include <bits/stdc++.h>
#define MAX 100000001
using namespace std;
bool prime[MAX];
void seive(){
    memset(prime,true,sizeof(prime));
    for(int i=2;i*i<=MAX;i++){
        if(prime[i]){
            for(int j=i*i;j<=MAX;j+=i){
                prime[j]=false;
            }
        }
    }
}
int main(){
    seive();
    int t;
    cin>>t;
    while(t--){
        cout<<t<<" "<<prime[t]<<endl;
    }
    return 0;
}