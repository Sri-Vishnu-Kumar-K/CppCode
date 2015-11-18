#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n,m;
        cin>>n>>m;
        char a[n][m];
        int startIndx = -1,startIndy = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                if(a[i][j]=='M'){
                    startIndx = i;
                    startIndy = j;
                }
            }
        }

        t--;
    }

    return 0;
}
