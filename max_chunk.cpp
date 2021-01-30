#include <bits/stdc++.h>

using namespace std;
int solve(vector<int> &v){
    int chunk = 0;
    int i = 0;
    while(i<v.size()){
        int upto = v[i];
        for(;i<=upto;i++){
            upto = max(v[i],upto);
        }
        chunk++;
    }
    return chunk;
}

int main(){
    vector<int> v(10);
    iota(v.begin(),v.end(),0);
    random_shuffle(v.begin(),v.end());
    for(int x:v)
        cout << x << " ";
    cout << endl;
    auto ans = solve(v);
    cout << ans << endl;
    return 0;
}