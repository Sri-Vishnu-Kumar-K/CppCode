#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int n;
        scanf("%d",&n);
        long long fact = 1;
        for(int i=2;i<=n;i++){
            fact *= i;
        }
        long facts = 0;
        long sqr = (long)sqrt(fact) + 1;
        for(long long i = 1; i< sqr ;i++){
            if(fact%i == 0){
                facts+= 2;
            }
        }
        printf("%d\n",facts);
        t--;
    }
    return 0;
}
