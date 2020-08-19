#include <bits/stdc++.h>

using namespace std;

int main(){
    map<string,int> mymap;
    mymap.insert(make_pair("hello",69));
    mymap.insert(make_pair("apple",67));
    mymap.insert(make_pair("ball",66));
    mymap.insert(make_pair("cat",75));
    mymap.insert(make_pair("zxcv",56));
    mymap.insert(make_pair("asdf",46));
    mymap.insert(make_pair("qftg",26));
    mymap.insert(make_pair("ader",66));
    mymap.insert(make_pair("bhuj",46));
    mymap.insert(make_pair("bher",26));
    mymap.insert(make_pair("tder",16));
    mymap.insert(make_pair("apple",68));

    cout<<mymap.count("apple")<<endl;

    // cout<<mymap.max_size()<<endl;
    // cout<<mymap.size()<<endl;
    // cout<<mymap["ader"]<<endl;
    //mymap.clear();
    
    // for(auto itr=mymap.rbegin();itr!=mymap.rend();itr++){ //rbegin and rend for reverse iteration
    //     cout<<itr->first<<" "<<itr->second<<endl;
    // }

    // map <string,int> mymap2(mymap.begin(),mymap.end());
    // for(auto itr=mymap2.begin();itr!=mymap2.end();itr++){ //rbegin and rend for reverse iteration
    //     cout<<itr->first<<" "<<itr->second<<endl;
    // }
    return 0;
}