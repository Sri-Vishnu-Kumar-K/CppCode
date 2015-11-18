#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;
#define N 20
int min(int a,int b){
    return a<b?a:b;
}

int isSafe(int a[][N],int n,int x,int y,int bx,int by){
    if((x>0&&x<=n&&y>0&&y<=n)&&(x!=bx || y!=by)&&a[x][y]!=1){
        return true;
    }
    return false;
}

int solve(int a[][N],int n,int x,int y,int ex,int ey,int bx, int by){
    if(isSafe(a,n,x,y,bx,by)==true){
        a[x][y]=1;
        if(x == ex && y== ey){
            return 1;
        }else{
            return min(1+solve(a,n,x+1,y,ex,ey,bx,by),min(1+solve(a,n,x,y+1,ex,ey,bx,by),min(1+solve(a,n,x-1,y,ex,ey,bx,by),1+solve(a,n,x,y-1,ex,ey,bx,by))));
        }
    }
}


int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int n,sx,sy,ex,ey,bx,by;
        scanf("%d%d%d%d%d%d%d",&n,&sx,&sy,&ex,&ey,&bx,&by);
        int a[N][N]={0};
        printf("%d\n",solve(a,n,sx,sy,ex,ey,bx,by));
        t--;
    }
    return 0;
}
