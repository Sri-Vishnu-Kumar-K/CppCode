#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    long n;
    scanf("%ld",&n);
    long max = 0;
    long count = 0;
    int t;
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        if(t==0){
            if(max<count){
                max=count;
            }
            count = 0;
        }else{
            count++;
        }
    }
    if(count>max){
        max = count;
    }
    printf("%ld",max);
    return 0;
}
