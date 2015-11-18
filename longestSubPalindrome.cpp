#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int lp(int s, int e,char a[]){
    if(s==e){
        return 1;
    }else if(a[s]==a[e]){
        return (lp(s+1,e-1,a)+2);
    }else if(a[s]!=a[e]){
        int max = lp(s+1,e,a)>lp(s,e-1,a)?lp(s+1,e,a):lp(s,e-1,a);
        return max;
    }else if(e==s+1 && a[e]==a[s]){
        return 2;
    }else if(e==s+1 && a[e]!=a[s]){
        return 1;
    }
}

int main(){
    char *a;
    int size;
    cin>>size;
    a = new char[size];
    cin>>a;
    cout<<lp(0,size-1,a);
    return 0;
}
