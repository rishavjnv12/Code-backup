#include <bits/stdc++.h>
using namespace std;
void flip(char &a){
    if(a=='0') a = '1';
    else a = '0';
}
void test(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> a(n+1,vector<char>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cin >> a[i][j];
    }
    vector<vector<int>> ans;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m-1;j++){
            if(a[i][j] == 0){
                flip(a[i+1][j]);
                flip(a[i][j+1]);
                flip(a[i+1][j+1]);
                ans.push_back({i+1,j,i,j+1,i+1,j+1});
            }
                
            else{
                flip(a[i][j]);
                flip(a[i][j+1]);
                flip(a[i+1][j+1]);
                ans.push_back({i,j,i,j+1,i+1,j+1});
            }
        }
    }
    cout << ans.size() << endl;
    for(auto &v:ans){
        for(int &x:v){
            cout << x << " ";
        }
        cout << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--) test();
    return 0;
}