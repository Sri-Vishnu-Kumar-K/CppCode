#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    char a[10],b[10];
    int c[26];
    int flag=0;
    printf("Enter 2 strings \n");
    scanf("%s %s",&a,&b);
    memset(c,0,26);
    if(strlen(a)==strlen(b)){
        int n = strlen(a);
        for(int i=0;i<n;i++){
            c[a[i]-'a']+=1;
        }
        for(int i=0;i<n;i++){
            if(c[b[i]-'a']>=1){
                c[b[i]-'a']--;
            }else{
               flag=1;
               break;
            }
        }
        if(flag==0){
            printf("Yes they are anagrams\n");
        }else{
            printf("No they are not anagrams\n");
        }
    }else{
        printf("The strings are not of same lengths so they cant be anagrams\n");
    }
    return 0;
}
