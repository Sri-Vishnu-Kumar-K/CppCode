#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        long long int count = 0;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int temp;
            scanf("%d",&temp);
            if(temp ==1){
                count+=1;
            }
        }
        count = count*(count+1)/2;
        printf("%lld\n",count);
        t--;
    }
    return 0;
}
