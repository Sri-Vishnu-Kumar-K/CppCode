#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int n,flag=0;
        scanf("%d",&n);
        if(360%n ==0){
            printf("y ");
            flag=1;
        }else{
            printf("n ");
        }
        if(flag==1||n<=360){
            printf("y ");
        }else{
            printf("n ");
        }
        if(n*(n+1)/2 <=360){
            printf("y\n");
        }else{
            printf("n\n");
        }

        t--;
    }
    return 0;

}
