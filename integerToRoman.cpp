#include <bits/stdc++.h>
using namespace std;
string under_ten(int n){
    switch(n){
        case 0:return "";
        case 1: return "I";
        case 2: return "II";
        case 3: return "III";
        case 4: return "IV";
        case 5: return "V";
        case 6: return "VI";
        case 7: return "VII";
        case 8: return "VIII";
        case 9: return "IX";
        case 10: return "X";
    }
}
string under_hundred(int n){
    int x=n/10,y=n%10;
    switch(x){
        case 0: return ""+under_ten(y);
        case 1: return "X"+under_ten(y);
        case 2: return "XX"+under_ten(y);
        case 3: return "XXX"+under_ten(y);
        case 4: return "XL"+under_ten(y);
        case 5: return "L"+under_ten(y);
        case 6: return "LX"+under_ten(y);
        case 7: return "LXX"+under_ten(y);
        case 8: return "LXXX"+under_ten(y);
        case 9: return "XC"+under_ten(y);
        case 10: return "C"+under_ten(y);
    }
}
string under_thousand(int n){
    int x=n/100,y=n%100;
    switch(x){
        case 0: return ""+under_hundred(y);
        case 1: return "C"+under_hundred(y);
        case 2: return "CC"+under_hundred(y);
        case 3: return "CCC"+under_hundred(y);
        case 4: return "CD"+under_hundred(y);
        case 5: return "D"+under_hundred(y);
        case 6: return "DC"+under_hundred(y);
        case 7: return "DCC"+under_hundred(y);
        case 8: return "DCCC"+under_hundred(y);
        case 9: return "CM"+under_hundred(y);
        case 10: return "M"+under_hundred(y);
    }
}
string remaining_all(int n){
    int x=n/1000,y=n%1000;
    switch(x){
        case 1: return "M"+under_thousand(y);
        case 2: return "MM"+under_thousand(y);
        case 3: return "MMM"+under_thousand(y);
        case 4: return "MMMM"+under_thousand(y);
    }
}
string intToRoman(int n) {
    if(n<=10)
        return under_ten(n);
    if(n<=100)
        return under_hundred(n);
    if(n<=1000)
        return under_thousand(n);
    return remaining_all(n);
}


int main(){
    /*int num=-1;
    while(num<1 or num>3999){
        cout<<"Enter a number:";
        cin>>num;
    }*/
    for(int i=1;i<=4999;i++){
        cout<<i<<":     "<<intToRoman(i)<<endl;
    }
    return 0;
}