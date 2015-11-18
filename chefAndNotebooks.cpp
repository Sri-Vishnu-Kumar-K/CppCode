#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int x,y,n,k;
        scanf("%d %d %d %d",&x,&y,&k,&n);
        int pages = x - y;
        bool flag = true;
        for(int i=0;i<n;i++){
            int p,c;
            scanf("%d %d",&p,&c);
            if(p >= pages && c <= k){
                flag = false;
            }
        }
        if(flag == true){
            printf("UnluckyChef\n");
        }else{
            printf("LuckyChef\n");
        }
        t--;
    }
    return 0;
}
