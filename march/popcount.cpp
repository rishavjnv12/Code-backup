#include <iostream>
#define upto (1<<25)+1
using namespace std;
int arr[(1<<25)+1];
int main(){

    for(int i=0;i<((1<<25)+1);i++){
        arr[i]=__builtin_popcount(i);
        arr[i+1]=arr[i]+1;
    }

    for(int i=100000000;i>=upto;i--){
        cout<<(1+arr[i%(1<<25)])-__builtin_popcount(i)<<endl;
    }
    return 0;
}