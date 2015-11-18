#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int count=0;
        char c =getchar();
        while(c<'0')c = getchar();
        int i;
        for(i=0;c>='0';i++){
            if(c=='4' || c=='7'){
                count++;
            }
            c=getchar();
        }
        printf("%d\n",i-count);
        t--;
    }
}
