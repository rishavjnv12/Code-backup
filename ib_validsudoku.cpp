#include <bits/stdc++.h>
using namespace std;
bool isvalid(vector<string> s){
    vector<map<char,bool>> ver(9);
    map<char,bool> box[3][3];
    map<char,bool> hor;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(s[i][j]=='.')
                continue;
            if(hor.find(s[i][j])!=hor.end()){
                return false;
            }else{
                hor[s[i][j]]=true;
            }
            if(ver[j].find(s[i][j])!=ver[j].end()){
                return false;
            }else{
                ver[j][s[i][j]]=true;
            }
            if(box[i/3][j/3].find(s[i][j])!=box[i/3][j/3].end()){
                return false;
            }else{
                box[i/3][j/3][s[i][j]]=true;
            }
        }
        hor.clear();
    }
    return true;
}
int main(){
    vector<string> sudoku={"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..7", "....8..79"};
    cout<<isvalid(sudoku)<<endl;
    return 0;
} 