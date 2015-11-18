#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        char a[1000],b[1000];
        int x[26],y[26],xx[26],yy[26];
        for(int i=0;i<26;i++){
            x[i]=0;
            y[i]=0;
            xx[i]=0;
            yy[i]=0;
        }
        cin>>a>>b;
        for(int i=0;i<strlen(a);i++){
            x[a[i]-'a']+=1;
            x[a[i]-'a']=1;
        }
        for(int i=0;i<strlen(b);i++){
            y[b[i]-'a']+=1;
            y[b[i]-'a']=1;
        }
        int count =0;
        int count1=0;
        int flag1 =1,flag2=1;
        for(int i=0;i<26;i++){
            if(x[i]!=y[i]){
                flag1=2;
            }
        }
        for(int i=0;i<26;i++){
            if(xx[i]!=yy[i]){
                flag2=2;
            }
        }
        if(flag1==flag2){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        t--;
    }
    return 0;
}
