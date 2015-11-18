#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    string s1 = "AMITABH BACHCHAN";
    string s2 = "RAJNIKANTH";
    int a[26]={0};
    int b[26]={0};
    for(int i=0;i<s1.length();i++){
        a[s1.at(i)-'A']=1;
    }
    for(int i=0;i<s2.length();i++){
        b[s2.at(i)-'A']=1;
    }
    for(int i=0;i<26;i++){
        if(a[i]==1&&b[i]==1){
            printf("%c ",65+i);
        }
    }
    return 0;
}
