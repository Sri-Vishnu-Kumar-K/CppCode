#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    char a[100001];
    cin>>a;
    int b[26];
    for(int i=0;i<26;i++){
        b[i]=0;
    }
    for(int i=0;i<strlen(a);i++){
        b[a[i]-'a']+=1;
    }
    int count1=0,count2=0;
    for(int i=0;i<26;i++){
        if(b[i]%2==0){
            count2+=1;
        }else{
            count1+=1;
        }
    }
    if(strlen(a)%2==0 && count1==0){
        printf("YES");
    }else if (strlen(a)%2==1 && count1==1){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}
