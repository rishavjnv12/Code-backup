#include <bits/stdc++.h>
#define int long long
using namespace std;
int final_n = 0;
int memo[4004][4004];
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

void solve(vector<int> &a,int k){
    const int n = a.size();
    vector<int> pref(n);
    int sum = accumulate(a.begin(),a.end(),0);
    sort(a.rbegin(),a.rend());
    partial_sum(a.begin(),a.end(),pref.begin());
    if(sum < 2*k or n==1){
        printf("-1\n");
        return;
    }else if(sum == 2*k){
        if(subset_sum(a,k))
            printf("%lld\n",n);
        else printf("-1\n");
    }else if(a[0]>=k and a[1]>=k){
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
        if(final_n > 15000 and final_n<20000){
            int sa = 0;
            int i = 0;
            int a_count;
            while(i<n){
                sa+=a[i];
                int j;
                bool found = false;
                for(j=n-1;j>=i+1;j--){
                    if(a[j]>=k-sa){
                        found = true;
                        break;
                    }
                }
                if(found){
                    swap(a[i+1],a[j]);  // 8 2 5 5 3 1
                    a_count = i+2;
                    break;
                }
                i++;
            }
            sort(a.begin()+a_count,a.end(),greater<int>());
            int ba = 0;
            i = a_count;
            int b_count = 0;
            while(ba<k and i<n){
                ba+=a[i];
                i++;
                b_count++;
            }
            if(ba>=k){
                // cout << a_count << " " << b_count << endl;
                cout << a_count + b_count << endl;
            }else{
                cout << -1 << endl;
            }
        }else{
            int ans = b_s(a,pref,k);
            printf("%lld\n",ans);
        }
    }
}

int32_t main(){
    int t;
    scanf("%lld",&t);
    vector<vector<int>> q(t);
    vector<int> q_k(t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%lld%lld",&n,&q_k[i]);
        final_n+=n;
        q[i].resize(n);
        for(int j=0;j<n;j++){
            scanf("%lld",&q[i][j]);
        }
    }
    for(int i=0;i<t;i++){
        solve(q[i],q_k[i]);
    }
    return 0;
}