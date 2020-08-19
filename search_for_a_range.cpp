#include <bits/stdc++.h>
using namespace std;
vector<int> search(const vector<int>arr,int n){
    vector<int>::const_iterator start = lower_bound(arr.begin(),arr.end(),n);
    vector<int>::const_iterator end = upper_bound(arr.begin(),arr.end(),n);
    vector<int> ans(2);
    int ids=distance(arr.begin(),start);
    int ide=distance(arr.begin(),end)-1;
    if(ide<ids)
        ans[0]=ans[1]=-1;
    else{
        ans[0]=ids;
        ans[1]=ide;
    }
    return ans;
}
int main(){
    vector<int> arr={5, 7, 7, 8, 8, 10};
    int n;
    cin>>n;
    vector<int> ans=search(arr,n);
    cout<<ans[0]<<","<<ans[1]<<endl;
    return 0;
}