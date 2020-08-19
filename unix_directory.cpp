#include <bits/stdc++.h>
using namespace std;
bool fun(char a,char b){
    return a==b and a=='/';
}
string simplified(string s){
    s+='/';
    s.resize(distance(s.begin(),unique(s.begin(),s.end(),fun)));
    vector<string>str;
    string temp="";
    for(int i=1;i<s.size();i++){
        if(s[i]=='/'){
            str.push_back(temp);
            temp="";
        }else{
            temp+=s[i];
        }
    }
    stack<string> stk;
    for(int i=0;i<str.size();i++){
        if(str[i]==".."){
            if(!stk.empty())
                stk.pop();
        }
        else if(str[i]==".")
            continue;
        else 
            stk.push(str[i]);
    }
    temp="";
    while(stk.empty()==false){
        string temp2=stk.top();
        temp="/"+temp2+temp;
        stk.pop();
    }

    return (temp=="")?"/":temp;
}
int main(){
    string s1={"/./.././ykt/xhp/nka/eyo/blr/emm/xxm/fuv/bjg/./qbd/./../pir/dhu/./../../wrm/grm/ach/jsy/dic/ggz/smq/mhl/./../yte/hou/ucd/vnn/fpf/cnb/ouf/hqq/upz/akr/./pzo/../llb/./tud/olc/zns/fiv/./eeu/fex/rhi/pnm/../../kke/./eng/bow/uvz/jmz/hwb/./././ids/dwj/aqu/erf/./koz/.."
};
    cout<<simplified(s1)<<endl;
    return 0;
}