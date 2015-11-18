#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define INF 32767
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=INF;
        }
    }
    int s,e,d;
    for(int i=0;i<m;i++){
        cin>>s>>e>>d;
        if(d<a[s-1][e-1]){
            a[s-1][e-1] = d;
            a[e-1][s-1] = d;
        }
    }
    int start;
    cin>>start;
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    visited[start-1] = true;
    int sum = 0;
    int count = 0;
    while(count < n-1){
        int min = INF;
        int minind = -1;
        for(int i=0;i<n;i++){
            if(visited[i]==true){
                for(int j=0;j<n;j++){
                    if(a[i][j]<min && visited[j]!=true){
                        min = a[i][j];
                        minind = j;
                    }
                }
            }
        }
        sum+=min;
        visited[minind] = true;
        count++;
    }
    cout<<sum;
    return 0;
}

