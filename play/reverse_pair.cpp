#include <bits/stdc++.h>
using namespace std;
int ans;
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
    /***************/
    while(i<m and j<n){
        if(left[i]>2*right[j]){
            ans+=(mid-(i+l)+1);
            j++;
        }else{
            i++;
        }
    }
    /****************/
    i=0,j=0;
    while(i<m and j<n){
        if(left[i]<=right[j]){
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
void sort(vector<int> &v){
    ans = 0;
    merge_sort(v,0,v.size()-1);
}
int main(){
    vector<int> v={ 14046, 57239, 78362, 99387, 27609, 55100, 65536, 62099, 40820, 33056, 88380, 78549, 57512, 33137, 81212, 32365, 42276, 65368, 52459, 74924, 25355, 76044, 78056, 45190, 94365, 58869, 20611};
    // vector<int> v = {1,2,3,3,1};
    // for(int &x:v)
    //     cout << x << " ";
    // cout << endl;
    sort(v);
    // merge(v,0,3,4);
    for(int &x:v)
        cout << x << " ";
    cout << endl;
    cout << ans << endl;
    return 0;
}