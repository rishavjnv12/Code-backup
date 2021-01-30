#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &v,int l,int mid,int r){
    int m = mid-l+1;
    int n = r-mid;
    int left[m],right[n];
    for(int i=0;i<m;i++){
        left[i] = v[i+l];
    }
    for(int i=0;i<n;i++){
        right[i] = v[mid+1+i];
    }
    int i=0,j=0,x=l;
    while(i<m and j<n){
        if(left[i]<right[j]){
            v[x] = left[i];
            i++;
        }else{
            v[x] = right[j];
            j++;
        }
        x++;
    }
    while(i<m){
        v[x] = left[i];
        x++;
        i++;
    }
    while(j<n){
        v[x] = right[j];
        j++;
        x++;
    }
}

void merge_sort(vector<int> &v,int l,int r){
    if(l<r){
        int m = l+(r-l)/2;
        merge_sort(v,l,m);
        merge_sort(v,m+1,r);
        merge(v,l,m,r);
    }
}

int main(){
    // vector<int> v = {5,2,546,32,78,42,21,54};
    vector<int> v={4,5,1,2,6,3};
    merge_sort(v,0,v.size()-1);
    for(int i=1;i<v.size();i++)
        assert(v[i]>=v[i-1]);
    for(int x:v)
        cout << x << " ";
    // cout << endl;
    return 0;
}