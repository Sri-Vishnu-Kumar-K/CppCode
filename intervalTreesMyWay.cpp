#include<iostream>
using namespace std;

struct interval{
    int low,high;
};

struct node{
    interval* i;
    node* left;
    node* right;
    int max;
};

node* newNode(interval i){
    node* temp = new node;
    temp->i = new interval(i);
    temp->left = NULL;
    temp->right = NULL;
    temp->max = i.high;
    return temp;
}

node* insert(node* root, interval i){
    if(root == NULL){
        return newNode(i);
    }
    int lower_bound = root->i->low;
    if(i.low<lower_bound){
        root->left = insert(root->left,i);
    }else{
        root->right = insert(root->right,i);
    }
    if(root->max<i.high){
        root->max = i.high;
    }
    return root;
}

bool isOverlapping(interval i1,interval i2){
    if(i2.low<i1.high && i1.low<i2.high){
        return true;
    }else{
        return false;
    }
}

interval* findOverlap(node* root, interval i){
    if(root == NULL){
        return NULL;
    }
    if(isOverlapping(*(root->i),i)){
        return root->i;
    }
    if (root->left != NULL && root->left->max >= i.low)
        return findOverlap(root->left, i);
    return findOverlap(root->right, i);
}

void inorder(node* root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    cout << "[" << root->i->low << ", " << root->i->high << "]"<< " max = " << root->max << endl;
    inorder(root->right);
}

int main(){
    int n;
    cout<<"Enter the number of Intervals to enter into the tree"<<endl;
    cin>>n;
    interval i;
    node* root = NULL;
    while(n>0){
        cout<<"Enter the lower and upper limits of the interval"<<endl;
        cin>>i.low>>i.high;
        root = insert(root,i);
        n--;
    }
    cout<<"Ïnorder traversal is:"<<endl;
    inorder(root);
    cout<<"Enter the range to query:"<<endl;
    interval qrange;
    cin>>qrange.low>>qrange.high;
    interval* res = findOverlap(root,qrange);
    if(res == NULL){
        cout<<"No overlap"<<endl;
    }else{
        cout<<"["<<res->low<<", "<<res->high<<"]"<<endl;
    }
    return 0;
}
