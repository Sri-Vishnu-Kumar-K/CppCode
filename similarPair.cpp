#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//int graph[1000001][1000001];
int sum = 0;
bool visit[1000001];
void dfs(int source,int n,int t,vector<int>v,vector<int>q[] ){
    vector<int>::iterator it = v.begin();
    while(it!=v.end()){
        //cout<<*it<<" ";
        if(source>*it && source - *it <= t){
            sum++;
        }else if(source < *it && *it - source <= t){
            sum++;
        }
        it++;
    }
    visit[source] = true;
    v.insert(v.end(),source);
    for(vector<int>::iterator it=q[source].begin();it!=q[source].end();it++){
        if(!visit[*it]){
            dfs(*it,n,t,v,q);
        }
    }
}

int main(){
    int n,t;
    cin>>n>>t;
    //bool graph[n+1][1000001];
    vector<int>q[n+1];
    /*for(int i=0;i<n+1;i++){
        for(int j=0;j<1000001;j++){
            graph[i][j] = false;
        }
    }*/
    for(int i=0;i<n-1;i++){
        int s,e;
        cin>>s>>e;
        q[s].insert(q[s].end(),e);
    }
    for(int i=1;i<=n;i++){
        visit[i] = false;
    }
    int source = 0;
    for(int i=1;i<=n;i++){
        for(vector<int>::iterator it = q[i].begin(); it!= q[i].end();it++){
            visit[*it] = true;
        }
    }
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            source = i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        visit[i] = false;
    }
    //cout<<source<<endl;
    vector<int>v;
    dfs(source,n,t,v,q);
    cout<<sum;
    return 0;
}
