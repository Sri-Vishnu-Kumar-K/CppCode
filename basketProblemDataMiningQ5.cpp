#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int a[101][101]={0};
    for(int i=1;i<101;i++){
        for(int j=1;j<101;j++){
            if(i%j==0){
                a[i][j]=1;
            }
        }
    }
    int sol[101]={0};
    int tot = 0;
    for(int i=0;i<101;i++){
        int sum=0;
        for(int j=0;j<101;j++){
            sum+=a[i][j];
        }
        tot +=sum;
        if(sum>=5){
            sol[i]=1;
        }
    }
    cout<<"The frequent items are :"<<endl;
    for(int i=1;i<101;i++){
        if(sol[i]==1){
            cout<<i<<endl;
        }
    }
    cout<<"The frequent pairs are :"<<endl;
    for(int i=1;i<100;i++){
        for(int k=i+1;k<101;k++){
            int sum=0;
            for(int j=1;j<101;j++){
                if(a[i][j]==1 && a[k][j]==1){
                    sum++;
                }
            }
            if(sum>=5){
                cout<<i<<","<<k<<endl;
            }
        }
    }
    cout<<"The size of all the baskets is :"<<tot<<endl;
    int max = -1;
    int maxind = 0;
    for(int j=0;j<101;j++){
        int sum=0;
        for(int i=0;i<101;i++){
            sum+=a[i][j];
        }
        if(sum>max){
            max = sum;
            maxind = j;
        }
    }
    cout<<"The basket with most no of items is "<<maxind<<" it has "<<max<<" items"<<endl;
    int sum1=0;
    int dem1=0;
    for(int j=1;j<101;j++){
        if(a[24][j]&&a[60][j]){
            dem1++;
            if(a[8][j])
                sum1++;
        }
    }
    cout<<"The confidence of {24,60} -> 8 is "<<(float)sum1/dem1<<endl;
    int sum2=0;
    int dem2=0;
    for(int j=1;j<101;j++){
        if(a[2][j]&&a[3][j]&&a[4][j]){
            dem2++;
            if(a[5][j])
                sum2++;
        }
    }
    cout<<"The confidence of {2,3,4} -> 5 is "<<(float)sum2/dem2<<endl;
    return 0;
}

