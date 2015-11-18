#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int fastRead(int &x){
    register char c = getchar();
    while(c<33){
        c=getchar();
    }
    x=0;
    while(c>33){
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
        fastRead(n);
        bool a[100003];
        int count=0;
        memset(a,false,100003);
        int temp;
        for(int i=0;i<n;i++){
            fastRead(temp);
            if(a[temp]==false){
                a[temp]=true;
                count++;
            }
        }
        printf("%d\n",count);
        t--;
    }


    return 0;
}
