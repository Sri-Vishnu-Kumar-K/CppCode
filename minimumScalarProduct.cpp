#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int *a,*b;
        int n;
        scanf("%d",&n);
        a = new int[n];
        b = new int[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&b[i]);
        }
        sort(a,a+n);
        sort(b,b+n,greater<int>());
        long int sum=0;
        for(int i=0;i<n;i++){
            sum +=a[i]*b[i];
        }
        printf("Min Scalar pdt is %d\n",sum);
        t--;
    }
    return 0;
}
