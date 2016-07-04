#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

struct dlist{
    int data;
    dlist* next;
    dlist* prev;
};

node* newNode(int data){
    node* temp;
    temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

dlist* newDlistNode(int data){
    dlist* temp;
    temp = new dlist;
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;

}

dlist* spiralPrint(node* root){
    stack<struct node*> s1;
    stack<struct node*> s2;
    dlist* spiral = NULL;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            node* top = s1.top();
            s1.pop();
            cout<<top->data<<endl;
            if(spiral == NULL){
                spiral = newDlistNode(top->data);
            }else{
                dlist* temp = spiral;
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next = newDlistNode(top->data);
                dlist* temp1 = temp;
                temp = temp->next;
                temp->prev = temp1;
            }
            if(top->left!=NULL){
                s2.push(top->left);
            }
            if(top->right!=NULL){
                s2.push(top->right);
            }
        }
        while(!s2.empty()){
            node* top = s2.top();
            s2.pop();
            cout<<top->data<<endl;
            if(spiral == NULL){
                spiral = newDlistNode(top->data);
            }else{
                dlist* temp = spiral;
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next = newDlistNode(top->data);
                dlist* temp1 = temp;
                temp = temp->next;
                temp->prev = temp1;
            }
            if(top->right!=NULL){
                s1.push(top->right);
            }
            if(top->left!=NULL){
                s1.push(top->left);
            }
        }

    }
    return spiral;
}


int main(){
    node* root;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    dlist* head = spiralPrint(root);
    dlist* tail;
    while(head!=NULL){
        tail = head;
        cout<<head->data<<' ';
        head = head->next;
    }
    cout<<endl;
    dlist* temp = tail;
    while(temp!=NULL){
        cout<<temp->data<<' ';
        temp = temp->prev;
    }
    return 0;
}
