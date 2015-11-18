#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int *n;
    int *length;
    int size,ind,max;
    cin>>size;
    length = new int[size];
    n = new int [size];
    for(int i=0;i<size;i++){
        cin>>n[i];
        length[i]=0;
    }
    length[0]=1;
    ind = 0;
    max=length[0];
    for(int i=1;i<size;i++){
        if(n[ind]<n[i]){
            length[i] += length[ind]+1;
            ind = i;
            if(length[ind]>max){
                max=length[ind];
            }
        }
    }
    cout<<max<<endl;
    return 0;
}
