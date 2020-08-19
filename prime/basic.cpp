#include <bits/stdc++.h>
using namespace std;
vector<int> primefactor(int n){
    vector<int> result;
    while(n%2==0){
        result.emplace_back(2);
        n/=2;
    }
    for(int i=3;i<=sqrt(n);i+=2){
        while(n%i==0){
            result.emplace_back(i);
            n/=i;
        }
    }
    if(n>2){
        result.emplace_back(n);
    }
    return result;
}
int main(){
    int n=24;
    vector<int>ans=primefactor(n);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}