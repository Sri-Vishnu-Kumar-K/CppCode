#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

int findmin(int d[],int p,int v[]){
    int min=INT_MAX,minind=0;
    for(int i=0;i<p;i++){
        if(min>d[i] && v[i]!=1){
            min=d[i];
            minind=i;
        }
    }
    return minind;
}

int main(){
    int p,t,junk;
    junk=scanf("%d %d",&p,&t);
    int **a;
    a = new int*[p];
    for(int i=0;i<p;i++){
        a[i]=new int[p];
    }
    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++){
            a[i][j]=INT_MAX;
        }
    }
    for(int i=0;i<t;i++){
        int p1,p2,l;
        junk=scanf("%d %d %d",&p1,&p2,&l);
        if(a[p1][p2]>l){
            a[p1][p2]=l;
        }
    }
    int d[p],v[p],proc[p];
    for(int i=0;i<p;i++){
        d[i]=INT_MAX;
        v[i]=0;
        proc[i]=INT_MAX;
    }
    d[0]=0;
    int count=1,temp=INT_MAX;
    for(int i=0;i<p-1;i++){
        int u = findmin(d,p,v);
        v[u]=1;
        for(int j=0;j<p;j++){
            if(d[j]>=d[u]+a[u][j] && a[u][j]!=INT_MAX && v[j]!=1){
                if(j==p-1){
                    temp=d[u]+a[u][j];
                    if(temp<d[p-1]){
                        count=1;
                        d[j]=temp;
                    }else if(d[p-1]==temp){
                        count++;
                    }
                }else{
                    d[j] = d[u]+a[u][j];
                }
            }
        }
    }
    printf("%d\n",d[p-1]*(count)*2);
    return 0;
}
