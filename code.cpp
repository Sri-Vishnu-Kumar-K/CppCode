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

int main(){
    int t;
    fastRead(t);
    while(t>0){
        int n,k,a;
        char s[3];
        fastRead(n);
        fastRead(k);
        fastRead(a);
        gets(s);
        int p[n];
        for(int i=0;i<n;i++){
            fastRead(p[i]);
        }
        for(int i=0;i<k;i++){
            if(k!=0){
                if(s[0]=='X'){
                    for(int j=0;j<n;j++){
                        a = a ^ p[j];
                    }
                }else if(s[0]=='A'){
                    for(int j=0;j<n;j++){
                        a = a & p[j];
                    }
                }else if(s[0]=='O'){
                    for(int j=0;j<n;j++){
                        a = a | p[j];
                    }
                }
                }
        }
        printf("%d\n",a);
        t--;
    }
    return 0;
}


