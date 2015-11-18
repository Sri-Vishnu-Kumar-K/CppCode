#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int n,k;
    int *a;
    scanf("%d %d",&n,&k);
    a = new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int count=0;
    for(int i=1;i<n;i++){
        if(a[i-1]+k>=a[i] || a[i-1]-k<=a[i]){
            count++;
        }else{
            break;
        }
    }
    printf("%d",count);
    return 0;
}
