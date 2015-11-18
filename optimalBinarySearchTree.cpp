#include<iostream>
#include<climits>
using namespace std;


int obst(int i,int j,int p[]){
    if(i>j){
        return 0;
    }
    if(i==j){
        return p[i];
    }
    int psum=0;
    for(int k=i;k<=j;k++){
        psum+=p[k];
    }
    int min=INT_MAX;
    for(int r=i;r<=j;r++){
        int cost=obst(i,r-1,p)+obst(r+1,j,p);
        if(cost<min){
            min=cost;
        }
    }
    return min+psum;
}

int main(){
    int keys[]={10,20,30};//keys are sorted else, sort the keys and p accordingly before proceeding.
    int p[]={34,8,50};
    int n = sizeof(keys)/sizeof(keys[0]);
    cout<<obst(0,n-1,p)<<endl;
    return 0;
}
