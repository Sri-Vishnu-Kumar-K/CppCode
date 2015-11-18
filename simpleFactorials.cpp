#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int n;
        scanf("%d",&n);
        long prod = 1;
        for(int i=2;i<=n;i++){
            prod = prod*i;
        }
        printf("%ld\n",prod);
        t--;
    }
    return 0;
}
