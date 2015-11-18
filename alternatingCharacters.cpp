#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    char a[100000];
    int t;
    int y = scanf("%d",&t);
    while(t>0){
        cin>>a;
        int start =0, en = 0;
        char temp = a[0];
        int count = 0;
        for(int i =1;i<strlen(a);i++){
            if(temp == a[i]){
                en = i;
            }else{
                temp = a[i];
                count += en - start;
                start = en = i;
            }
        }
        count += en - start;
        printf("%d\n",count);
        t--;
    }

    return 0;
}
