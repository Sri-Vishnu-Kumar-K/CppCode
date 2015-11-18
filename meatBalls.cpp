#include<iostream>
#include<cstdio>
#include<algorithm>
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

int fastRead(long long int &x){
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
        int n;
        long long int *p;
        long long int tot,sum=0,count=0;
        fastRead(n);
        fastRead(tot);
        p = new long long int [n];
        for(int i=0;i<n;i++){
            fastRead(p[i]);
        }
        sort(p,p+n);
        sum=p[n-1];
        count++;
        for(int i=n-2;i>=0;i--){
            if(sum<tot){
                sum = sum +p[i];
                count++;
            }else{
                break;
            }
        }
        printf("%d\n",count);
        t--;
    }
    return 0;
}
