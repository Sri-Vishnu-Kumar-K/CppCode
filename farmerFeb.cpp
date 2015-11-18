#include<iostream>
#include<cstdio>
using namespace std;

int fastRead(int &x){
    register char c = getchar();
    while(c<'0' && c>'9'){
        c=getchar();
    }
    x=0;
    while(c>='0' && c<='9'){
        x  = (x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return 0;
}

bool isprime(int n){
    int flag=0;
    for(int i=n/2;i>1;i--){
        if(n%i==0){
            flag = 1;
        }
    }
    if(flag==1){
        return false;
    }else{
        return true;
    }
}

int main(){
    int t=0;
    fastRead(t);
    while(t>0){
        int x,y;
        fastRead(x);
        fastRead(y);
        int i = x+y+1;
        while(1){
            if(isprime(i)){
                printf("%d\n",i-x-y);
                break;
            }
            i++;
        }
        t--;
    }
    return 0;
}
