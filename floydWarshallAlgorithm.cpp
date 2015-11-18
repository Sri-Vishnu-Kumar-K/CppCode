#include<iostream>
#include<climits>
using namespace std;

int main(){
    cout<<"Enter no of nodes"<<endl;
    int n;
    int **adj;
    cin>>n;
    adj = new int*[n];
    for(int i=0;i<n;i++){
        adj[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(adj[i][j]<adj[i][k]+adj[k][j]){
                    adj[i][j]=adj[i][k]+adj[k][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==INT_MIN){
                cout<<"Negative cycle"<<endl;
                return 0;
            }
            cout<<adj[i][j];
        }
        cout<<endl;
    }
    return 0;
}
