#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int fastRead(long long int &x){
    register char c=getchar();
    while(c<'0' && c>'9'){
        c=getchar();
        if(c==' '){
            return 0;
        }
    }
    x=0;
    while(c>='0' && c<='9'){
        x = (x<<3) + (x<<1) + c - '0';
    }
    return 0;
}

int main(){
    long long int n,m;
    scanf("%lld %lld",&n,&m);
    while(m>0){
        long long int q;
        scanf("%lld",&q);
        if(q<=n+1 || q>=3*n+1){
            printf("0\n");
        }else{
            if(q-2*n-1 < 0){
                printf("%lld\n",n+(q-2*n-1));
            }else{
                printf("%lld\n",n-(q-2*n-1));
            }
        }
        m--;
    }


}
