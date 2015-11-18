#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        char a[32],b[32];
        int res[32];
        scanf("%s",a);
        int k=0;
        for(int i=0;i<strlen(a);i++){
            if(a[i]=='*'){
                a[i] = (a[i-1]-'0')*(a[i+1]-'0');
                a[i-1]=' ';
                a[i+1]=' ';
            }
        }

        int count = b[0]-'0';
        for(int i=1;i<=k;i++){
            if(b[i]=='+'){
                count +=b[i+1]-'0';
            }else if(b[i]=='-'){
                count -=b[i+1]-'0';
            }
        }
        printf("%d\n",count);
        t--;
    }
    return 0;
}
