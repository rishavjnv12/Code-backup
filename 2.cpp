#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
vector<int> solve(int A, vector<vector<int> > B, vector<int> C) {
    vector<int> candies(A);
    for(int i=0;i<B.size();i++){
        int l=B[i][0]-1,r=B[i][1]-1;
        candies[l]+=1;
        if((r+1)<A)
            candies[r+1]-=1;
    }
    for(int i=1;i<A;i++){
        candies[i]=candies[i]+candies[i-1];
    }
    int n=1e5;
    vector<int> m(n+1);
    for(int x:candies){
        m[x]++;
    }
    for(int i=n-1;n>=0;i--){
        m[i]+=m[i+1];
    }
    int size=C.size();
    vector<int> ans(size);
    for(int i=0;i<size;i++){
        ans[i]=m[C[i]];
    }
    return ans; 
}
int main(){
    auto ans =  solve(4, {{1,2},{4,4},{1,3}},{1,2,3});
    for(int x:ans) cout << x << " ";
    cout << endl;
    cout << cnt << endl;
    return 0;
}