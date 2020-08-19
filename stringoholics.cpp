#include <bits/stdc++.h>
using namespace std;
vector<int> compute_lps(string pattern){
    int n=pattern.length();
    vector<int> lps(n,0);
    int len=0;
    for(int i=1;i<n;){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;   
        }else{
            if(len)
                len=lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
int kmp_search(string text,string pattern){
    int n=text.length();
    int m=pattern.length();
    vector<int> lps=compute_lps(pattern);
    //vector<int> result;
    int i=0;
    int j=0;
    while(i<n){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        if(j==m){
            return i-j;
            j=lps[j-1];
        }else if(i<n and pattern[j]!=text[i]){
            if(j)
                j=lps[j-1];
            else i++;
        }
    }
    //return 8876;
}
int countrotation(string s){
    string s1 = s.substr(1, s.size() - 1) + s;
    int ans=kmp_search(s1,s);
    return (ans==0)?s.size():ans;
}
long long lcm(long long a,long long b){
    return a*b/__gcd(a,b);
}
int solve(vector<string> &A) {
    vector<long long> nor;
    for(int i=0;i<A.size();i++){
        nor.push_back(countrotation(A[i]));
    }
    for(int i=0;i<nor.size();i++){
        cout<<" "<<nor[i]<<",";
    }
    long long  ans=1;
    for(int i=0;i<nor.size();i++){
        ans=lcm(ans,nor[i]);
    }
    return ans;
}
int main(){
    vector<string> q={"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
     "babaaaabbaba", "baaaaababaabbaaaaabbbbbbbaabbaaaababbabaababaabaaabbbaaaaa",
      "abaabb", "aababbbbabbaaaabbaaaaaaaababbbabbbbaabbaabaabbaabaababbbababaababaabbababaaabaaaab",
       "babaaaaababbbbbabbbbabbaaabaaaababbabbaabbbabbaaaabbbabaaaabaaaababb",
        "bbbbbbaaaaaabbbbbbababaabaabbbbbaaabbabbaabbbbaaaaaababbabaaabbabbabbbabbaabbabbbbaabbbaaaaabbabaaab",
         "aabaaabaabbbbababbabbabaaaababbababbbabbbbaabbaaaaababbbbbababbbbaaababababab", "aaaababbbaabbbabaabb",
          "ababaaaabbabbbbaaabbababbbabbbabaaa", "aaabaabbbabaa", "baababbababbbbbabbabaabbabbbbbaaaabaaaababaa",
           "babaa", "abbabababbbbbbbbbbbaaaaaababbababaaabbbaaaabbbababbabaabbaabbbbaabbbaabbababababaabaaabbaaabbba",
            "ababbaabbaaabbbabaabababbbabaaabbbaababaaa", "abbaaaababbbbaaabaaaabaaaaabaababbabbaababbbabbbbbbbbbabbaabaaabbaaababbbaa",
             "bbabababaabbabbabbbabbaababbabaaabbbababab", "abbbaaabaab", "bbaaabbaaabbaabbabababa",
              "aabaabaaaaaaabaabbbaaababbbbbbababbaabababbaaaaabbabbbabbbaababbaabababbbbbbbbbaabaab", "babbaaabbabbaabaaabbb", "bbabaabba",
               "baabaaaaabbaaaaaabbbbaaaabababa", "babbaababaaba", "baabaabaabbababbaabbabbbbbabaaaabbbbbabbabbbbbabbbabaabbbbabbbbaaabbbbabababaaaababbaaabbabb",
                "abbbbaaaabaabbabbaababaabbababbbaaabbabbbbbaaabbabbaabbb", "bababaaaaabababbabbaabababbbaabbaabaabaabbabbbababbaaabababbababbbb",
                 "abaaabbbabbbaabba", "bbbbaaaabbbababaabbbababaaaababbaaaaaabbbabbaababababbba",
                  "bababaabaaaabbaabbababbaabbaabaabbaaaaaaaababbaaaaaabbaaabaabaaababbababbbbaabbabbabaabab",
                   "aabbbabaaabababaabbbbaabbabaaabbbaaabbabbbbabaabbbbaabbbaaaaabbbabbbbb",
                    "aabbbbbbabaabbbabbaababbababaabaaababbbbabbbaababaaaabbaaabaaabaaaabbbabababbab",
                     "abaaaaababbabaabbbaaaaabbaaaabaaaaaaaababbaabbbaabbabbbabbaaaaaab",
                      "bbbaabbabbbbbbaaaabbabbbbbbbaaabaababbaaaabbbaababbaaabbbbbbbbabbabababbaaabaabaaabaaaabbbbbabaabaaa",
                       "bbaaabaaabaaabaabaaabbaabaabbabaabaabbababaaaaabaabbbbaba", "abaababaaabbabaabaabbbaaabbaabababbabaaabbbbabbbbbaaaaa",
                        "abba", "abbbababbaaabbaaabbbabaabbababaaabbbbaaaaababbabbaabbabbbaaabaabbaaaaabaaaabbbaabbbabbbbbbbabb",
                         "bbabbaaabaaaabbaaaabbbaaaababbbaabaaaaab", "abbaabaabbaaaaaaaabbaabbabbababaaaaaaabbabaabaabbbabbaabbaababbaabbaba",
                          "bbbbaababbaaaaaaaaabbbabbbabaabababaababaababa",
                           "baaabaabbbbbbaabbabbbabaaaaababaabaababbbaaaaaaaabbbbbabbabaaaaaaaabababaabaababaaabbaaaaaaaaabaa",
                            "aababbbabbaaaaababbabaababbbbbbbbaaabbaaaaabbaabbbba", "ababababaaaaaabbbabbaaababaabb",
                            "bababbaababaabbbabbaab", "baababababbaaaaabbbbbbbbbaabababb", "bbbbb",
                             "aabaabbbaabababbababaaaaabbbbaababaabbabbbbbbaabbaaabbababbbabbabbbaabbbab",
                              "bbaabbbbaabbaaaaaabbbaabababbbaabaaabbbbbabaababbbaababbbaaabaaabaaaababbbbaabbaababb", "aaababbaaaaabaabababbabaabbbbabbaba"};
    cout<<solve(q)<<endl;
    return 0;
}