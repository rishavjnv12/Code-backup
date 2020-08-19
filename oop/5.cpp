#include <iostream>
#include <string>

using namespace std;

class Account{
    private:
        string name;
        int ac_number;
        int balance;
    public:
        void init(string name, int ac_number, int balance);
        void deposit(int x);
        void withdraw(int x);
        void ac_info();
};

void Account::init(string name, int ac_number, int balance=0){
    if(balance<0){
        cout<<"Invalid balance"<<endl;
        return;
    }
    this->name = name;
    this->ac_number = ac_number;
    this->balance = balance;
    cout<<"Account created successfully"<<endl;
    this->ac_info();
}

void Account::deposit(int x){
    if(x<=0){
        cout<<"Invalid Amount!"<<endl;
        return;
    }
    balance += x;
    cout <<"Deposited successfully"<<endl;
}

void Account::withdraw(int x){

    if(x<=0){
        cout<<"Invalid Amount!"<<endl;
        return;
    }

    if(x>balance){
        cout<<"Insufficient Balance"<<endl;
    }else{
        balance -= x;
        cout<<"Withdrawn successfully"<<endl;
    }
}

void Account::ac_info(){
    cout<<"Name: "<<name<<endl;
    cout<<"Account Number: "<<ac_number<<endl;
    cout<<"Balance: "<<balance<<endl;
}

int main(){
    Account ac1;
    
    ac1.init("Rishav Kumar",1001,1000);

    int amount;

    cout<<"Enter amount to deposite: ";
    cin>>amount;
    ac1.deposit(amount);

    ac1.ac_info();

    cout<<"Enter amount to withdraw: ";
    cin>>amount;
    ac1.withdraw(amount);

    ac1.ac_info();

    cout<<"Enter amount to withdraw: ";
    cin>>amount;
    ac1.withdraw(amount);

    ac1.ac_info();


    return 0;
}