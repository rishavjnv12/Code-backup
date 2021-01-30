#include <bits/stdc++.h>
using namespace std;

template <typename T>
class maxFreqStack{
private:
    unordered_map<T,int> freq;
    unordered_map<int,stack<T>> m;
    int mx = 0;
public:
    void push(T x){
        freq[x]++;
        mx = max(mx,freq[x]);
        m[freq[x]].push(x);
    }
    T pop(){
        int x = m[mx].top();
        m[mx].pop();
        if(m[mx].empty())
            mx--;
        freq[x]--;
        return x;
    }
};
vector<int> solve(vector<vector<int> > A) {
    vector<int> ans;
    maxFreqStack <int> stk;
    for(auto op:A){
        if(op[0] == 1){
            stk.push(op[1]);
            ans.push_back(-1);
        }else{
            ans.push_back(stk.pop());
        }
    }
    return ans;
}

int main(){
    auto ans = solve({
        {1,4},
        {2,0},
        {1,9},
        {2,0},
        {1,6},
        {1,6},
        {2,0}
    });
    for(int x:ans)
        cout << x << " ";
    cout << endl;
    return 0;
}