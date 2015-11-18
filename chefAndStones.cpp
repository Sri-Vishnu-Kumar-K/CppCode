#include<cstdio>
#include<iostream>
using namespace std;

/*int fastRead(int &x){
    register char c = getchar();
    while(c<'0' && c>'9'){
        c=getchar();
    }
    x=0;
    while(c>='0' && c<='9'){
        x = (x<<8)+(x<<2)+c-'0';
        c = getchar();
    }
    return 0;
}
*/

int main(){
    int t;
    //fastRead(t);
    scanf("%d",&t);
    while(t>0){
        long int n,k;
        //fastRead(n);
        //fastRead(k);
        scanf("%ld %ld",&n,&k);
        long int *a;
        a = new long int[n];
        for(int i=0;i<n;i++){
            //fastRead(a[i]);
            scanf("%ld",&a[i]);
        }
        long int temp = 0;
        long int max = 0;
        for(int i=0;i<n;i++){
            //fastRead(temp);
            scanf("%ld",&temp);
            if(max<(k/a[i])*temp){
                max = (k/a[i])*temp;
            }
        }
        printf("%ld\n",max);
        t--;
    }
    return 0;
}
