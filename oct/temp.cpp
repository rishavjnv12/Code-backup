#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n,k,x,y;
        cin>>n>>k>>x>>y;
        int c=0;
        int curr = x;
        bool found = true;
        set<int> s;
        while(s.count(curr)==0){
            if(s.count(curr)==0){
                s.insert(curr);
                if(curr == y){
                    cout<<"YES"<<endl;
                    found=true;
                    break;
                }
                curr = (curr+k)%n;
                c++;
            }
        }
        if(s.find(y) == s.end())
            cout<<"NO"<<endl;
    }
    return 0;
}