#include <iostream>

using namespace std;

double power(double x,int p=2){
    double ans=1;
    for(int i=0;i<p;i++){
        ans*=x;
    }
    return ans;
}

int main(){

    int q;
    cout<<"Enter number of queries:";
    cin>>q;
    while(q--){
        double x;
        int p;
        cout<<"Enter x:";
        cin>>x;
        cout<<"Enter p:";
        cin>>p;
        if(p==2){
            cout<<x<<"^"<<p<<"="<<power(x)<<endl;
        }else{
            cout<<x<<"^"<<p<<"="<<power(x,p)<<endl;
        }
    }

    return 0;
}