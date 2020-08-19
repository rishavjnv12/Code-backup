#include <bits/stdc++.h>

using namespace std;
bool fun(pair<int,int>a,pair<int,int>b){
    return (float)b.second/b.first > (float)a.second/a.first; 
}
int main(){
    int n;//no. of objects
    int w;//weight of knapsack
    cin>>n;
    vector<pair<int,int>> obj(n);
    for(int i=0;i<n;i++){
        cin>>obj[i].first;//profit
    }
    for(int i=0;i<n;i++){
        cin>>obj[i].second;//weight
    }
    sort(obj.begin(),obj.end(),fun);
    for(auto i:obj){
        cout<<i.first<<" "<<i.second<<endl;
    }
    int currweight=0;
    while(currweight<w){
        
    }
    return 0;
}