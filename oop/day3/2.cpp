#include <bits/stdc++.h>

using namespace std;

class Student{
    private:
        int collegeID;
        string first;
        string middle;
        string last;
        static int count;

    public:
        Student(int cid, string fname){
            cout << "Constructing..." << endl;
            collegeID = cid;
            first = fname;
        }
        Student(int cid, string fname, string mname){
            cout << "Constructing..." << endl;
            collegeID = cid;
            first = fname;
            middle = mname;
        }
        Student(int cid, string fname, string mname, string lname){
            cout << "Constructing..." << endl;
            collegeID = cid;
            first = fname;
            middle = mname;
            last = lname;
        }
    void display(){
        cout << collegeID << " " << first << " " << middle << " " << last << endl;
    }
    ~Student(){
        cout << "Destructing..." << endl;
    }
};
int main()
{
    Student *stdptr0 = new Student(1, "rishav");
    Student *stdptr1 = new Student(2, "atul kumar");
    Student *stdptr2 = new Student(3, "rishav kumar");
    Student *stdptr3 = new Student(4, "sunny kumar mishra");
    Student *stdptr4 = new Student(5, "amit kumar");

    stdptr0->display();
    stdptr1->display();
    stdptr2->display();
    stdptr3->display();
    stdptr4->display();

    delete stdptr0;
    delete stdptr1;
    delete stdptr2;
    delete stdptr3;
    delete stdptr4;

    return 0;
}
