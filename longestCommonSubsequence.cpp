#include<iostream>
#include<cstring>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}

int lcs(int i,int j,char x[],char y[]){
    if(i==0)
        return 0;
    if(j==0)
        return 0;
    if(x[i]==y[j]){
        return 1+lcs(i-1,j-1,x,y);
    }
    return max(lcs(i-1,j,x,y),lcs(i,j-1,x,y));
}

int main(){
    char a[20],b[20];
    cin>>a>>b;
    cout<<lcs(strlen(a),strlen(b),a,b);
    return 0;
}
