#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    long long int pos=0;
    long long int a;
    scanf("%lld",&a);
    pos = a%6;
    if(pos==1 || pos==3 || pos==0){
        printf("yes\n");
    }else{
        printf("no\n");
    }
    return 0;
}
