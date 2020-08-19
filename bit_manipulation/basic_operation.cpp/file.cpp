#include <iostream>
using namespace std;
int add(int m,int n){
        while(n){
            int carry=m&n;
            m^=n;
            n=carry<<1;
        }
        return m;
}
int main(){
    int num1,num2;
    cout<<"Enter numbers:";
    cin>>num1>>num2;
    cout<<add(num1,num2)<<endl;
    return 0;
}