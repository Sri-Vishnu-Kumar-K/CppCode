#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        int p = n;
        string a;
        if(n%3==0 && n%5 == 0){
            while(n%3==0 && n>0){
                a = a+"555";
                n = n/3;
            }
            while(n%5==0 && n>0){
                a = a+"33333";
                n = n/5;
            }
            cout<<a<<endl;
        }else{
            cout<<"-1"<<endl;
        }
        t--;
    }

    return 0;
}
