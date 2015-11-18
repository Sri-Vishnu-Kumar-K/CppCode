#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int reverse(char s[],int n){
    for(int i=n-1;i>=0;i--){
        cout<<s[i];
    }
    cout<<' ';
    return 0;
}

int main(){
    string s;
    getline(cin,s);
    char *t;
    t = new char[s.length()];
    int k=0;
    for(int i = s.length()-1;i>=0;i--){
        if(s[i]!=' '){
            t[k]=s[i];
            k++;
            if(i==0){
                reverse(t,k);
            }
        }else{
            reverse(t,k);
            k=0;
        }
    }
    return 0;
}
