#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int n,m;
        scanf("%d %d",&n,&m);
        int *a;
        int *mval;
        a = new int[n];
        mval = new int[n];
        for(int i =0;i<n;i++){
            a[i] = i;
            mval[i] = i;
        }
        for(int i=0;i<m;i++){
            int it;
            scanf("%d",&it);
            a[it]=0;
            for(int x = it+1;x<n;i++){
                a[x] = a[x-1] + 1;
                if(a[x]>mval[x]){
                    mval[x]=a[x];
                }
            }
            for(int y = it-1; y >=0;y--){
                a[y] = a[y+1] + 1;
                if(a[y]>mval[y]){
                    mval[y]=a[y];
                }
            }
        }
        for(int i =0;i<n;i++){
            printf("%d ",mval[i]);
        }
        printf("\n");
        t--;
    }
    return 0;
}
