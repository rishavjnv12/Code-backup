#include <bits/stdc++.h>
using namespace std;
int binary_search(const vector<int> &a,int l,int r,int target){
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
int search(const vector<int> &a,int target=0){
    const int n = a.size();
    if(n<=1 or a[0]<a[n-1])
        return binary_search(a,0,n-1,target);
    int l = 0,r = n-1;
    int pivot;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid]>a[mid+1]){
            pivot = mid;
            break;
        }else if(a[mid]<a[n-1])
            r = mid-1;
        else 
            l = mid+1;

    }
    // return pivot;
    if(a[pivot]==target)
        return pivot;
    int left = binary_search(a,0,pivot-1,target);
    if(left!=-1)
        return left;
    return binary_search(a,pivot+1,n-1,target);
}
int main(){
    vector<int> a={15,16,17,18,1,2,3,4,5,6,7,8};
    cout << search(a) << endl;
    return 0;
}
// 5,6,7,8,1,2,3,4