#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int x[26];
    for(int i=0;i<26;i++){
        x[i]=0;
    }
    for(int p=0;p<n;p++){
        char a[100];
        int y[26];
        for(int j=0;j<26;j++){
            y[j]=0;
        }
        cin>>a;
        for(int i=0;i<strlen(a);i++){
            if(y[a[i]-'a']!=1){
                x[a[i]-'a']+=1;
                y[a[i]-'a']=1;
            }
        }
    }
    int flag = 0;
    for(int i=0;i<26;i++){
        if(x[i]==n){
            printf("%c",i+'a');
            flag = 1;
        }
    }
    if(flag==0){
        printf("no such string");
    }
    return 0;
}
