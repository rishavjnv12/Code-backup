#include <iostream>
#include <string>

using namespace std;

class Person{
    private:
        string name;
        int age;
        string gender;
    public:
        void set_name(string x);
        void set_age(int x);
        void set_gender(string x);

        string get_name();
        int get_age();
        string get_gender();
};

string Person::get_name(){
    return name;
}

int Person::get_age(){
    return age;
}

string Person::get_gender(){
    return gender;
}

void Person::set_name(string x){
    name = x;
}

void Person::set_age(int x){
    age=x;
}
void Person::set_gender(string g){
    gender=g;
}

int main(){
    Person p1;

    p1.set_name("Binod Tharu");
    p1.set_age(20);
    p1.set_gender("male");

    cout<<p1.get_name()<<endl;
    cout<<p1.get_age()<<endl;
    cout<<p1.get_gender()<<endl;
    return 0;
}
