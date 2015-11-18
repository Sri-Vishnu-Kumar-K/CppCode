#include<iostream>
using namespace std;

int main(){
    int *a;
    int n;
    cin>>n;
    a = new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n/2 ;i>0;i--){
        if(a[i]<a[2*i] || a[i]<a[2*i + 1]){
            if(a[2*i] < a[2*i +1]){
                int temp = a[2*i];
                a[2*i]=a[i];
                a[i]=temp;
            }else{
                int temp = a[2*i +1];
                a[2*i +1]=a[i];
                a[i]=temp;
            }
        }
        if(a[2*i]<a[2*i +1]){
            swap(a[2*i],a[2*i +1]);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i];
    }
    return 0;
}
