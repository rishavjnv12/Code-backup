#include <bits/stdc++.h>
using namespace std;
pair<string,int> dividebytwo(string str){
    string temp="";
    int num=0;
    int rem=0;
    for(int i=0,num=0;i<str.length();i++){
        num=rem*10+(str[i]-'0');
        if(num>=2){
            temp+=to_string(num/2);
            rem=num%2;
        }else if(i<str.length()-1){
            if(i!=0)
                temp+="0";
            num=num*10+(str[i+1]-'0');
            temp+=to_string(num/2);
            rem=num%2;
            i++;
        }else{
            rem=num;
            temp+="0";
        }
    }
    return make_pair(temp,rem);
}
int ispoweroftwo(string s){
    while(s!="1"){
        pair<string,int> temp=dividebytwo(s);
        if(temp.second==1)
            return 0;
        else s=temp.first;
    }
    return 1;
}
int main(){
    string q;
    cin>>q;
    //cout<<dividebytwo(q).first<<endl;
    //cout<<dividebytwo(q).second<<endl;
    cout<<ispoweroftwo(q)<<endl;
    main();
    return 0;
}
/*

    2,4



*/

