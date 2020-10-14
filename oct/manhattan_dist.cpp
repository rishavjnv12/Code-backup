// https://www.spoj.com/problems/DISTANCE/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    scanf("%d%d",&n,&d);
    vector<pair<vector<int>,int>> points(n,{vector<int>(d),0});
    for(int i = 0;i<n;i++){
        for(int j=0;j<d;j++){
            cin>>points[i].first[j];
        }
    }
    int ans = INT_MIN;
    for(int state = 0;state < (1<<d) ;state++){
        for(int i=0;i<n;i++){
            int weight = 0;
            for(int bit = d-1;bit>=0;bit--){
                if(state&(1<<bit))
                    weight+=points[i].first[bit];
                else 
                    weight-=points[i].first[bit];
            }
            points[i].second = weight;
        }
        int mx = INT_MIN,mn = INT_MAX;
        for(int i=0;i<n;i++){
            mx = max(mx, points[i].second);
            mn = min(mn, points[i].second);
        }
        ans = max(ans,abs(mx-mn));
    }
    cout<<ans<<endl;

    return 0;
}