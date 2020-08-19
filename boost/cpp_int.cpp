#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace std;

int main(){
    cpp_int x=1;
    int y=10000;
    for(int i=1;i<=y;i++){
        x*=i;
    }
    cout<<"Factorial of "<<y<<" is "<<x<<endl;
    return 0;
}