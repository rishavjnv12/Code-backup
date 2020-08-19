 /*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.
21 is read off as one 2, then one 1 or 1211.
Given an integer n, generate the nth sequence.
Note: The sequence of integers will be represented as a string.
Example:
if n = 2,
the sequence is 11.
1, 11, 21, 1211, 111221, 312211, 13112221, 1113213211, 31131211131221, 13211311123113112211, 11131221133112132113212221, 3113112221232112111312211312113211,
1321132132111213122112311311222113111221131221, 11131221131211131231121113112221121321132132211331222113112211, 
311311222113111231131112132112311321322112111312211312111322212311322113212221
https://www.interviewbit.com/problems/count-and-say/
*/
#include <bits/stdc++.h>
using namespace std;
string fun(int n){
    string ans="11";
    if(!n) return "";
    if(n==1) return "1";
    if(n==2) return ans;

    for(int i=3;i<=n;i++){
        string temp = "";
        ans+='$';
        int count=1;
        for(int j=1;j<ans.size();j++){
            if(ans[j]!=ans[j-1]){
                temp+= count + '0';
                temp+=ans[j-1];
                count=1;
            }else{
                count++;
            }
        }
        ans=temp;
    }
    return ans;
}
int main(){
    int n=1;
    while(n<100){
        cout<<fun(n++)<<endl;
        for(int i=0;i<6;i++)
            cout<<endl;
    }
    return 0;
}



