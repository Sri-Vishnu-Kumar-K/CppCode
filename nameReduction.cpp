#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        char x[40000],y[40000];
        cin>>x>>y;
        strcat(x,y);
        int a[26];
        memset(a,0,26);
        for(int i=0;i<strlen(x);i++){
            a[x[i]-'a']+=1;
        }
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            char b[40000];
            cin>>b;
            for(int j=0;j<strlen(b);j++){
                a[b[j]-'a']-=1;
            }
        }
        int i;
        for( i=0;i<26;i++){
            if(a[i]<0){
                break;
            }
        }
        if(i<26){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
        t--;
    }
    return 0;
}
