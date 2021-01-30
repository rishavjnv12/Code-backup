#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>

using namespace std;
class Error{
    string err;
public:
    void get(){
        cout << err << endl;
    }
    Error(string s){
        err = s;
    }
};
int main(){
    int a,b;
    cin >> a >> b;
    int c;

    try{
        if(b == 0)
            throw Error("Divide by zero");
        if(b==1)
            throw Error("Divide by one");
        c = a/b;
        cout << "C is " << c << endl;
    }catch(Error e){
        e.get();
    }

    return 0;
}
