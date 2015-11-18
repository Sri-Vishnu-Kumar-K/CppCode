#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n,k;
        cin>>n>>k;
        int countn=0,county=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x<=0){
                countn++;
            }else{
                county++;
            }
        }
        if(countn>=k){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
        t--;
    }
    return 0;
}
