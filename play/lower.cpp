#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int n){
    unordered_map<int,int> three;
    int curr = 1;
    for(int i=0;curr <= n;i++){
        three[curr] = i;
        curr*=3;
    }
    curr = 1;
    for(int i=0;curr <= n;i++){
        if(three.count(n-curr)){
            return {i,three[n-curr]};
        }
        curr*=5;
    }
    return {-1,-1};
}
int main(){
    auto ans = solve(134);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}