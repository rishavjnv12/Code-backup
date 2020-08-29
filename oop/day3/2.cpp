#include <bits/stdc++.h>

using namespace std;

class Student{
    private:
        int college_id;
        string fname;
        string mname;
        string lname;
    public:
        void detail();
        Student(string name,int id);


};

Student::Student(string name,int id){
    string temp="";
    college_id=id;
    fname=mname=lname="";
    for(int i=0;i<name.length();i++){
        if(name[i]==' '){
            if(fname==""){
                fname=temp;
                temp="";
            }else if(mname==""){
                mname=temp;
                temp="";
            }else{
                lname=temp;
                break;
            }
        }else {
            temp+=name[i];
        }
    }
    if(lname=="")
        lname=temp;
}

void Student::detail(){
    cout<<"College id:"<<college_id<<endl;
    cout<<"First name:"<<fname<<endl;
    cout<<"Middle name:"<<mname<<endl;
    cout<<"Last name:"<<lname<<endl;
}

int main(){
    Student s("Ankit Raj Rajpoot",100);
    s.detail();
    return 0;
}
