#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};

node* makeNode(int data){
    node* temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
/*void inOrder(node* n){
    if(n->left!=NULL){
        inOrder(n->left);
    }
    cout<<n->data<<endl;
    if(n->right!=NULL){
        inOrder(n->right);
    }
}*/

void populateList(node* root, vector<int>&l, int v){
    node* temp = root;
    while(temp!=NULL){
        l.push_back(temp->data);
        if(v < temp->data ){
            temp = temp->left;
        }else if(v > temp->data){
            temp = temp->right;
        }else if(v == temp->data){
            break;
        }
    }
}


void findDistance(node* root, int v1,int v2){
    vector<int>l1,l2;
    l1.clear();
    l2.clear();
    populateList(root,l1,v1);
    cout<<"Path from root to first node:"<<endl;
    for(vector<int>::iterator it = l1.begin(); it!= l1.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    populateList(root,l2,v2);
    cout<<"Path from root to second node:"<<endl;
    for(vector<int>::iterator it = l2.begin(); it!= l2.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    int i;
    for (i = 0; i < l1.size() && i < l2.size() ; i++){
        if (l1[i] != l2[i])
            break;
    }
    cout<<"Least common ancestor is :"<<l1[i-1]<<endl;
    cout<<"The distance is:"<<l1.size()+l2.size()-(2*i)+1<<endl;
}


int main(){
    int n;
    cout<<"Enter the no of nodes to be added:"<<endl;
    cin>>n;
    cout<<"Enter the data"<<endl;
    int temp;
    cin>>temp;
    node* root = makeNode(temp);
    n--;
    while(n>0){
        cout<<"Enter the data"<<endl;
        cin>>temp;
        bool flag = true;
        node* nTemp = makeNode(temp);
        node* iter = root;
        node* prev = iter;
        while(iter!=NULL){
            prev = iter;
            if(iter->data > nTemp -> data){
                iter = iter -> left;
            }else if(iter->data < nTemp -> data){
                iter = iter -> right;
            }else if(iter -> data == nTemp -> data ){
                cout<<"Node Exists"<<endl;
                flag = false;
                break;
            }
        }
        if(!flag){
            continue;
        }
        if(nTemp -> data < prev->data){
            prev->left = nTemp;
        }else{
            prev->right = nTemp;
        }
        n--;
    }
    //inOrder(root);
    int v1,v2;
    cout<<"Enter values for the nodes to find distance"<<endl;
    cin>>v1>>v2;
    findDistance(root,v1,v2);
    return 0;
}
