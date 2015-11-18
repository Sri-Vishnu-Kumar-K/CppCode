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
        int id[1001];
        int flag = 0;
        for(int i=0;i<1001;i++){
            id[i]=0;
        }
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            id[x]+=1;
        }
        int count = 0;
        for(int i=0;i<1001;i++){
            if(id[i]>1){
                count +=1;
            }
        }
        printf("%d\n",count);
        t--;
    }
    return 0;
}
