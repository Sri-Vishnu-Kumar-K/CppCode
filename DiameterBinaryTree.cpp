#include<iostream>
#include<cstdio>
using namespace std;

int max(int a,int b){
    return a>=b?a:b;
}

class node{
    public:
    int val;
    int dia;
    node* left;
    node* right;
    node(int);
};

node::node(int v){
    val = v;
    dia = 0;
    left = NULL;
    right = NULL;
}

int diameter(node* root){
    if(root->right == NULL && root->left == NULL){
        return 1;
    }else if(root->right != NULL && root->left != NULL){
        root->dia = 1+max(diameter(root->right),diameter(root->left));
        return root->dia;
    }else if(root->right != NULL && root->left == NULL){
        root->dia = 1+diameter(root->right);
        return root->dia;
    }else if(root->right == NULL && root->left != NULL){
        root->dia = 1+diameter(root->left);
        return root->dia;
    }
    return 0;
}

int maxi = 0;
void print(node* root){
    if(root != NULL){
        cout<<root->val<<" "<<root->dia<<endl;
    }
    if(root->left != NULL){
        print(root->left);
    }
    if(root->right != NULL){
        print(root->right);
    }
}

void maxer(node* root){
    if(root->left!= NULL && root->right != NULL){
        if(maxi < root->left->dia + root->right->dia + 1){
            maxi = root->left->dia + root->right->dia + 1;
            cout<<maxi<<endl;
        }
    }
    if(root->left != NULL){
        if(maxi< root->left->dia + 1){
            maxi = root->left->dia + 1;
            cout<<maxi<<endl;
        }
        maxer(root->left);
    }
    if(root->right != NULL){
        if(maxi< root->right->dia + 1){
            maxi = root->right->dia + 1;
            cout<<maxi<<endl;
        }
        maxer(root->right);
    }
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(3);
    root->right->right = new node(4);
    //root->left->left->left = new node(5);
    //root->left->right->right = new node(6);
    diameter(root);
    print(root);
    maxer(root);
    return 0;
}
