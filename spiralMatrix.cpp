#include<iostream>
#include<cstdio>
using namespace std;

void printSpiral(int a[][10],int row, int col){
    int row1 = 0, col1 = 0;
    while(row1 < row && col1<col){
        for(int i=col1;i<col;i++){
            cout<<a[row1][i]<<' ';
        }
        row1++;
        for(int i=row1;i<row;i++){
            cout<<a[i][col-1]<<' ';
        }
        col--;
        if(row1<row){
            for(int i = col-1;i>=col1;i--){
                cout<<a[row-1][i]<<' ';
            }
            row--;
        }
        if(col1<col){
            for(int i = row - 1; i>=row1;i--){
                cout<<a[i][col1]<<' ';
            }
            col1++;
        }
    }

}

int main(){
    int a[10][10];
    int row,col;
    cin>>row>>col;
    for(int i=0;i<row;i++){
        for(int j = 0;j<col;j++){
            cin>>a[i][j];
        }
        cout<<endl;
    }
    printSpiral(a,row,col);
    return 0;
}
