#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int a[1001][1001];

int main(){
    int m,n;
    cin>>m>>n;
    int sol[m+1][n+1];
    int mini = m*n*100000;
    for(int i=1;i<=m;i++){
        for(int j=1 ;j<=n;j++){
            cin>>a[i][j];
            sol[i][j] = mini;
        }
    }
    int ri,rj;
    cin>>ri>>rj;
    a[ri][rj] = mini;
    sol[1][1] = a[1][1];
    for(int i=1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            if(i<m){
                if(sol[i+1][j]<sol[i][j] + a[i+1][j])
                    sol[i+1][j] = sol[i][j] + a[i+1][j];
            }
            if(j<n){
                if(sol[i][j+1]<sol[i][j] + a[i][j+1])
                    sol[i][j+1] = sol[i][j] + a[i][j+1];
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<sol[m][n];
    return 0;
}
