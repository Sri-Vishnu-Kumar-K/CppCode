#include<iostream>
#include<cstdio>

using namespace std;

bool dp(int a[],int n,int m){
    if(m == 0){
        return true;
    }else if(n < 0 && m !=0){
        return false;
    }else if(a[n] <= m){
        return (dp(a,n-1,m - a[n])||dp(a,n-1,m));
    }else if(a[n]>m){
        return dp(a,n-1,m);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int n,m;
        int *a;
        scanf("%d %d",&n,&m);
        a = new int[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        if(dp(a,n-1,m)==true){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
        t--;
    }
    return 0;
}
