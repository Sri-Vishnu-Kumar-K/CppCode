#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int findNext(int k){

    return (((-k)&k)+k);
}

int findSum(int bit[],int n, int l){
    int sum = bit[l];
    while(l>0){
        l -= ((-l)&l);
        sum += bit[l];
    }
    return sum;
}

int main(){
    int n,q;
    cin>>n;
    int a[n];
    int bit[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
        bit[i] = 0;
    }
    bit[n]=0;
    cin>>q;
    while(q>0){
        int mod ;
        cin>>mod;
        for(int i=0;i<n;i++){
            int k = i+1;
            a[i] = a[i]+mod;
            while(k < n+1){
                bit[k] += abs(a[i]);
             //   cout << bit[k] <<" "<<k<<endl;
                k = findNext(k);
            }
        }
        cout<<findSum(bit,n,n)<<endl;
        for(int i=0;i<=n;i++){
            bit[i]=0;
        }
        q--;
    }
    return 0;
}
