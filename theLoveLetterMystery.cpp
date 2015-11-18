#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int t;
    int y = scanf("%d",&t);
    while(t>0){
        char a[10000];
        cin>>a;
        int i =0;
        int j = strlen(a)-1;
        int count = 0;
        while(i<=j){
            if(a[i]!=a[j]){
                if(a[i]>a[j]){
                    count +=a[i]-a[j];
                }else{
                    count +=a[j]-a[i];
                }
            }
            i++;
            j--;
        }
        cout<<count<<endl;
        t--;
    }
    return 0;
}
