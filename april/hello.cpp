#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        cpp_int a,b,c;
        cin>>a>>b>>c;
        cpp_int x=c/a;
        cpp_int y=a*x+b;
        if(y<=c) cout<<y<<"\n";
        else cout<<y-a<<"\n";
    }
    return 0;
}