#include<iostream>
using namespace std;
int findmax(int j,int **a,int n){
    int maxind=0;
    for(int i=0;i<n;i++){
        if(a[i][j]>a[maxind][j]){
            maxind=i;
        }
    }
    return maxind;
}


int bin(int j,int **a,int n,int m){
    int i = findmax(j,a,n);
    if(a[i][j]<a[i][j-1] && j>0){
        return bin(j-1,a,n,m);
    }else if(a[i][j]<a[i][j+1] && j<m-1){
        return bin(j+1,a,n,m);
    }else{
        return a[i][j];
    }
}


int main(){
    int **a;
    int n,m;
    cin>>n>>m;
    a = new int *[n];
    for(int i=0;i<n;i++){
        a[i]=new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    cout<<bin(m/2,a,n,m)<<endl;
    return 0;
}
