#include<iostream>
using namespace std;

int main(){
    long int n,m;
    cin>>n>>m;
    long a,b,k;
    long long sum=0;
    for(int i = 0;i<m;i++){
        cin>>a>>b>>k;
        sum += (b-a+1)*k;
    }
    cout<<sum/n;
    return 0;
}
