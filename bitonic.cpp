#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &a,int l,int r,int target){
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid]==target)
            return mid;
        else if(a[mid]>target)
            r = mid-1;
        else 
            l = mid+1;
    }
    return -1;
}
int rbs(vector<int> &a,int l,int r,int target){
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid] == target)
            return mid;
        else if(a[mid]>target)
            l = mid+1;
        else 
            r = mid-1;
    }
    return -1;
}
int solve(vector<int> &a,int target){
    const int n = a.size();
    int l = 0,r = n-1;
    int peak;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid-1] < a[mid] and a[mid+1] > a[mid]){
            peak = mid;
            break;
        }else if(a[mid] < a[mid+1]){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    int left = bs(a,0,peak,target);
    if(left!=-1)
        return left;
    return rbs(a,peak+1,n-1,target);
}


int main(){
    vector<int> v = {1,2,3,4,5,6,7,5,3,1};
    while(true){
        int n;
        cin >> n;
        cout << solve(v,n) << endl;
    }
    return 0;
}