#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long tot = n*(n+1)/2;
    long long sum=0;
    long long val;
    for(int i=1;i<=n;i++){
        cin>>val;
        sum+=val;
    }
    if(sum==tot){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}
