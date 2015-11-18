#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t>0){
        int n,m;
        cin>>n>>m;
        int a[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j]=0;
            }
        }
        for(int i=0;i<m;i++){
            int s,e;
            cin>>s>>e;
            a[s-1][e-1]=1;
        }
        int start;
        cin>>start;
        int cost[n];
        bool visit[n];
        for(int i=0;i<n;i++){
            cost[i] = -1;
            visit[i] = false;
        }
        deque<int>q;
        q.push_back(start-1);
        int count = 1;
        while(q.empty()!=true){
            int s = q.front();
            q.pop_front();
            for(int j=0;j<n;j++){
                if(a[s][j]==1 && visit[j]!=true){
                    q.push_back(j);
                    cost[j]=count*6;
                    visit[j]=true;
                }
            }
            count++;
        }
        for(int i=0;i<n;i++){
            if(i==start-1){
                continue;
            }
            cout<<cost[i]<<" ";
        }
        cout<<endl;
        t--;
    }
    return 0;
}

