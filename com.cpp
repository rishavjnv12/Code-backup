#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {0,1,2,3};
    int ans = INT_MAX;
    vector<int> temp;
    vector<int> a = {4,6,10,2000};
    vector<int> b = {2,3,5,100};
    do{
        int cnt = 0;
        int sum = 0;
        for(int i=0;i<4;i++){
            sum += a[v[i]];
            cnt+=(sum*b[v[i]]);
        }
        if(cnt < ans){
            ans = cnt;
            temp = v;
        }

    }while(next_permutation(v.begin(),v.end()));
    cout << ans << endl;
    for(int x:temp)
        cout << x << " ";
    cout << endl;
    return 0;
}

// 3 7 4 5
// 2 1 2 4

