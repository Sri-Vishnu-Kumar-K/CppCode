#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

inline void fastRead(int &x){
    register int c = getchar();
    x=0;
    int neg=0;
    for(;(c<48 || c>57)&&c!='-';c=getchar());
    if(c=='-'){
        neg=1;
        c=getchar();
    }
    for(;(c>47 || c<58);c=getchar()){
        x=(x<<1)+(x<<3)+c-'0';
    }
    if(neg==1){
        x=-x;
    }

}


int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int *a,*b,*v,n;
        scanf("%d",&n);
        a = new int[n];
        b = new int[n];
        v=new int[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            v[i]=0;
        }
        int pdt=0;
        for(int i=0;i<n;i++){
            int min=32767;
            for(int j=0;j<n;j++){
                if(min>a[i]*b[j] && v[j]!=1){
                    min=a[i]*b[j];
                    v[j]=1;
                }
            }
            pdt+=min;
        }
        cout<<pdt<<endl;
        t--;
    }
    return 0;
}
