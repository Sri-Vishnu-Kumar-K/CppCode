#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n,m;
        cin>>n>>m;
        int a[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    a[i][j]=0;
                }else{
                    a[i][j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            int st,en;
            cin>>st>>en;
            a[st-1][en-1]=1000000;
            a[en-1][st-1]=1000000;
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]!=1000000){
                    cout<<a[i][j]<<" ";
                }else{
                    cout<<"INF ";
                }
            }
            cout<<endl;
        }*/
        int s;
        cin>>s;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(a[i][k]+a[k][j]<a[i][j]){
                        a[i][j]=a[i][k]+a[k][j];
                    }
                }
            }
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]!=1000000){
                    cout<<a[i][j]<<" ";
                }else{
                    cout<<"INF ";
                }
            }
            cout<<endl;
        }*/
        for(int i=0;i<n;i++){
            if(i!=s-1){
                cout<<a[s-1][i]<<" ";
            }
        }
        cout<<endl;
        t--;
    }
    return 0;
}
