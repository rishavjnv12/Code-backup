#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> hd(n),pu(n);

    for(int i=0;i<n;i++)
        cin >> hd[i];
    for(int i=0;i<n;i++)
        cin >> pu[i];
    
    //3 7 4 5
    //2 1 2 4

    //3 5 7 4
    //2 4 1 2
    //3 4 5 7
    //2 2 4 1
    vector<pair<int,int>> dish(n);
    for(int i=0;i<n;i++)
        dish[i] = {hd[i],pu[i]};
    
    sort(dish.begin(),dish.end());
    int curr_sum = 0;
    int ans = dish.back().first;
    for(int i=n-1;i>0;i--){
        curr_sum+=dish[i].second;
        ans = min({ans,max(curr_sum,dish[i-1].first)});
    }
    ans = min(ans,curr_sum+dish[0].second);
    cout << ans << endl;
}
main(){
    int t;
    cin >> t;
    while(t--) solve();
}