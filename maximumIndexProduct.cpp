#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int n;
    int p = scanf("%d",&n);
    long long *a;
    long long *l;
    long long *r;
    long long ind;
    a = new long long [n];
    l = new long long [n];
    r = new long long [n];
    for(int i=0;i<n;i++){
        p = scanf("%lld",&a[i]);
    }
    long long max = -1;
    for(int i=0;i<n;i++){
        int flag = 0;
        for(int j =i-1;j>=0;j--){
            if(a[j]>a[i]){
                l[i] = j+1;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            l[i]=0;
        }
        int flag1=0;
        for(int j = i+1;j<n;j++){
            if(a[j]>a[i]){
                r[i]=j+1;
                flag1=1;
                break;
            }
        }
        if(flag1 == 0){
            r[i]=0;
        }
        ind = l[i]*r[i];
        if(max<ind){
            max = ind;
        }
    }
    printf("%lld\n",max);
    return 0;
}
