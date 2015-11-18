#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        char a[10000];
        scanf("%s",a);
        int ca,cb;
        scanf("%d %d",&ca,&cb);
        int tc = 0;
        int flag = 0;
        int i=0;
        int j = strlen(a)-1;
        while(i<=j){
            if(a[i]!='/' && a[j]!='/' && a[i]!=a[j]){
                flag = 1;
                break;
            }else if(a[i]=='/' && a[j]!='/'){
                if(a[j]=='a'){
                    tc+=ca;
                }else{
                    tc+=cb;
                }
            }else if(a[i]!='/' && a[j]=='/'){
                if(a[i]=='a'){
                    tc+=ca;
                }else{
                    tc+=cb;
                }
            }else if(a[i]=='/' && a[j]=='/'){
                if(ca<cb){
                    tc+=ca;
                }else{
                    tc+=cb;
                }
            }
            i++;
            j--;
        }
        if(flag == 0)
            printf("%d\n",tc);
        else
            printf("-1\n");
        t--;
    }
    return 0;
}
