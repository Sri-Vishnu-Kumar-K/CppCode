#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

int fastRead(int &x){
    register char c=getchar();
    while(c<'0'){
        c=getchar();
    }
    x=0;
    while(c>='0' && c<='9'){
        x = (x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return 0;
}

int main(){
    int t;
    fastRead(t);
    while(t>0){
        int min=INT_MAX,n,s,sum=0;
        fastRead(n);
        for(int i=0;i<n;i++){
            fastRead(s);
            sum+=s;
            if(s<min){
                min=s;
            }
        }
        printf("%d\n",sum-(n*min));
        t--;
    }

    return 0;
}
