#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int n;
        scanf("%d",&n);
        char road[40][50],dir[40][50];
        for(int i=0;i<n;i++){
            scanf("%s %[^\n]%*c",dir[i],road[i]);
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                printf("Begin %s",road[i]);
            }else{
                if(strcmp("Left",dir[i+1])==0){
                    printf("Right %s",road[i]);
                }else{
                    printf("Left %s",road[i]);
                }
            }
            printf("\n");
        }
        printf("\n");
        t--;
    }
    return 0;
}
