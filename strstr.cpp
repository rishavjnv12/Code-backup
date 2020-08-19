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
    return -1;
}
int Solution::strStr(const string A, const string B) {
    if(A=="" or B=="") return -1;
    else return kmp_search(A,B);
}
