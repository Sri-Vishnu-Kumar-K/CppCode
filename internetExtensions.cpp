#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    map<string,string> m;
    string st1,st2;
    for(int i=0;i<n;i++){
        cin>>st1>>st2;
        m[st1]=st2;
    }
    for(int i=0;i<q;i++){
        string st3;
        cin>>st3;
        unsigned f = st3.find_last_of(".");
        string st4 = st3.substr(f+1);
        if(m.count(st4)>0)
            cout<<m[st4]<<endl;
        else{
            cout<<"unknown"<<endl;
        }
    }
    return 0;
}
