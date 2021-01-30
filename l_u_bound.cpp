#include <bits/stdc++.h>
using namespace std;

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


// Return the index of smallest number greater than target
int u_bound(vector<int> &a,int target = 0){
    int l = 0;
    int h = a.size()-1;
    if(a[h] <= target)
        return h+1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(a[mid]==target and a[mid+1]>target)
            return mid+1;
        else if(a[mid] <= target)
            l = mid+1;
        else
            h = mid-1;
    }
    return l;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x:a)
        cin >> x;
    while(true){
        int target;
        cin >> target;
        cout << u_bound(a,target) << endl;
    }
    return 0;
}