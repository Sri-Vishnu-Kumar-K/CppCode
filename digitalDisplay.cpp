#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    char a[101];
    scanf("%s",a);
    int count = 0;
    for(int i=0;i<strlen(a);i++){
        if(a[i]=='0'){
            count += 6;
        }else if(a[i]=='1'){
            count +=2;
        }else if(a[i]=='2'){
            count +=5;
        }else if(a[i]=='3'){
            count +=5;
        }else if(a[i]=='4'){
            count +=4;
        }else if(a[i]=='5'){
            count +=5;
        }else if(a[i]=='6'){
            count +=6;
        }else if(a[i]=='7'){
            count +=4;
        }else if(a[i]=='8'){
            count +=7;
        }else if(a[i]=='9'){
            count +=6;
        }
    }
    printf("%d",count);
    return 0;
}
