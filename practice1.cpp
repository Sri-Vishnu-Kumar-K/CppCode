#include<iostream>
#include<cstdio>
using namespace std;
inline void fastRead_int(int &x) {
register int c = getchar();
x = 0;
int neg = 0;
for(; ((c<48 || c>57) && c != '-'); c = getchar());

if(c=='-') {
       neg = 1;
       c = getchar();
    }

for(; c>47 && c<58 ; c = getchar())
 { x = (x<<1) + (x<<3) + c - 48; }

if(neg)
x = -x;
}

int main(){
    int t;
    fastRead_int(t);
    while(t>0){
        int c, *a,n;
        fastRead_int(n);
        a = new int[n];
        fastRead_int(c);
        for(int i=0;i<n;i++){
            fastRead_int(a[i]);
        }
        int f=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[i]+a[j]==c){
                    printf("%d %d\n",i+1,j+1);
                    f=1;
                    break;
                }
            }
            if(f==1){
                break;
            }
        }
        t--;
    }
    return 0;
}
