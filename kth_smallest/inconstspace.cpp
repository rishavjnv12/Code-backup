#include<bits/stdc++.h>
using namespace std;
int kthSmallest(vector<int> arr,int k){
    int hi=*max_element(arr.begin(),arr.end());
    int lo=*min_element(arr.begin(),arr.end());
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        int lesser=0,equal=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<mid) lesser++;
            else if(arr[i]==mid) equal++;
        }
        if(lesser<k and (equal+lesser)>=k){
            return mid;
        }else if(lesser>=k){
            hi=mid-1;
        }else if(lesser<k and (equal+lesser)<k){
            lo=mid+1;
        }
    }
    return -1;
}
int increment(int x){return x+2;};
int main(){
    vector<int>arr ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
    time_t time;
    shuffle(arr.begin(),arr.end(),default_random_engine(time));
    transform(arr.begin(),arr.end(),arr.begin(),increment);
    for(int i=0; i<arr.size(); i++){
        cout << arr[i]<<" ";
    }
    cout << endl;
    int k;
    cout<<"Enter k:"<<endl;
    cin>>k;
    cout<<"Answer is "<<kthSmallest(arr,k)<<endl;
    return 0;
}