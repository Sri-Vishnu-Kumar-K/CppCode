#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int main(){
    unsigned int t;
    cin>>t;
    getchar();
    while(t>0){
        char s[111];
        cin>>s;
        if(strlen(s)==5&&
           (s[0]>='a' && s[0]<='h') &&
           (s[1]>='1' && s[1]<='8')&&
           s[2]=='-' &&
           (s[3]>='a' && s[3]<='h') &&
           (s[4]>='1' && s[4]<='8')){
            int a = s[0]-s[3];
            int b = s[1]-s[4];
            if(a<0){
                a*=-1;
            }
            if(b<0){
                b*=-1;
            }
            if(a*b==2){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }else{
            cout<<"Error"<<endl;
        }
        t--;
    }
    return 0;
}
