#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node
{
char name[20];
int type;
struct node *next, *down;
};
// A utility function to create a new BST node
struct node *newNode(char item[],int type1){
struct node *temp = (struct node *)malloc(sizeof(struct node));
strcpy(temp->name,item);
temp->next = temp->down = NULL;
temp->type = type1;
if(type1==1)
printf("New directory %s has been created\n",temp->name);
else
printf("New file %s has been created\n",temp->name);
return temp;
}
struct node *inorder(struct node *root,char p[]){
if (root->next!= NULL && strcmp(root->name,p)!=0){
inorder(root->next,p);
printf("%s ", root->name);
if(root->type==1)
inorder(root->down,p);
}
return root;
}
int find(struct node* node,char *key){
struct node* temp = node;
if(temp!=NULL){
if(strcmp(temp->name,key)==0){
printf("Found %s\n",temp->name);
return 1;
}else{
find(temp->down,key);
find(temp->next,key);
}
}
return 0;
}
struct node* insert(struct node* node, char key[],char par[],int
mode){
/* If the tree is empty, return a new node */
if (node == NULL){
printf("The root node is getting created .....\n");
return newNode(key,mode);
}
else{
struct node *temp = NULL;
temp=inorder(node,par);
struct node *temp1 = newNode(key,mode);
if(temp->down==NULL && temp->type ==1){
temp->down = temp1;
if(temp1->type == 2){
printf("File %s successfully inserted\n",temp1-
>name);
}
else
printf("Directory %s successfully
inserted\n",temp1->name);
}else{
temp = temp->down;
while(temp->next!=NULL){
temp = temp->next;
}
temp->next = temp1;
if(temp1->type == 2){
printf("File %s successfully inserted\n",temp1-
>name);
}else
printf("Directory %s successfully
inserted\n",temp1->name);
}
}
return node;
}
int main(){
struct node *root = NULL;
int p=0;
int c=0;
char parent[50][20];
char child[50][20];
char cont = 'y';
root = insert(root, "root","",1);
while(cont == 'y'){
char parDir[20];
char fileOrDir[20];
int t;
printf("Enter parent directory and directory or file name and
type (1 for directory and 2 for file)\n");
scanf("%s",parDir);
scanf("%s",fileOrDir);
scanf("%d",&t);
insert(root,fileOrDir,parDir,t);
strcpy(child[c],fileOrDir);
strcpy(parent[p],parDir);
c++;
p++;
printf("Wanna insert more?? \n");
scanf("%s",&cont);
}
char finder[20];
printf("Enter file name to search\n");
scanf("%s",finder);
find(root,finder);
char par[20];
char chi[20];
strcpy(chi,finder);
printf("The path in reverse order is\n");
while(strcmp(par,"root")!=0){
int i=0;
for(i=0;i<c;i++){
if(strcmp(child[i],chi)==0){
strcpy(par,parent[i]);
strcpy(chi,parent[i]);
printf("%s\n",par);
}
}
}
return 0;
}
