#include<iostream>
#include<cstdio>

using namespace std;

int gcd(int a,int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

int main(){
    long long int t;
    scanf("%lld",&t);
    while(t>0){
        long long int n,a,b;
        scanf("%lld",&n);
        for(int i=0;i<n;i++){
            if(i==0){
                scanf("%lld",&a);
            }else{
                scanf("%lld",&b);
                a=gcd(a,b);
            }
        }
        if(a>1){
            printf("%lld\n",a);
        }else{
            printf("-1\n");
        }
        t--;
    }
    return 0;
}
