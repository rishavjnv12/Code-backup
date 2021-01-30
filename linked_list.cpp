#include <bits/stdc++.h>
using namespace std;

struct List{
    int val;
    List* next;
};

List* head = nullptr;
int sz = 0;
List* new_node(int x){
    List* temp = new List();
    temp->val = x;
    temp->next = nullptr;
    return temp;
}

void print_ll(List* head){
    auto ptr = head;
    while(ptr){
        printf("%d ",ptr->val);
        ptr=ptr->next;
    }
}
void insert(int pos,int ele){
    if(pos>sz+1)
        return;
    if(pos == 1){
        List* temp = new_node(ele);
        temp->next = head;
        head = temp;
    }else{
        auto ptr = head;
        auto node = new_node(ele);
        for(int i=0;i<pos-2;i++){
            ptr=ptr->next;
        }
        auto temp = ptr->next;
        node->next = temp;
        ptr->next = node;
    }
    sz++;
    assert(head!=nullptr);
}

void delete_node(int pos){
    if(pos>sz)
        return;
    sz--;
    if(pos == 1){
        auto temp = head;
        head = head->next;
        delete temp;
    }else{
        List* ptr = head;
        for(int i=0;i<pos-2;i++){
            ptr = ptr->next;
        }
        List* temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        char q;
        cin >> q;
        if(q == 'i'){
            int pos,ele;
            cin >> pos >> ele;
            insert(pos,ele);
        }else if(q == 'd'){
            int pos;
            cin >> pos;
            delete_node(pos);
        }else{
            print_ll(head);
            printf("\n");
        }
    }
    return 0;
}