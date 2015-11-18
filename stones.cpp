#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

long findmax(long *a,int n){
    long max = INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    return max;
}

int main(){
    int n;
    long k;
    scanf("%d %d",&n,&k);
    long *a;
    a = new long [n];
    for(int i=0;i<n;i++){
        scanf("%ld",&a[i]);
    }
    for(int i=0;i<k;i++){
        long max = findmax(a,n);
        for(int j=0;j<n;j++){
            a[j]= max - a[j];
        }
    }
    for(int i=0;i<n;i++){
        printf("%ld ",a[i]);
    }
    return 0;
}
