#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int *val,*b;
    int size;
    cin>>size;
    val = new int[size+1];
    b = new int[size+1];
    for(int i=1;i<=size;i++){
        cin>>val[i];
        b[i]=val[i];
    }
    b[0]=0;
    for(int i=1;i<=size;i++){
        for(int j=1;j<=i;j++){
            if(b[i]<=val[j]+b[i-j]){
                b[i]=val[j]+b[i-j];
            }
        }
    }
    for(int i=1;i<size+1;i++){
        cout<<b[i]<<'\t';
    }
    return 0;
}
