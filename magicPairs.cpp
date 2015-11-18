#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        long long int n;
        scanf("%lld",&n);
        char c = getchar();
        c=getchar();
        while(c!='\n')c=getchar();
        printf("%lld\n",n*(n-1)/2);
        t--;
    }
    return 0;
}
