#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int memo[4004][4004];
int final_n = 0;
bool iss(vector<int>&nums,int idx,int sum){
    if(idx==-1)
        return sum==0;
    if(sum<0)
        return false;
    if(memo[idx][sum] == -1)
        return memo[idx][sum] = (iss(nums,idx-1,sum) or iss(nums,idx-1,sum-nums[idx]));
    return memo[idx][sum];
}
bool subset_sum(vector<int> &a,int target){
    memset(memo,-1,sizeof memo);
    return iss(a,a.size()-1,target);
}

int find_min(vector<int> &a,int n,vector<int> &pref){
    int sum = pref[n-1];
    bool dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
                dp[i][j] = dp[i-1][j];
            if(a[i-1]<=j)
                dp[i][j] |= dp[i-1][j-a[i-1]];
        }
    }
    int diff = INT_MAX;
    for(int j=sum/2;j>=0;j--){
        if(dp[n][j]){
            diff = sum-2*j;
            break;
        }
    }
    return diff;
}
bool check(vector<int> &a,int idx,vector<int> &pref,int k){
    int diff = find_min(a,idx+1,pref);
    return ((pref[idx]-diff)/2)>=k;
}
int b_s(vector<int> &a,vector<int> &pref,int k){
    int left = 0;
    const int n = a.size();
    while(left<n and pref[left]<2*k) left++;
    int right = n-1;
    int ans = -1;
    while(left<=right){
        int mid = (left+right)/2;
        if(check(a,mid,pref,k)){
            ans = mid+1;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return ans;
}

void solve(){
    int n,k;
    scanf("%lld%lld",&n,&k);
    final_n+=n;
    vector<int> a(n),pref(n);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    int sum = accumulate(a.begin(),a.end(),0);
    sort(a.rbegin(),a.rend());
    partial_sum(a.begin(),a.end(),pref.begin());
    if(sum < 2*k or n==1){
        printf("-1\n");
        return;
    cin.tie(NULL);
    }else if(sum == 2*k){
        if(subset_sum(a,k))
            printf("%lld\n",n);
        else printf("-1\n");
    }else if(a[0]>=k and a[1]>=k){
        // cout << 2 << endl;
        printf("2\n");
    }else if(a[0]>=k and a[1]<k){
        int curr = 0;
        int i = 1;
        while(curr < k and i<n){
            curr+=a[i];
            i++;
        }
        printf("%lld\n",i);
    }else{
        int ans = b_s(a,pref,k);
        printf("%lld\n",ans);
        return;
    }
}
int32_t main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    scanf("%lld",&t);
    while(t--) solve();
    assert(final_n < 4000);
    return 0;
}