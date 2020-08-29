#include <iostream>
#include <iomanip>

using namespace std;

class Time{
    private:
        int hour;
        int minute;
        int second;
    public:
        void showTime();
        void setTime(int,int,int);
        void addTime(Time);
        Time();
};

void Time::showTime(){
    cout<<setfill('0')<<setw(2);
    cout<<hour<<":";
    cout<<setfill('0')<<setw(2);
    cout<<minute<<":";
    cout<<setfill('0')<<setw(2);
    cout<<second<<endl;
}

void Time::setTime(int h,int m=0,int s=0){

    if (h<0 or m>=60 or m<0 or s>=60 or s<0){
        cout<<"Invalid time"<<endl;
        return;
    }

    hour=h;
    minute=m;
    second=s;
}

void Time::addTime(Time t){
    second+=t.second;
    minute+=(t.minute+second/60);
    hour+=(t.hour+minute/60);
    minute%=60;
    second%=60;
}

Time::Time(){
    hour=0;
    minute=0;
    second=0;
}

int main(){
    Time t,t2;
    t.setTime(13,51,6);

    cout<<"Time 1:";
    t.showTime();
    
    t2.setTime(3,51,59);

    cout<<"Time 2:";
    t2.showTime();
    t.addTime(t2);

    cout<<"Time 1 + Time 2:";
    t.showTime();
    return 0;
}