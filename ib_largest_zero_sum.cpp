#include <bits/stdc++.h>
using namespace std;
vector<int> zerosum(vector<int> a){
    vector<int>cum_sum;
    for(int i=0,sum=0;i<a.size();i++){
        sum+=a[i];
        cum_sum.push_back(sum);
    }
    unordered_map<int,pair<int,int>> mp;
    mp[0]=make_pair(-1,INT_MIN);
    for(int i=0;i<cum_sum.size();i++){
        if(mp.find(cum_sum[i])==mp.end()){
            mp[cum_sum[i]]=make_pair(i,INT_MIN);
        }else{
            mp[cum_sum[i]].second=i;
        }
    }
    // for(auto i:mp){
    //     cout<<i.first<<":";
    //     cout<<i.second.first<<" "<<i.second.second<<endl;
    // }
    int l=INT_MIN,r=INT_MIN;
    for(auto i:mp){
        auto myp=i.second;
        if((myp.second-myp.first)>(r-l) and myp.second!=INT_MIN){
            r=myp.second;
            l=myp.first;
        }
    }
    vector<int> ans;
    for(int i=l+1;i<=r;i++){
        ans.push_back(a[i]);
    }
    return ans;
}
int main(){
    vector<int> a={-19, 8, 2, -8, 19, 5, -2, -23};
    vector<int> ans=zerosum(a);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//-8, 8, -1, -16, -28, -27, 15, -14, 14, -27, -5, -6, -25, -11, 28, 29, -3, -25, 17, -25, 4, -20, 2, 1, -17, -10, -25