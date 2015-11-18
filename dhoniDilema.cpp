#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        long long *o;
        int n,z;
        scanf("%d %d",&n,&z);
        o = new long long[n];
        long long min;
        for(int i=0;i<n;i++){
            scanf("%lld",&o[i]);
            if(min<o[i]){
                min = o[i];
            }
        }
        int minind=-1;
        for(int i=0;i<n-z+1;i++){
            long long sum = 0;
            for(int j = i;j<i+z;j++){
                sum = sum ^ o[j];
            }
            if(min>sum){
                min = sum;
                minind = i+1;
            }
        }
        printf("%d\n",minind);
        t--;
    }
    return 0;
}
