#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        long n;
        scanf("%ld",&n);
        if(n%2==1){
            printf("%ld\n",n-1);
        }else{
            printf("%ld\n",n);
        }
        t--;
    }
    return 0;
}
