#include <bits/stdc++.h>
using namespace std;
// -10 -6 -5 -4
//  -9 -4 -3  1
//  -7 -2  1  2
//  -5  2  3  4

// Return the index of first occurrence of element if present
// Or the index of lowest element greater than the target
int l_bound(vector<int>& a,int target=0){
    int l = 0;
    int h = a.size()-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(a[mid] == target){
            if(mid == 0 or a[mid-1]<target)
                return mid;
            else
                h = mid-1;
        }else if(a[mid]<target)
            l = mid+1;
        else 
            h = mid-1;
    }
    return l;
}


int solve(vector<vector<int>> &a){
    if(a.empty() or a[0].empty())
        return 0;
    int l = 0;
    int r = a.size()-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(a[mid][0] == 0){
            if(mid == 0 or a[mid-1][0]<0){
                l = mid;
                break;
            }else
                r = mid-1;
        }else if(a[mid][0]<0)
            l = mid+1;
        else 
            r = mid-1;
    }
    int ans = 0;
    cout << l << endl;
    for(int i = 0;i<l;i++){
        ans+=l_bound(a[i],0);
    }
    return ans;
}
int main(){
    vector<vector<int>> v = {{-10,-6,-5,-4},
                {-9,-4,-3,1},
                {-7,-2,1,2},
                {-5,2,3,4},
                {0,2,3,4}};

    cout << solve(v) << endl;
    return 0;
}