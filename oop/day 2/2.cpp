#include <iostream>

using namespace std;

class Account{
    private:
        int ac_number;
        int balance;
    public:
        int get_balance();
        void deposit(int);
        void deduct(int);
        void init(int,int);
        void display();
        void moneyTransfer(Account &,int);
};

int Account::get_balance(){
    return balance;
}

void Account::deduct(int amount){
    if(amount<0){
        cout<<"Invalid amount"<<endl;
        return;
    }
    if(amount>balance){
        cout<<"Insuffient balance"<<endl;
        return;
    }
    balance -= amount;
}

void Account::deposit(int amount){
    if(amount<0){
        cout<<"Invalid amount"<<endl;
        return;
    }
    balance += amount;
}

void Account::init(int ac_number,int balance=0){
    if (ac_number<=0 or balance < 0){
        cout<<"Invalid Values"<<endl;
        return;
    }
    this->ac_number=ac_number;
    this->balance=balance;
}

void Account::display(){
    cout<<"Account number: "<<ac_number<<endl;
    cout<<"Balance: "<<balance<<"\n"<<endl;
}

void Account::moneyTransfer(Account &payer,int amount){
    if (amount < 0){
        cout<<"Invalid Amount"<<endl;
        return;
    }
    if (amount > payer.get_balance()){
        cout<<"Insufficient amount in payer's account"<<endl;
        return;
    }
    this->deposit(amount);
    payer.deduct(amount);
}

int main(){
    Account a1,a2;

    a1.init(100,1000);
    a2.init(101,1500);

    cout<<"\n\n";
    a1.display();
    a2.display();

    cout<<"\n\n";
    a1.moneyTransfer(a2,600);
    a1.display();
    a2.display();

    cout<<"\n\n";
    a1.moneyTransfer(a2,1000);
    a1.display();
    a2.display();

    return 0;
}