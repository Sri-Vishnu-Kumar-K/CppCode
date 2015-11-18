#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int n;
        scanf("%d",&n);
        long int count=0;
        long int count2=0;
        for(int i=0;i<n;i++){
            long long int val;
            scanf("%lld",&val);
            if(val==2){
                count2++;
            }else if(val>1){
                count++;
            }
        }

        printf("%ld\n",(count*(count-1)/2)-(count2*(count2-1)/2));
        t--;
    }
    return 0;
}
