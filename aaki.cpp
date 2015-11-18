#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    long int n,k;
    cin>>n>>k;
    long int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int count = 0;
    for(long int i=0;i<n;i++){
        long int l =i+1;
        long int h = n-1;
        while(l<=h){
            long int m = (l+h)/2;
            if(a[m]-a[i]==k){
                count++;
                break;
            }else if(a[m]-a[i]>k){
                h = m-1;
            }else{
                l = m+1;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
