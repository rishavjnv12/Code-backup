#include <bits/stdc++.h>
using namespace std;
struct obj{
    int data;
};

int main(){
    obj x;

    //Shallow copy
    x.data = 10;
    obj y = x;
    y.data = 20;
    cout << x.data << endl;


    //Deep copy
    obj* a = new obj;
    a->data = 10;
    obj*b = a;
    b->data = 20;
    cout << b->data << endl;

    return 0;
}
