#include<iostream>
#include<cstdio>

int fastRead(long long int &x){
    register char c =getchar();
    while(c<'0' && c>'9'){
        c=getchar();
    }
    x=0;
    while(c>='0' && c<='9'){
        x = (x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return 0;
}

int main(){
    long long int t;
    fastRead(t);
    while(t>0){
        long long int n;
        fastRead(n);
        printf("%lld\n",(2*n)+((n-1)*n/2));
        t--;
    }
    return 0;
}
