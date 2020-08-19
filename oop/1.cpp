#include <iostream>
#include <string>

using namespace std;

struct Student{
    string student_name;
    int roll_no;

    void set_details(){
        cout<<"Enter student name: ";
        getline(cin,student_name);
        cout<<"Enter roll number: ";
        cin>>roll_no;
    }

    void print_details(){
        cout<<"Name: "<<student_name<<endl;
        cout<<"Roll number: "<<roll_no<<endl;
    }
};

int main(){
    Student student;
    student.set_details();

    cout<<"student's information:-"<<endl;
    student.print_details();
    return 0;
}