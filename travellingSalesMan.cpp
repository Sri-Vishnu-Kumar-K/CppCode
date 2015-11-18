#include<iostream>
#include<climits>
using namespace std;
int show(int visit[],int n){
    for(int i=0;i<n;i++){
        cout<<visit[i]<<'\t';
    }
    cout<<endl;
}

int tsm(int **a,int ver,int n,int visit[],int dist){
    int v = ver;
    int count=0;
    for(int i=v;count<n;i++){
        cout<<v+1<<'\t'<<dist<<endl;
        int min=INT_MAX;
        show(visit,n);
        for(int j=0;j<n;j++){
            if(min>a[i][j] && visit[j]!=1 && a[i][j]!=0){
                min=a[i][j];
                v=j;
            }
        }
        dist+=a[i][v];
        visit[v]=1;
        count++;
    }
    return dist;
}

int main(){
    int n;
    cin>>n;
    int **adj;
    int * visit;
    adj = new int*[n];
    for(int i=0;i<n;i++){
        adj[i]=new int[n];
    }
    cout<<"If not connected type 32767"<<endl;
    for(int i=0;i<n;i++){
        visit[i]=0;
        for(int j=0;j<n;j++){
            cout<<"Enter weight"<<i+1<<" "<<j+1;
            cin>>adj[i][j];
        }
    }
    cout<<tsm(adj,0,n,visit,0);
    return 0;
}
