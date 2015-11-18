#include<iostream>
#include<cstdio>
using namespace std;

inline void fastRead_int(int &x) {
register int c = getchar();//getting the no
x = 0;
int neg = 0;
for(; ((c<48 || c>57) && c != '-'); c = getchar());//check for negatives and non numbers

if(c=='-') {
       neg = 1;
       c = getchar();
}//check if negative

for(; c>47 && c<58 ; c = getchar()){//parse the string to int.
    x = (x<<1) + (x<<3) + c - 48;
}

if(neg)
    x = -x;
}

int main(){
    int a[5];
    for(int i=0;i<5;i++){
        fastRead_int(a[i]);
    }
    for(int i=0;i<5;i++){
        printf("%d",a[i]);
    }

    return 0;
}
