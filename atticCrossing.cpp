#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    long long int t;
    scanf("%lld",&t);
    while(t>0){
        char c=getchar();
        while(c!='#' && c!='.'){
            c=getchar();
        }
        int days=0;
        int maxlen=1;
        while(c=='#'||c=='.'){
            if(c=='.'){
                int len=1;
                while((c=getchar())=='.'){
                    len++;
                }
                if(maxlen<len){
                    days+=maxlen-len;
                    maxlen=len;
                }
            }
        }
        printf("%d\n",days);
        t--;
    }
    return 0;
}
