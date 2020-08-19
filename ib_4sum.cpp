#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> foursum(vector<int> a,int target){
    map<int,pair<int,int>> mp;
    vector<vector<int>> ans;
    assert(mp.find(0)!=mp.end());
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            if(a[i]==0 and a[j]==0) cout<<"here";
            if(mp.find(target-(a[i]+a[j]))==mp.end()){
                if(a[i]==0 and a[j]==0) cout<<"here";
                mp[a[i]+a[j]]=make_pair(a[i],a[j]);
            }else{
                vector<int> temp(4);
                temp[0]=mp[target-(a[i]+a[j])].first;
                temp[1]=mp[target-(a[i]+a[j])].second;
                temp[2]=a[i];
                temp[3]=a[j];
                sort(temp.begin(),temp.end());
                ans.push_back(temp);
            }
        }
    }
    sort(ans.begin(),ans.end());
    ans.resize(distance(ans.begin(),unique(ans.begin(),ans.end())));
    
    return ans;
}
int main(){
    vector<int> a={ 9, -8, -10, -7, 7, -8, 2, -7, 4, 7, 0, -3, -4, -5, -1, -4, 5, 8, 1, 9, -2, 5, 10, -5, -7, -1, -6, 4, 1, -5, 3, 8, -4, -10, -9, -3, 10, 0, 7, 9, -8, 10, -9, 7, 8, 0, 6, -6, -7, 6, -4, 2, 0, 10, 1, -2, 5, -2};
    // vector<int> a={0,0,0,0};
    int target=0;
    auto ans=foursum(a,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}