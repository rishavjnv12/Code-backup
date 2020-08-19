//"This", "is", "an", "example", "of", "text", "justification."
//L 16
#include<bits/stdc++.h>
#define print(x) cout<<x<<endl
using namespace std;
vector<string> fun(vector<string> words,int L){
    int word_used=0;
    while(word_used<words.size()){
        int length=0;
        do{
            length+=(words[word_used++].size()+1);
            if(length==16)
                
        }while(length<L);
    }
}
int main(){
    vector<string> words;
    vector<string> justified;
    int len,L;
    print("number of words: ");
    cin>>len;
    for(int i=0;i<len;i++){
        print("Enter word: ");
        string temp;
        cin>>temp;
        words.push_back(temp);
    }
    print("Length of space:");
    cin>>L;
    justified=fun(words,L);
    for(int i=0;i<justified.size();i++){
        print(justified[i]);
    }
    return 0;
}