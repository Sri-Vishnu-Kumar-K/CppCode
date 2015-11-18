#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int s,n;
    int size;
    cin>>size;
    cin>>s;
    for(int i=1;i<size;i++){
        cin>>n;
        if(s+n>n){
            s +=n;
        }else{
            s = n;
        }
    }
    cout<<s<<endl;
    return 0;
}
