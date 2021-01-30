#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a = {2,5,2,76,43,75,222,4};
    priority_queue<int,vector<int>> pq;
    for(int x:a)
        pq.emplace(x);
    
    while(pq.empty() == false){
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}