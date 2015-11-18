#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        string a,b;
        cin>>a>>b;
        int x[300];
        for(int i=0;i<300;i++){
            x[i]=0;
        }
        for(int i=0;i<a.length();i++){
            x[a.at(i)]+=1;
        }
        for(int i=0;i<b.length();i++){
            x[b.at(i)]+=1;
        }
        int count = 0;
        for(int i='a';i<='z';i++){
            if(x[i]%2==0 && x[i]!=0){
                count++;
            }
        }
        for(int i='A';i<='Z';i++){
            if(x[i]%2==0 && x[i]!=0){
                count++;
            }
        }
        printf("%d\n",count);
        t--;
    }
    return 0;
}
