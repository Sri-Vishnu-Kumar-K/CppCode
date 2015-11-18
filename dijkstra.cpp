#include<iostream>
#include<climits>
using namespace std;

class graph{
public:
    int **a;
    int *d;
    int *visit;
    int *p;
    int n;

    graph(){
        cout<<"Enter no of vertices"<<endl;
        cin>>n;
        a = new int *[n];
        for(int i=0;i<n;i++){
            a[i]=new int[n];
        }
        d = new int[n];
        visit = new int[n];
        p=new int[n];
    }
    int getdata();
    int findmin();
    int dijkstra();
};

int graph::getdata(){
    for(int i=0;i<n;i++){
        d[i]=INT_MAX;
        visit[i]=0;
        p[i]=0;
        for(int j=0;j<n;j++){
            cout<<"Enter distance between "<<i+1<<" and "<<j+1<<endl;
            cin>>a[i][j];
        }
    }
    return 0;
}

int graph::findmin(){
    int min = INT_MAX;
    int minind = 0;
    for(int i=0;i<n;i++){
        if(d[i]<min && visit[i]!=1 &&d[i]!=INT_MAX){
            min = d[i];
            minind = i;
        }
    }
    visit[minind]=1;
    return minind;
}

int graph::dijkstra(){
    d[0]=0;

    for(int k=0;k<n-1;k++){
        int u = findmin();
        for(int v=0;v<n;v++){
            if(a[u][v]!=0 && visit[v]!=1 && d[v]>d[u]+a[u][v]){
                d[v]=d[u]+a[u][v];
                p[v] = u;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<'\t'<<d[i]<<'\t'<<p[i]<<endl;
    }
    return 0;
}

int main(){
    graph g;
    g.getdata();
    g.dijkstra();
    return 0;
}
