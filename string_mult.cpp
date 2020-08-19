#include <bits/stdc++.h>
using namespace std;
string addstr(string s1,string s2){
    int len1=s1.length()-1;
    int len2=s2.length()-1;
    int carry=0;
    if(len1<len2){
        string temp=s1;
        s1=s2;
        s2=temp;
    }
    for(int i=0;i<abs(len1-len2);i++)
        s2="0"+s2;
    for(int i=s1.length()-1;i>=0;i--){
        int num=(s1[i]-'0')+(s2[i]-'0')+carry;
        s1[i]=(num%10)+'0';
        carry=num/10;
    }
    return (carry)?"1"+s1:s1;
}
string multdigit(string s,char c){
    int carry=0;
    for(int i=s.length()-1;i>=0;i--){
        int num=(s[i]-'0')*(c-'0')+carry;
        s[i]=(num%10)+'0';
        carry=num/10;
    }
    return (carry)?to_string(carry)+s:s;
}
string multiply(string s1, string s2) {
    vector <string> arr;
    reverse(s2.begin(),s2.end());
    for(int i=0;i<s2.length();i++){
        string temp=multdigit(s1,s2[i]);
        for(int j=0;j<i;j++)
            temp=temp+"0";
        arr.push_back(temp);
    }
    string ans="0";
    for(int i=0;i<arr.size();i++){
        ans=addstr(ans,arr.at(i));
    }
    ans.erase(0, ans.find_first_not_of('0'));
    return (ans=="")?"0":ans;
}
int main(){
    string s1,s2;
    cout<<"Enter 1st number:";
    cin>>s1;
    cout<<"Enter 2nd number:";
    cin>>s2;
    cout<<multiply(s1,s2)<<endl;
    return 0;
}