#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    int t;
    double n,l,s,d,c;
    scanf("%d",&t);
    while(t>0){
        scanf("%lf %lf %lf %lf",&l,&s,&d,&c);
        n = s*pow(c+1,d-1);
        if(n>=l){
            printf("ALIVE AND KICKING\n");
        }else{
            printf("DEAD AND ROTTING\n");
        }
        t--;
    }
    return 0;
}
