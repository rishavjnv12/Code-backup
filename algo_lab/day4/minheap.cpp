#include <bits/stdc++.h>

using namespace std;
int main(){
    vector<int>v={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    for(int i=0; i<100;i++)
        next_permutation(v.begin(),v.end());
    //to implement max heap, remove greater<int>
    priority_queue<int,vector<int>,greater<int> >q;
    
    for(auto i:v){
        q.push(i);
    }
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}