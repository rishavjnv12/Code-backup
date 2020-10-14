#include <iostream>

using namespace std;
const float PI=3.14159;

class Shape{
    public:
        void area(int x){
            cout<<"Area of square with side "<<x<<" is "<<x*x<<endl;
        }
        void area(int x, int y){
            cout<<"Area of rectangle with dimension "<<x<<","<<y<<" is "<<x*y<<endl;
        }
        void area(double r){
            cout<<"Area of circle with radius "<<r<<" is "<<PI*r*r<<endl;
        }
};


int main(){
    Shape square,rectangle,circle;

    square.area(5);
    rectangle.area(5,6);
    circle.area(4.2);

    return 0;
}

