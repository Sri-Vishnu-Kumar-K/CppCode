#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    long long r;
    int c;
    cin>>r>>c;
    if(r%2==1){
        r = r+1;
        cout<<(r*5)-8-2+((c-1)*2)<<endl;
    }
    else
        cout<<(r*5)-8-1+((c-1)*2)<<endl;
    return 0;
}
