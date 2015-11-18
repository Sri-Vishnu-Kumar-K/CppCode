#include<iostream>
using namespace std;

int main(){
    int **a;
    int r,c;
    cin>>r>>c;
    a = new int *[r];
    for(int i=0;i<r;i++){
        a[i]=new int[c];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    for (int i=0; i<r/2; i++){
        for (int j=i; j<c-i-1; j++){
                int tmp=a[i][j];
                a[i][j]=a[j][r-i-1];
                a[j][r-i-1]=a[r-i-1][c-j-1];
                a[r-i-1][c-j-1]=a[c-j-1][i];
                a[c-j-1][i]=tmp;
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<'\t';
        }
        cout<<endl;
    }
    return 0;
}
