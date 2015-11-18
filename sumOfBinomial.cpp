#include<iostream>
#include<cstdio>
using namespace std;

long long int fact(long int x){
    if(x==1 || x==0){
        return 1;
    }else{
        return x*fact(x-1);
    }
}

int main(){
    long long int t;
    scanf("%lld",&t);
    while(t>0){
        long int n,i=0,pdt=1,sum=0;
        scanf("%ld",&n);
        long long int nfac = fact(n);
        while(i<=n){
            sum += (nfac/(fact(i)*fact(n-i)))%3;
            i++;
        }
        printf("%lld\n",sum%(1000000007));
        t--;
    }
}
