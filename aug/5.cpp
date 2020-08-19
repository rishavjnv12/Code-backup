#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int32_t main(){
    int t;
    ios;
    cin>>t;
    while(t--){

        int n,k;
        cin>>n>>k;

        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<int> fam(101,0);


        for(int i=0; i<n; i++){
            for(int j=i;j<n;j++){
                if(j==0){
                    fam[a[j]]++;
                }else{
                    // printf("Hello1");
                    dp[i][j]=dp[i][j-1];
                    if(fam[a[j]]==1) dp[i][j]+=2;
                    else if(fam[a[j]]>=2) dp[i][j]++;
                    fam[a[j]]++;
                }
            }
            fam=vector<int>(101,0);
        }
        // printf("Initias");
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         printf("%d ",dp[i][j]);
        //     }
        //     cout<<endl;
        // }
        vector<vector<int>> dp2(101,vector<int>(n+2,0));
        for(int i=1;i<=n;i++){
            dp2[1][i]=dp[0][i-1];
        }
        for(int i=2;i<=100;i++){
            for(int j=2;j<=n;j++){
                int curr=INT_MAX;
                for(int k=1;k<j;k++){
                    curr=min(curr,dp2[i-1][k]+dp[k][j-1]);
                }
                dp2[i][j]=curr;
            }
        }
        // printf("Final extras\n");
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         printf("%d ",dp2[i][j]);
        //     }
        //     cout<<endl;
        // }
        int res=INT_MAX;
        for(int i=1;i<=100;i++){
            res=min(res,i*k+dp2[i][n]);
        }
        printf("%d\n",res);
    }
    return 0;
}