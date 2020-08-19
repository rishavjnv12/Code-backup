#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> a){
    vector<int> leftmax,rightmax;
    leftmax.push_back(a[0]);
    for(int i=1; i<a.size();i++){
        int x=max(leftmax[i-1],a[i]);
        leftmax.push_back(x);
    }
    reverse(a.begin(),a.end());
    rightmax.push_back(a[0]);
    for(int i=1; i<a.size();i++){
        int x=max(rightmax[i-1],a[i]);
        rightmax.push_back(x);
    }
    reverse(rightmax.begin(),rightmax.end());
    reverse(a.begin(),a.end());
    int ans=0;
    for(int i=0;i<a.size();i++){
        int x=min(leftmax[i],rightmax[i]);
        if(x>=a[i])
            ans+=(x-a[i]);
    }
    return ans;
}
int main(){
    vector<int> a={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<solve(a)<<endl;
    return 0;
}