#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int n;
    int a[101];
    int *b;
    for(int i=0;i<101;i++){
        a[i]=0;
    }
    scanf("%d",&n);
    b = new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
        a[b[i]]+=1;
    }
    for(int i=0;i<101;i++){
        if(a[b[i]]!=2){
            printf("%d",b[i]);
            break;
        }
    }
    return 0;
}
