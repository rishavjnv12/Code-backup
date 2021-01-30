#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>

using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    int c;

    try{
        if(b == 0)
            throw runtime_error("Divide by zero error");
        c = a/b;
        cout << "C is " << c << endl;
    }catch(runtime_error &error){
        cout << "Exception occured " << endl;
        cout << error.what();
    }

    return 0;
}