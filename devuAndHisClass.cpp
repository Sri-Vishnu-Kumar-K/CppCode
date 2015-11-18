#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int type;
        scanf("%d",&type);
        char a[100001];
        scanf("%s",a);
        int count=0;
        for(int p=0;p<strlen(a);p++){
            for(int i=1;i<strlen(a)-1;){
                if(a[i-1] == a[i] && a[i]!=a[i+1]){
                    char temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                    count++;
                    i = i+1;
                }else if(a[i-1]!=a[i] && a[i]==a[i+1]){
                    char temp = a[i];
                    a[i] = a[i-1];
                    a[i-1] = temp;
                    count++;
                    i = i+1;
                }
                i++;
            }
        }
        bool flag = true;
        for(int i=1;i<strlen(a);i++){
            if(a[i] == a[i-1]){
                flag = false;
                break;
            }
        }
        if(flag == true){
            printf("%d\n",count);
        }else{
            printf("-1\n");
        }
        t--;
    }
    return 0;
}
