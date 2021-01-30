#include <iostream>
#include <typeinfo>

using namespace std;
int main(){
    const float n = 7.0;
    cout << typeid(n).name() << endl;
    return 0;
}