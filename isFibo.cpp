#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int a=-1,b=1;
        int c=a+b;
        while(c<n){
            c = a+b;
            a = b;
            b = c;
        }
        if(c==n){
            cout<<"IsFibo"<<endl;
        }else{
            cout<<"IsNotFibo"<<endl;
        }
        t--;
    }
    return 0;
}
