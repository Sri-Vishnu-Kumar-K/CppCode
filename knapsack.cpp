#include<cstdio>
#include<iostream>
using namespace std;
int max(int a, int b) {
    return (a > b)? a : b;
}

int knapSack(int W, int wt[], int n1,int n2){
    if (n1 == 0 || W == 0){
            return 0;
    }
    if (wt[n1-1] > W)
       return knapSack(W, wt, n1-1,n2);
    else return max( wt[n1-1] + knapSack(W-wt[n1-1], wt, n1-1,n2),knapSack(W, wt, n1-1,n2));
}
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    printf("%d", knapSack(k, a, n,n));
    return 0;
}
