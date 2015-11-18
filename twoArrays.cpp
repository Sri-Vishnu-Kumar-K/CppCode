#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long int n;
    cin>>n;
    int q;
    cin>>q;
    int a[n],b[n];
    for(long long int i=0;i<n;i++){
        a[i]=b[i]=0;
    }
    for(int i=0;i<q;i++){
        int t,l,r,c;
        cin>>t;
        if(t==1){
            cin>>l>>r>>c;
            for(int i=l;i<=r;i++){
                a[i]+=c;
            }
        }
        else if(t==2){
            cin>>l>>r>>c;
            for(int i=l;i<=r;i++){
                b[i]+=c;
            }
        }else{
            cin>>l>>r;
            long long int sum = 0;
            for(int i=l;i<=r;i++){
                sum+=(a[i]*b[i]);
            }
            cout<<sum%1000000007;
        }
    }
    return 0;
}

