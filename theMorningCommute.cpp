#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int curtime=0;
        int n;
        int start, time, wait;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&start,&time,&wait);
            if (curtime <= start)
                curtime = start + time;
            else
                curtime += wait - (curtime - start - 1) % wait - 1 + time;
        }
        printf("%d\n",curtime);
        t--;
    }

    return 0;
}
