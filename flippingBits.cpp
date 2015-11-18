#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

int main(){
    int t;
    int p = scanf("%d",&t);
    while(t>0){
        int32_t x = 4294967295;
        unsigned int y;
        p = scanf("%ud",&y);
        cout<<x-y<<endl;
        t--;
    }
    return 0;
}
