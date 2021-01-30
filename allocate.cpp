#include <bits/stdc++.h>
using namespace std;

int split(vector<int> &v,int max_page){
    int blk = 1;
    int curr = 0;
    for(int x:v){
        if(curr+x > max_page){
            blk++;
            curr = x;
        }else{
            curr+=x;
        }
    }
    return blk;
}

int books(vector<int> &a, int b){
    
    int l = *max_element(a.begin(),a.end());
    int r = accumulate(a.begin(),a.end(), 0);
    int ans=-1;
    while(l <= r){
        int mid = l+(r-l)/2;
        int cnt = split(a,mid);
        if(cnt <= b){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}
// 99 67 34 12
int main(){
    vector<int> a = {31, 14, 19, 75};
    // cout << is_possible(a, 99 , 1);
    cout << books(a,12) << endl;
    return 0;
}