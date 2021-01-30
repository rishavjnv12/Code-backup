#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &v,int target){
    int lo = 0,hi = v.size()-1;
    while(lo < hi){
        int mid = lo+(hi-lo)/2;
        if(v[mid]==target)
            return mid;
        else if(v[mid] > target)
            hi = mid-1;
        else 
            lo = mid+1;
    }
    return lo;
}

int main(){
    vector<int> v = {1,2,4,5,7,9,11,12};
    int n;
    cin >> n;
    cout << solve(v,n) << endl;
    return 0;
}