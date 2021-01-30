#include <bits/stdc++.h>
using namespace std;

vector<int> fun(vector<int> &v){
int neg = -1;
    v.push_back(-1);
    int ans = 0;
    vector<int> idx;
    for(int i=0;i<v.size();i++){
        if(v[i]<0){
            int curr = i-neg-1;
            if(curr>ans){
                ans = curr;
                idx = {neg+1,i-1};
            }
            neg = i;
        }
    }
    vector<int> res;
    for(int i=idx[0];i<=idx[1];i++){
        res.push_back(v[i]);
    }    
    return res;
}

int main(){//        0 1 2 3 4 5 6 7 8 9,10,11,12
    vector<int> v = {5,6,-1,7,8,8,9,-4,7,8,9,-9,-9,7,9,9,9,9,9,9,-6};
    auto ans = fun(v);
    for(int &x:ans)
        cout << x<< " ";
    cout << endl;
    return 0;
}