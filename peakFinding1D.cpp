#include<iostream>
using namespace std;

int bin(int i,int a[],int n){
    if(a[i]<a[i-1] && i>=1){
        return bin(i/2,a,n);
    }else if(a[i]<a[i+1] && i<n-1){
        return bin(i+i/2,a,n);
    }else{
        return a[i];
    }
}

int main(){
    int n;
    int *a;
    cin>>n;
    a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<bin(n/2,a,n)<<endl;
    return 0;
}
