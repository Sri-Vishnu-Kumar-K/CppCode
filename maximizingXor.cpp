#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int l,r;
    int max = -32767;
    int p = scanf("%d %d",&l,&r);
    for(int i = l;i<=r;i++){
        for(int j=i;j<=r;j++){
            if( (int)i^j > max){
                max = (int)i^j;
            }
        }
    }
    printf("%d",max);
    return 0;
}
