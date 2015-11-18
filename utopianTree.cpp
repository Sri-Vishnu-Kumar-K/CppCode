#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int t;
    int p = scanf("%d",&t);
    while(t>0){
        int n;
        p = scanf("%d",&n);
        int a = 1;
        for(int i=0;i<n;i++){
            if(i%2==0){
                a = 2*a;
            }else{
                a = a+1;
            }
        }
        printf("%d\n",a);
        t--;
    }
    return 0;
}
