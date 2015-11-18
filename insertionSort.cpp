#include<iostream>
using namespace std;
//3.29
int main(){
    int *a;
    int n;
    cin>>n;
    a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]<a[j]){
                int temp = a[i];
                for(int k=i-1;k>=j;k--){
                    a[k+1]=a[k];
                }
                a[j]=temp;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}
