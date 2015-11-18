#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int n;
        scanf("%d",&n);
        int a =-1;
        int b = 1;
        int c = 0;
        for(;c<n;){
            c = a+b;
            a = b;
            b = c;
        }
        if(c==n){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        t--;
    }
    return 0;
}
