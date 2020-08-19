#include <iostream>

using namespace std;

inline int minimum(int x,int y){
    if (x < y) return x;
    else return y;
}

inline int maximum(int x,int y){
    if (x > y) return x;
    else return y;
}

int main(){
    int x=9;
    int y=7;
    cout<<minimum(x,y)<<endl;

    return 0;
}