#include<iostream>
#include<cstdio>
#include<cstring>

int main(){
    int k,n;
    char a[50][50],b[50][50];
    std::cin>>k>>n;
    for(int i=0;i<k;i++){
        scanf("%s",*a[i]);
    }
    std::cout<<*a[k-1];
    return 0;


}
