#include<iostream>
using namespace std;

struct node{
        int data;
        node *right;
        node *left;
};

class bst{
public:
    node *root;
    bst(){
        root=NULL;
    }
    int ins(int val){
        if(root==NULL){
            root = new node;
            root->data=val;
            root->left=NULL;
            root->right=NULL;
            return 0;
        }else{
            node *temp;
            node *p;
            temp = root;
            p = temp;
            while(temp!=NULL){
                p = temp;
                if(val > temp->data){
                    temp = temp->right;
                }else{
                    temp = temp->left;
                }
            }
                node *n;
                n = new node;
                n->data=val;
                n->right=NULL;
                n->left=NULL;
            if(val<p->data){
                p->left=n;
            }else{
                p->right=n;
            }
        }
        return 0;
    }
    int sorter(node *n){
        if(n!=NULL){
            sorter(n->left);
            cout<<n->data;
            sorter(n->right);
        }
        return 0;
    }
    int sort(){
        sorter(root);
        return 0;
    }
};

int main(){
    bst t;
    int n;
    int dat;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>dat;
        t.ins(dat);
    }
    t.sort();
    return 0;
}
