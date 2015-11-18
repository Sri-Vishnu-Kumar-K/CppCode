#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int next(bool a[],int p,int n){
    int res = p;
    bool flag = true;
    for(int i=p+1;i<=n;i++){
        if(a[i]==true){
            res = i;
            flag = false;
            break;
        }
    }
    if(flag == true){
        for(int i=1;i<p;i++){
            if(a[i]==true){
                res = i;
                break;
            }
        }
    }
    return res;
}


int main() {
    int n,k;
    cin>>n>>k;
    bool a[n+1];
    for(int i=0;i<=n;i++){
        a[i]=true;
    }
    int temp;
    for(int i=0;i<k;i++){
        cin>>temp;
        a[temp]=false;
    }
    int sword = 1;
    int kill = next(a,sword,n);
    while(kill!=sword){
        a[kill] = false;
        sword = next(a,kill,n);
        kill = next(a,sword,n);
    }
    cout<<sword;
    return 0;
}

