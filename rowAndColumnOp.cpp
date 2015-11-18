#include<iostream>
#include<cstdio>

using namespace std;

int fastRead(int &x){
    register char c;
    while(c<'0'){
        c=getchar();
    }
    x = 0;
    while(c>='0' && c<='9'){
        x = (x<<3)+(x<<1)+c-'0';
        c = getchar();
    }
    return 0;
}

int main(){
    int *row,*col;
    int n,q,temp,val,rowmax=0,colmax=0;
    fastRead(n);
    row = new int[n];
    col = new int[n];
    for(int i=0;i<n;i++){
        row[i]=col[i]=0;
    }
    fastRead(q);
    for(int i=0;i<q;i++){
        char c = getchar();
        while(getchar()!=' ');
        fastRead(temp);
        fastRead(val);
        if(c=='R'){
            row[temp-1]+=val;
            if(rowmax<row[temp-1]){
                rowmax = row[temp-1];
            }
        }else if(c=='C'){
            col[temp-1]+=val;
            if(colmax<col[temp-1]){
                colmax = col[temp-1];
            }
        }
    }
    printf("%d\n",rowmax+colmax);
    return 0;
}
