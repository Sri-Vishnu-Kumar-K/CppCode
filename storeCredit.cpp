#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int cost;
        int n;
        int *a;
        scanf("%d",&cost);
        scanf("%d",&n);
        a = new int[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && a[i]<cost && a[j]<cost){
                    if(a[i]+a[j]==cost){
                        printf("%d %d\n",i<j?i:j,i<j?j:i);
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1){
                break;
            }
        }
        t--;
    }
    return 0;
}
