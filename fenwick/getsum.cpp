#include <bits/stdc++.h>
using namespace std;

int bit_arr[100001];

void add(int idx,int val,int len){
    while(idx<=len){
        bit_arr[idx]+=val;
        idx+=(idx & (-idx));
    }
}
int get_sum(int idx){
    int result=0;
    while(idx){
        result+=bit_arr[idx];
        idx-=(idx & (-idx));
    }
    return result;
}

int main(){
    vector<int> arr={1,7,3,0,5,8,3,2,6,2,1,1,4,5};
    int len=arr.size();
    for(int i=0;i<len;i++){
        add(i+1,arr[i],len);
    }
    for(int i=1;i<=len;i++){
        cout<<bit_arr[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=len;i++){
        cout<<get_sum(i)<<" ";
    }
    return 0;
}