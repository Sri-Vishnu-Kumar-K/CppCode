#include<cstdio>
#define N 1000000007
int main(){
    int t;
    long long int min,max,mid,x,y,z;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%lld",&x,&y,&z);
        if((x>=y)&&(x>=z)){
            max=x;
            if(y<=z){
                mid=z;
                min=y;
            }else{
                mid=y;
                min=z;
            }
        }else if((y>=x)&&(y>=z)){
            max=y;
            if(x<=z){
                mid=z;
                min=x;
            }else{
                mid=x;
                min=z;
            }
        }else if((z>=x)&&(z>=y)){
            max=z;
            if(x<=y){
                mid=y;
                min=x;
            }else{
                mid=x;
                min=y;
            }
        }
        z = ((((min%N)*((mid-1)%N))%N)*((max-2)%N))%N;
        printf("%lld\n",z);
    }
    return 0;
}
