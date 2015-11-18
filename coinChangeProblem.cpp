#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int change(int p,int a[],int size){
    if(p<=0){
        return 0;
    }else{
        int *man;
        man = new int[size];
        for(int i=0;i<size;i++){
            man[i]=change(p-a[i],a,size);
        }
        int min1=man[0];
        for(int i=1;i<size;i++){
            if(min1>man[i])
                min1=man[i];
        }
        return (min1+1);
    }
}

int main(){
    int p,*val,size;
    cin>>size;
    val = new int[size];
    for(int i=0;i<size;i++){
        cin>>val[i];
    }
    cin>>p;
    cout<<change(p,val,size);
    return 0;
}
