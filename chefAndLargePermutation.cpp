#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    long int t;
    scanf("%ld",&t);
    while(t>0){
        long int n,k;
        scanf("%ld %ld",&n,&k);
        long int *a;
        a = new long int[k];
        for(long int i=0;i<k;i++){
            scanf("%ld",&a[i]);
        }

        t--;
    }


    return 0;
}
