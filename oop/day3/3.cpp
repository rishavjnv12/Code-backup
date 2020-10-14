#include <bits/stdc++.h>

using namespace std;

class B;

class A{
    private:
        int data1;
        friend void add(A, B);

    public:
        void getData(int num1)
        {
            data1 = num1;
        }
};

class B{
    private:
        int data2;
        friend void add(A, B);

    public:
        void getData(int num2)
        {
            data2 = num2;
        }
};

void add(A num1, B num2){
    cout << "Sum: " << num1.data1 + num2.data2 << endl;
}

int main(){
    A num1;
    B num2;
    int a, b;
    cout << "Enter A, B: ";
    cin >> a >> b;
    num1.getData(a);
    num2.getData(b);
    add(num1, num2);
    return 0;
}