#include<iostream>
#include<climits>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    int k;
    cin>>k;
    int **a;
    a = new int *[m];
    for(int i=0;i<m;i++){
        a[i]=new int[n] ;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int i=0,j=0;
    int max = INT_MIN;
    while( j<=n-k && i<=m-k){
        int sum1=0;
        for(int p=i;p<i+k;p++){
            for(int q=j;q<k+j;q++){
                sum1+=a[p][q];
            }
        }
        if(max<sum1){
            max=sum1;
        }
        i++;
        j++;
    }
    cout<<max;
}
