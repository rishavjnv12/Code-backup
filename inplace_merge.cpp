#include <bits/stdc++.h>
using namespace std;
vector<int> merge(vector <int> a,int m,vector<int> b,int n){
    int x = m+n-1;
    int i = m-1;
    int j = n-1;
    while(i>=0 and j>=0){
        if(a[i]>b[j]){
            a[x] = a[i];
            i--;
        }else{
            a[x] = b[j];
            j--;
        }
        x--;
    }
    while(i>=0){
        a[x] = a[i];
        i--;
        x--;
    }
    while(j>=0){
        a[x] = b[j];
        j--;
        x--;
    }
    return a;
}
int main(){
    vector<int> a = {4,7,9,11,0,0,0,0};
    vector<int> b = {1,5,10,12};
    auto ans = merge(a,4,b,4);
    for(int x:ans)
        cout << x << " ";
    cout << endl;
    return 0;
}