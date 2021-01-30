#include <bits/stdc++.h> 

using namespace std;
string solve(const vector<string>& a){
    const int n = a.size();
    if(n == 0)
        return "";
    int ans = a[0].size();
    for(int i=1;i<n;i++){
        int j;
        for(j=0;j<min(ans,(int)a[i].size());j++){
            if(a[i][j]!=a[0][j])
                break;
        }
        ans = j;
    }
    return a[0].substr(0,ans);
}

int32_t main(){
    vector<string> arr = {"aaaa","aaaaaaa","aaaaaaaaaaaaaaaa"};
    cout << solve(arr) << endl;
    return 0;
}