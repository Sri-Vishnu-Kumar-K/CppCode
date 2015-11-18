#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int n,m;
        scanf("%d %d",&n,&m);
        int a[n];
        int max = INT_MIN;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]>max){
                max = a[i];
            }
        }
        int p = 0;
        for(int i = 0;i<n;i++){
            p += max - a[i];
        }
        if(m>=p){
            if(m == 0){
                printf("Yes\n");
            }else if (m!=0 && p==0){
                if(m%n == 0 && m>n){
                    printf("Yes\n");
                }else{
                    printf("No\n");
                }
            }else if (m!=0 && p!=0){
                m = m - p;
                if(m == 0 || (m%n == 0 && m >n)){
                    printf("Yes\n");
                }else{
                    printf("No\n");
                }
            }else{
                printf("No\n");
            }
        }else{
            printf("No\n");
        }
        t--;
    }
    return 0;
}
