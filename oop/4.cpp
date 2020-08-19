#include <iostream>
#include <string>

using namespace std;

class Student{
    private:
        string name;
        int roll_no;
        int marks;
    public:
        void set_details();
        void print_details();
        int get_marks();
};

void Student::set_details(){
    cout<<"Enter student name: ";
    cin.ignore();
    getline(cin,name);

    cout<<"Enter roll number: ";
    cin>>roll_no;
    
    cout<<"Enter marks: ";
    cin>>marks;
}
void Student::print_details(){
    cout<<"Name: "<<name<<endl;
    cout<<"Roll number: "<<roll_no<<endl;
    cout<<"Marks: "<<marks<<endl;
}

int Student::get_marks(){
    return marks;
}

Student find_topper(Student student[],int n){

    Student topper=student[0];
    int max_marks=student[0].get_marks();

    for(int i=0;i<n;i++){
        if(student[i].get_marks()>max_marks){
            topper=student[i];
            max_marks=student[i].get_marks();
        }
    }
    return topper;
}


int main(){
    int n;

    do{
        cout<<"Enter number of students(greater than zero):";
        cin>>n;
    }while(n<=0);
    cout<<endl;
    Student student[n];
    for(int i=0; i<n; i++){
        cout<<"\n\nEnter student #"<<i+1<<" details: "<<endl;
        student[i].set_details();
    }

    Student topper=find_topper(student,n);
    cout<<"\n\nTopper's details:-"<<endl;
    topper.print_details();

    return 0;
}