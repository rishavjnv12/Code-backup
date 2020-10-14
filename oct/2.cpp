#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        int n,k,x,y;
        cin>>n>>k>>x>>y;
        unordered_set<int> st;
        bool found = false;
        int curr = x;
        while(true){
            if(curr == y){
                found = true;
                break;
            }
            if(st.count(curr)){
                break;
            }
            st.insert(curr);
            curr = (curr + k)%n;
        }
        if(found){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
