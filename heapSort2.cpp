#include <iostream>
using namespace std;

int max_heapify(int *a, int i, int n){
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n){
        if (j < n && a[j+1] > a[j])
            j = j+1;
        if (temp > a[j])
            break;
        else if (temp <= a[j]){
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a[j/2] = temp;
    return 0;
}
int heapsort(int *a, int n){
    int i, temp;
    for (i = n; i >= 2; i--){
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heapify(a, 1, i - 1);
    }
    return 0;
}
int build_maxheap(int *a, int n){
    for(int i = n/2; i >= 1; i--){
        max_heapify(a, i, n);
    }
    return 0;
}
int main(){
    int n, i, x;
    cin>>n;
    int a[20];
    for (i = 1; i <= n; i++){
        cin>>a[i];
    }
    build_maxheap(a,n);
    heapsort(a, n);
    for (i = 1; i <= n; i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
