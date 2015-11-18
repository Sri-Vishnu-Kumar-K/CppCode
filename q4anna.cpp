#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        long n;
        scanf("%ld",&n);
        long long *a;
        a = new long long[n];
        for(long i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        long *val;
        val = new long[n];
        val [n-1]=0;
        for(int i =0;i<n-1;i++){
            long count = 0;
            long long maxht = 0;
            printf("for %ld\n",a[i]);
            for(int j = i+1; j<n;j++){
                if(a[j] > maxht){
                    maxht = a[j];
                    count ++;
                }else{
                    if(a[i] > maxht){
                        count++;
                    }
                }
            }
            val[i]=count;
        }
        for(long i =0;i<n;i++){
            printf("%ld ",val[i]);
        }
        printf("\n");
        t--;
    }
    return 0;
}
