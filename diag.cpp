#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int lr =0, rl = 0;
    for(int i=0;i<n;i++){
        lr += a[i][i];
        rl += a[i][n-i-1];
    }
    cout<<lr<<" "<<rl<<endl;
    if(lr>=rl){
        cout<<lr-rl;
    }else{
        cout<<rl-lr;
    }
    return 0;
}
