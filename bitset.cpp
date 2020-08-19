#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/stdio_sync_filebuf.h>
#include <boost/filesystem.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main(){
    bitset<10> x("1010101000");

    for(int i=0;i<10;i++){
        cout<<x[i]<<" ";
    }
    cout<<sizeof(x);
    cout<<"\n\n\n";


    indexed_set s;
    s.insert(2);
    s.insert(3);
    s.insert(7);
    s.insert(9);
    auto y=s.upper_bound(2);
    cout<<*y;
    return 0;
}