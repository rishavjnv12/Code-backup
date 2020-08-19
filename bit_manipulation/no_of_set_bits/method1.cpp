//using gcc built-in function
#include <iostream>
using namespace std;
int main(){
    unsigned int num;
    cout << "Enter number:";
    cin>>num;
    cout<<"Set bits in "<<num<<" is "<<__builtin_popcount(num)<<endl;
    return 0;
}