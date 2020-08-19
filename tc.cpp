#include <bits/stdc++.h>
using namespace std;
int get(){
    return 1+rand()%15;
}
void print(vector<int> x){
    for(int i=0; i<x.size();i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t=10;
    cout<<10<<endl;
    while(t--){
        int n=0;
        vector<int> v;
        int c=1+rand()%5;
        for(int i=0;i<c;i++){
            int x=get();
            int f=1+rand()%2;
            for(int i=0;i<2*f;i++){
                v.push_back(x);
            }
        }
        vector<int> x,y;
        for(int i=0;i<v.size();i++){
            if(i<v.size()/2)
                x.push_back(v[i]);
            else y.push_back(v[i]);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        cout<<x.size()<<endl;
        print(x);
        print(y);
    }
}