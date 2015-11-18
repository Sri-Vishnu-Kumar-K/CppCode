#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        int l,r;
        cin>>l>>r;
        long long res=0;
        bool flag = false;
        long need = 1000000;
        for(int i = l; i<=r;i++){
            res += pow(10,i);
            if(res > need){
                flag = true;
                break;
            }
        }
        if(flag == true){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        t--;
    }

    return 0;
}
