#include<iostream>
#include<cstdio>
using namespace std;

int fastread(int &x){
    register char c = getchar();
    while(c<33){
        c=getchar();
    }
    x=0;
    while(c>33){
        x = (x<<3)+(x<<1)+c-'0';
        c = getchar();
    }
    return 0;
}

int main(){
    int t;
    fastread(t);
    while(t>0){
        int n;
        fastread(n);
        int g,min;
        fastread(g);
        min=g;
        int diff=0;
        for(int i=0;i<n-1;i++){
            fastread(g);
            if(g<min){
                min=g;
            }else{
                int temp = g-min;
                if(temp>diff){
                    diff=temp;
                }
            }
        }
        if(diff>0){
            printf("%d\n",diff);
        }else{
            printf("UNFIT\n");
        }
        t--;
    }
    return 0;
}
