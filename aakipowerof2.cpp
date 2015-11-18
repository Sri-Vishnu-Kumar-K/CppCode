#include<iostream>
#include<cstdio>
using namespace std;

int isSquare(int x){

    return x && (!(x&(x-1)));
}

int main(){
    int n;
    cin>>n;
    long int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cout<<isSquare(a[i])<<" ";
    }
    return 0;
}
