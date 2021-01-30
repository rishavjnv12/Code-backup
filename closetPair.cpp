#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &a,vector<int> &b,int target){
    const int m = a.size();
    const int n = b.size();
    int i = 0,j = n-1;
    int ans = a[i] + b[j];
    vector<int> res = {i,j};
    while(i<m and j>=0){
        int curr = a[i] + a[j];
        if(curr < target) i++;
        else j--;
        if(abs(target - curr) < abs(target-ans)){
            ans = curr;
            res = {i,j};
        }
    }
    
}

int main(){
    vector<int>  a = {1,2,3,4,5},b = {2,4,6,8};
    int target = 9;
    cout << fun(a,b,target);
    return 0;
}