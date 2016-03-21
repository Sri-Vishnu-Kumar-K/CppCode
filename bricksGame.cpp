#include<iostream>
#define LL long long
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        LL n,i,j;
        cin >> n;
        int pre[n],val[n],dp[n+1];
        pre[0]=0;
        for(i=n; i>0; i--){
            cin >> val[i];
        }
        for(i=1; i<=n; i++)
            pre[i]=pre[i-1]+val[i];
        dp[0]=0;
        dp[1]=val[1];
        dp[2]=dp[1]+val[2];
        dp[3]=dp[2]+val[3];
        for(i=4; i<=n; i++){
            dp[i]=max(-1,pre[i-1]-dp[i-1]+val[i]);
            dp[i]=max(dp[i],pre[i-2]-dp[i-2]+val[i]+val[i-1]);
            dp[i]=max(dp[i],pre[i-3]-dp[i-3]+val[i]+val[i-1]+val[i-2]);
        }
        cout << dp[n] << endl;
    }
    return 0;
}
