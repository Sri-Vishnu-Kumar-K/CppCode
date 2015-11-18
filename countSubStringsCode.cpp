#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        char *a;
        int n,k,q;
        scanf("%d %d %d",&n,&k,&q);
        a = new char[n];
        scanf("%s",a);
        for(int x=0;x<q;x++){
            int l,r;
            scanf("%d %d",&l,&r);
            int count=0;
            for(int i=l-1;i<=r-1;i++){
                int count1=0;
                int count0=0;
                for(int j=i;j<=r-1;j++){
                    if(a[j]=='1'){
                        count1++;
                    }else{
                        count0++;
                    }
                    if(count0 <=k && count1<=k){
                        count++;
                    }
                }
            }
            printf("%d\n",count);
        }
        t--;
    }
    return 0;
}
