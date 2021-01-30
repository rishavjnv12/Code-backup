#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
long long add(long long a,long long b){
    return ((a%mod)+(b%mod))%mod;
}
long long mul(long long a,long long b){
    return ((a%mod)*(b%mod))%mod;
}
int solve(vector<int> &a,int target){
    const int n = a.size();
    int l = 0, r = n-1;
    long long ans = 0;
    while(l<=r){
        int curr = a[l] + a[r];
        if(curr < target)
            l++;
        else if(curr > target)
            r--;
        else{
            int left = 1,right = 1;
            while(l<n-1 and a[l]==a[l+1]){
                l++;
                left++;
            }
            while(r>1 and a[r]==a[r-1]){
                r--;
                right++;
            }
            if(a[l] == a[r]){
                ans = add(ans,mul(left,left-1)/2);
            }else{
                ans = add(ans,mul(left,right));
            }
            l++;
            r--;
        }
    }
    return ans;
}
int main(){
    vector<int> v = {1, 2, 6, 6, 7, 9, 9};
    cout << solve(v,13) << endl;
    return 0;
}