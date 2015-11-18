#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int n,maxind=0;
        int w,max;
        scanf("%d %d",&n,&max);
        for(int i=1;i<n;i++){
            scanf("%d",&w);
            if(w+i>max){
                max=w+i;
                maxind=i;
            }
        }
        printf("%d\n",max);
        t--;
    }
    return 0;
}
