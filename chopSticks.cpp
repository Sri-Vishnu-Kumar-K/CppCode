#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int fastread(long long int n, vector<int>&a){
    for(int i=0;i<n;i++){
        register char c=getchar();
        while(c<33){
            c=getchar();
        }
        int x=0;
        while(x>33){
            x = (x<<3)+(x<<1)+c-'0';
            c=getchar();
        }
        a.push_back(x);
    }
    return 0;
}


int main(){
    long long int n,d;
    scanf("%lld %lld",&n,&d);
    vector<int>a;
    fastread(n,a);
    long long int count=0;
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++){
        if(a.at(i)-a.at(i-1)<=d){
            i++;
            count++;
        }
    }
    printf("%lld",count);
    return 0;
}
