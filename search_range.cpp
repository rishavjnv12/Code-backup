#include <bits/stdc++.h>
using namespace std;
int left(vector<int> &v,int target){
    if(v[0]==target)
        return 0;
    int lo = 0;
    int hi = v.size()-1;
    while(lo <= hi){
        int mid = lo+(hi-lo)/2;
        if(v[mid] == target){
            if(v[mid-1]<target)
                return mid;
            else
                hi = mid-1; 
        }else if(v[mid] < target){
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    return -1;
}
int right(vector<int>& v,int target){
    int lo = 0;
    int hi = v.size()-1;
    if(v[hi]==target)
        return hi;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(v[mid] == target){
            if(v[mid+1]>target)
                return mid;
            else
                lo = mid+1;
        }else if(v[mid] < target){
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    return -1;
}
int solve(vector<int> &v,int target){
    const int n = v.size();
    int l = left(v,target);
    if(l==-1)
        return 0;
    int r = right(v,target);
    return r-l+1;
}
int main(){
    vector<int> v = {1,2,3,4,5,5,5,5,6,7,8};
    int n;
    cin>>n;
    auto ans = solve(v,n);
    cout << ans << endl;
    return 0;
}