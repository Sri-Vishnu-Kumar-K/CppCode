#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int n;
        scanf("%d",&n);
        long long now;
        long long prev;
        int count = 0;
        scanf("%lld",&now);
        prev = now;
        bool nowv = false;
        for(int i=1;i<=n-1;i++){
            scanf("%lld",&now);
            if( now != prev ){
                if(nowv == false){
                    count = count + 2;
                    nowv = true;
                }else{
                    count++;
                }
            }else{
                nowv = false;
            }
            prev = now;
        }
        printf("%d\n",count);
        t--;
    }
    return 0;
}
