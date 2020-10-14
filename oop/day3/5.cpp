#include <bits/stdc++.h>

using namespace std;

class tollBooth {
    private:
        int totalCars;
        int totalCash;
    public:
        tollBooth(): totalCars(0), totalCash(0) {}
        void nopayCar() {
            totalCars++;
        }
void payingCar() {
totalCars++;
totalCash++;
}
void display() {
cout << "Cars: " << totalCars << endl;
cout << "Money collected: " << totalCash << endl;
}
};
int main() {
tollBooth booth;
int n;
do {
cout << "Enter option: " << endl;
cout << "0 - Non-paying car" << endl;
cout << "1 - Paying car" << endl;
cout << "9 - Show chart and exit" << endl;
cin >> n;
if(n==0) {
booth.nopayCar();
} else if(n==1) {
booth.payingCar();
} else if(n==9) {
booth.display();
} else {
cout << "No action for this input" << endl;
}
} while(n != 9);
return 0;
}