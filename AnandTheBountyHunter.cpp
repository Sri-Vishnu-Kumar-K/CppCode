#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int a[1001][1001];
long maxer = 999999;

long min(long a,long b){
    return a<b?a:b;
}

long dfs(int i,int j, int m, int n, int ri, int rj){
    if(i == m && j == n){
        return a[i][j];
    }else if(i == ri && j == rj){
        return maxer;
    }else if(i+1 <= m && j+1<= n){
        return min(a[i][j] + dfs(i+1,j,m,n,ri,rj),a[i][j] + dfs(i,j+1,m,n,ri,rj));
    }
}

int main() {
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    maxer = (m*n*100000) + 1;
    int resti,restj ;
    cin>>resti>>restj;
    long res = dfs(1,1,m,n,resti,restj);
    if(res >= maxer){
        cout<<"-1";
    }else{
        cout<<res;
    }
    return 0;
}
