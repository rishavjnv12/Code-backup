#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr,int l,int r){
    int i=l-1;
    int pivot=arr[r];
    for(int j=l;j<=r-1;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
int kthSmallest(vector<int>arr,int l, int r, int k){
    int index = partition(arr,l,r);
    if(index-l == k-1) return arr[index];
    if(index-l>k-1) return kthSmallest(arr,l,index-1,k);
    return kthSmallest(arr,index+1,r,k - index + l - 1);
}
int main(){
    vector<int>arr ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
    time_t time;
    shuffle(arr.begin(),arr.end(),default_random_engine(time));
    for(int i=0; i<arr.size(); i++){
        cout << arr[i]<<" ";
    }
    cout << endl;
    int k;
    cout<<"Enter k:"<<endl;
    cin>>k;
    cout<<"Answer is "<<kthSmallest(arr,0,arr.size()-1,k)<<endl;
    return 0;
}