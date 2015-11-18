#include<iostream>
#include<cstdio>
#include<cstring>
#include<string.h>
#include<stdio.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    getchar();
    while(t>0){
        char s[1000];
        int a[125];
        gets(s);
        for(int i='A';i<='Z';i++){
            a[i]=0;
        }
        for(int i=0;i<strlen(s);i++){
            a[toupper(s[i])]+=1;
        }
        int i;
        for( i='A';i<='Z';i++){
            if(a[i]!=1){
                printf("%c\n",i);
                break;
            }
        }
        if(i=='Z'+1){
            printf("~\n");
        }
        t--;
    }
    return 0;
}
