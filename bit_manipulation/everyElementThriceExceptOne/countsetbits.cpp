#include<bits/stdc++.h>
using namespace std;
vector <int> countSetBits(const vector<int> arr){
    vector <int>count(32,0);
    for(int i=0; i<arr.size(); i++){
        for(int j=0;j<32;j++){
            if(arr[i]&(1<<j))
                count[j]++;
        }
    }
    return count;
}
int mod(int x){return x%3;}
int search(const vector<int> arr){
    vector<int> count=countSetBits(arr);
    transform(count.begin(),count.end(),count.begin(),mod);
    int ans=0;
    for(int i=count.size()-1; i>=0;i--){
        ans+=(count[i]*pow(2,i));
    }
    return ans;
}
int main(){
    vector<int>arr={1,5,1,1,5,2,3,4,2,3,5,3,8,4,4,2};
    cout<<search(arr)<<endl;
    return 0;
}