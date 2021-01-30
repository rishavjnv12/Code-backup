#include <bits/stdc++.h>
using namespace std;
void print(vector<int> a){
    for(int x:a)
        cout << x << " ";
    cout << endl;
}
vector<int> solve(int n){
    if(n==1)
            return {1};
        vector<int> even = solve(n/2);
        vector<int> odd = solve(n-(n/2));
        vector<int>ans;
        
        for(auto e:even)
            ans.push_back(2*e);
        for(auto e:odd)
            ans.push_back((2*e)-1);
        return ans;
}
int main(){
    int n;
    cin >> n;
    solve(n);
    return 0;
}