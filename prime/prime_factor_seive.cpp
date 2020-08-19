#include <bits/stdc++.h>
#define MAX 10000001

using namespace std;

//store smallest prime factor
int spf[MAX];
void seive(){
    for(int i=1;i<MAX;i++){
        spf[i] = i;
    }
    for(int i=4;i<MAX;i+=2){
        spf[i] = 2;
    }
    for(int i=3;i*i<MAX;i+=2){
        for(int j=i*i;j<MAX;j+=i){
            if(spf[j]==j){
                spf[j] = i;
            }
        }
    }
}
vector<int> getf(int n){
    vector<int> ans;
    while(n!=1){
        ans.emplace_back(spf[n]);
        n/=spf[n];
    }
    return ans;
}
int main(){
    int n=10000;
    seive();
    for(int i=1;i<n;i++){
        vector<int> ans=getf(i);
        cout<<i<<":";
        for(int j=0;j<ans.size();j++){
            cout<<ans[j]<<" ";c
        }
        cout<<endl;
    }
    return 0;
}