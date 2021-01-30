#include <bits/stdc++.h>
using namespace std;
void sort(vector<int> &a){
    sort(a.begin(),a.end());
}
int b_search()
int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        sort(a);
        sort(b);
        sort(c);
        sort(d);
        const int n = a.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans+=b_search(c,d,-(a[i]+b[j]));
            }
        }
}
