#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &v){
    int n = v.size();

    sort(v.begin(),v.end());
    swap(v[0],v[v.size()-1]);
    int hi = n-2;
    int lo = 1;
    
    while(lo < hi){
        if(v[lo]==v[lo-1] or v[hi]==v[hi+1])
            swap(v[lo],v[hi]);
        lo++;
        hi--;
    }
    return v;
}
int main(){
    vector<int> v = {1,1,1,1,2,2,2};
    auto ans = solve(v);
    for(int x:ans)
        cout << x << " ";
    cout << endl;
    return 0;
}
// 1 2 1 2 1 2 1
// 1-4
// 2-3
