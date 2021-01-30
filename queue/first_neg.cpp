#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &v,int b){
    const int n = v.size();
    vector<int> ans;
    deque<int> d;
    for(int i=0;i<b;i++){
        if(v[i]<0)
            d.push_back(i);
    }
    
    for(int i=b;i<=n;i++){
        while(d.size() and d.front()<i-b)
            d.pop_front();
        if(d.empty())
            ans.push_back(0);
        else ans.push_back(v[d.front()]);
        if(i<n and v[i]<0)
            d.push_back(i);
        
    }
    return ans;

}
int main(){
    vector<int> v = {-1, 2, 3, -4, 5};
    int b = 2;
    auto ans = solve(v,b);
    for(int x:ans)
        cout << x << " ";
    cout << endl;
    return 0;
}