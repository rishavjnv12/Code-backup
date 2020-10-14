#include <bits/stdc++.h>
using namespace std;
class Employee {
protected:
string name;
int salary;
friend class Boss;
public:
void getDetails(string n, int s) {
name = n;
salary = s;
}
void display() {
cout << endl << name << "\t" << salary << endl;
}
};
class Boss {
public:
void incrSalary(Employee emp, int amount) {
emp.salary += amount;
cout << "New salary: " << emp.salary << endl;
}
};
int main() {
Employee e;
Boss b;
int x;
e.getDetails("bablu", 20000);
e.display();
cout << "Enter increment amount: ";
cin >> x;
b.incrSalary(e, x);
return 0;
}