#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        char a[1000],pr;
        scanf("%s",&a);
        int l=0;
        for(int i=0;i<strlen(a);i++){
            l++;
            if(a[i]<pr){
                l=l+26+a[i]-pr;
            }else{
                l=l+a[i]-pr;
            }
            pr=a[i];
        }
        if(l<= 11*strlen(a)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        t--;
    }
    return 0;
}
