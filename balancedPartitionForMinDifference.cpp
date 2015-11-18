#include<iostream>
#include<climits>
using namespace std;

int p(int i,int j,int a[]){
    if(i==0)
        return 0;
    if(j==0)
        return 1;
    if(a[i-1]>j){
        return p(i-1,j,a);
    }
    return (p(i-1,j-a[i],a)||p(i-1,j,a));
}

int main(){
    int n;
    cin>>n;
    int *a;
    a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
       sum += a[i];
    if (sum%2 != 0){
        cout<<"Not Possible";
        return 0;
    }
    if(p(n,sum/2,a)==1){
        cout<<"Possible";
    }
    return 0;
}
