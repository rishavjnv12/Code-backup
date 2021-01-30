#include <bits/stdc++.h>
using namespace std;
string countAndSay(int n) {
    if (n == 0) return "";  
    if (n == 1) return "1";

    string prev = "1";
    string current = prev;

    for (int seqNum = 2; seqNum <= n; seqNum++) {    // run from starting to generate second string
        current.clear();
        for (int j = 0; j < prev.length(); j++) {
            int count = 1; // we have at least 1 occourence of each digit
            // get the number of times same digit occurred (be carefull with the end of the string)
            while ((j + 1 < prev.length()) && (prev[j] == prev[j + 1])) {
                count++;    
                j++;        // we need to keep increasing the index inside of the string
            }
            // 0123456
            // 1112211
            // add to new string "count" + "digit itself"
            current.append(to_string(count) + prev[j]);
        }
        prev = current;
    }
    return current;        
}
int main(){
    int n;
    cin >> n;
    cout << countAndSay(n) << endl;
    return 0;
}