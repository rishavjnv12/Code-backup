#include <iostream>
using namespace std;

int main(){
    int t=rand()%100;
    cout<<t<<endl;
    while(t--){
        int n=rand()%10;
        cout<<n<<endl;
        while(n--){
            cout<<rand()%10<<" ";
        }
        cout<<endl;
    }
    return 0;
}