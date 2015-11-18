#include<iostream>
using namespace std;

int merge(int l,int m,int h, int *a){
    int *c ;
    c = new int[2*h];
    int k=l;
    int i=l;
    int j=m+1;
    while(i<=m && j<=h){
        if(a[i]<a[j]){
            c[k]=a[i];
            k++;
            i++;
        }else{
            c[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=m){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<=h){
        c[k]=a[j];
        k++;
        j++;
    }
    for(int i=l;i<k;i++){
        a[i]=c[i];
    }
    return 0;
}


int mergeSort(int l,int h, int *a){
    if(l<h){
        int mid = (l+h)/2;
        mergeSort(l,mid,a);
        mergeSort(mid+1,h,a);
        merge(l,mid,h,a);
    }
    return 0;
}
//3.2
int main(){
    int *a;
    int n;
    cin>>n;
    a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(0,n,a);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}
