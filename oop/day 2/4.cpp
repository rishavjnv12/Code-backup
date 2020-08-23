#include <iostream>

using namespace std;

void order(int &x,int &y){
    if(x<y){
        int temp=x;
        x=y;
        y=temp;
    }
}

int main(){
    int x,y;
    cout<<"Enter x:";
    cin>>x;
    cout<<"Enter y:";
    cin>>y;

    order(x,y);

    cout<<"x:"<<x<<endl;
    cout<<"y:"<<y<<endl;

    return 0;
}