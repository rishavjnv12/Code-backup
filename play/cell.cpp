#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<vector<int>> pref;
int query(int n,int x1,int y1,int x2,int y2){
    if(x1<0) x1 = 0;
    if(y1<0) y1 = 0;
    if(x2>=n) x2 = n-1;
    if(y2>=n) y2 = n-1;
    // cout << x1 <<" " << x2 << " " << y1 << " " << y2;
    int ans = pref[x1][y2];
    if(x1>0) ans-=pref[x1-1][y2];
    if(x2>0) ans-=pref[y1][x2-1];
    if(x1>0 and x2>0)
        ans+=pref[x1-1][x2-1];
    return ans;
}
int32_t main(){
    int n;
    cin >> n;
    a.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    pref = a;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            pref[i][j] += pref[i-1][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++)
            pref[i][j] += pref[i][j-1];
    }
    int q;
    cin >> q;
    while(q--){
        int x,y,l,b;
        cin >> x >> y >> l >> b;
        int from_x = x - (l),to_x = x+(l);
        int from_y = y - (b),to_y = y+(b);
        if(to_x < from_x) swap(to_x,from_x);
        if(to_y < from_y) swap(to_y,from_y);

        cout << query(n,from_x,to_x,from_y,to_y) << endl;
    }
    return 0;
}