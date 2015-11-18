#include<iostream>
#include<cstdio>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int *a;
    a = new int[n];
    for(int i=0;i<n;i++){
        int x1,x2,x3,y1,y2,y3;
        scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
        a[i]=x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
        if(a[i]<0){
            a[i]=a[i]*(-1);
        }
    }
    int minv=INT_MAX;
    int minind=0;
    int maxv=INT_MIN;
    int maxind=0;
    for(int i=0;i<n;i++){
        if(a[i]<=minv){
            minv=a[i];
            minind = i;
        }
        if(a[i]>=maxv){
            maxv=a[i];
            maxind=i;
        }
    }
    printf("%d %d",minind+1,maxind+1);
    return 0;
}
