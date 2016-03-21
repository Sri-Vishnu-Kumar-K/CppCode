#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int a[1001][1001];

struct node{
    int i,j,val;
};

int main(){
    int m,n;
    cin>>m>>n;
    int mini = m*n*100000;
    int sol[m+1][n+1];
    for(int i=1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            cin>>a[i][j];
            sol[i][j] = mini;
        }
    }
    int ri,rj;
    cin>>ri>>rj;
    queue<node>q;
    node no = {1,1,a[1][1]};
    sol[1][1] = a[1][1];
    q.push(no);
    while(!q.empty()){
        no = q.front();
        int k = no.i;
        int l = no.j;
        int v = no.val;
        if(k == ri && l == rj){
            q.pop();
            continue;
        }
        if(k == m && l == n && mini>v){
            mini = v;
        }
        q.pop();
        if(k<m){
            if(v+a[k+1][l]<sol[k+1][l]){
                node n1 = {k+1,l,v+a[k+1][l]};
                q.push(n1);
                sol[k+1][l] = v+a[k+1][l];
            }
        }
        if(l<n){
            if(v+a[k][l+1]<sol[k][l+1]){
                node n1 = {k,l+1,v+a[k][l+1]};
                q.push(n1);
                sol[k][l+1] = v+a[k][l+1];
            }
        }
    }
    if(mini < m*n* 100000)
        cout<<mini;
    else
        cout<<"-1";
    return 0;
}
