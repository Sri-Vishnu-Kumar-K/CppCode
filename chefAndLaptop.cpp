#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int c[101];
        int n;
        scanf("%d",&n);
        for(int i=0;i<101;i++){
            c[i]=0;
        }
        int x;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            c[x]+=1;
        }
        for(int i=0;i<101;i++){
            if(c[i]==1){
                printf("%d\n",i);
                break;
            }
        }
        t--;
    }
    return 0;
}
