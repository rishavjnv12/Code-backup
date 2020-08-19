#include <bits/stdc++.h>
using namespace std;
int fact(int n){
    return n==0?1:n*fact(n-1);
}
void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) return;
        /*if(is_sorted(nums.begin(),nums.end())){
            swap(nums[nums.size()-1],nums[nums.size()-2]);
            return;
        }
        else{*/
    if(is_sorted(nums.begin(),nums.end(),greater<int>())){
        reverse(nums.begin(),nums.end());
    }
    int idx;
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]>nums[i-1]){
            idx=i;
            break;
            
        }
    }
    int temp=nums[idx-1];
    int min_idx=idx;
    for(int i=idx+1;i<nums.size();i++){
        if(nums[i]<nums[min_idx] and nums[i]>temp)
            min_idx=i;
    }
    swap(nums[idx-1],nums[min_idx]);
    sort(nums.begin()+idx,nums.end());
        //}
}
int main(){
    vector<int> nums={1,2,3,4,5};
    cout <<"hello"<<endl;
    int x=fact(nums.size());
    for(int i=0;i<x;i++){
        for(int i=0;i<nums.size();i++){
            cout << nums[i]<<" ";
        }
        nextPermutation(nums);
        cout<<endl;
    }
    return 0;
}


//1,1+2,1+2+4,1+2+4+8,1+2+4+8+16,1+2+4+8+16+32
//(0 to n)sigma(pow(2,i))
// s(n)=