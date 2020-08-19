#include <bits/stdc++.h>

using namespace std;
struct MinHeapNode{
    char data;
    int freq;
    MinHeapNode* left,*right;
    MinHeapNode(char data,int freq){
        this->data = data;
        this->freq = freq;
        this->left=nullptr;
        this->right=nullptr;
    }
};

struct compare{
    bool operator()(MinHeapNode* l,MinHeapNode* r){
        return l->freq>r->freq;
    }
};
void printCodes(MinHeapNode*root,string str){
    if(root==nullptr)
        return;

    if(root->data!='$')
        cout<<root->data<<":"<<str<<endl;

    printCodes(root->left,str+"0");
    printCodes(root->right,str+"1");
}
void Huffmancode(char arr[],int freq[],int n){
    struct MinHeapNode *left,*right,*top;
    priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare>minheap;
    for(int i=0;i<n;i++){
        MinHeapNode* temp= new MinHeapNode(arr[i],freq[i]);
        minheap.push(temp);
    }

    while(minheap.size()!=1){
        left=minheap.top();
        minheap.pop();

        right=minheap.top();
        minheap.pop();

        top=new MinHeapNode('$',left->freq+right->freq);
        top->left=left;
        top->right=right;
        
        minheap.push(top);
    }

    printCodes(minheap.top(),"");
}

int main(){
    char arr[]={'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[]={5,9,12,13,16,45};
    int size=sizeof(arr)/sizeof(arr[0]);
    Huffmancode(arr,freq,size);
    return 0;
}