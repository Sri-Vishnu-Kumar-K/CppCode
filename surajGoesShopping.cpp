#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int n;
        int *a;
        scanf("%d",&n);
        a = new int[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int cost = 0;
        for(int i=n-1;i>=0;){
            cost += a[i] + a[i-1];
            i = i - 4;
        }
        printf("%d\n",cost);
        t--;
    }
    return 0;
}
