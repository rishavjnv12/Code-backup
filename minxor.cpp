#include <bits/stdc++.h>
using namespace std;
int minxor(vector<int> V){
    sort(V.begin(), V.end());
    int min=V[0]^V[1];
    for(int i=1;i<V.size()-1;i++){
        int temp=V[i]^V[i+1];
        if(temp<min)
            min=temp;
    }
    return min;
}
int main(){
    vector<int> V={0,2,5,7};
    vector<int> W={0,4,7,9};
    cout<<minxor(W)<<endl;
    return 0;
}