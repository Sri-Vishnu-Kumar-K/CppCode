#include<iostream>
#include<cstdio>
using namespace std;

struct node{
    int u;
    int v;
    int w;
};

int main(){
    int n;
    scanf("%d",&n);
    node *a;
    a = new node[n-1];
    for(int i=0;i<n-1;i++){
        int d,b,c;
        scanf("%d %d %d",&d,&b,&c);
        a[i].u = d;
        a[i].v = b;
        a[i].w = c;
    }
    for(int i=0;i<n-1;i++){
        cout<<i<<'\t'<<a[i].u<<'\t'<<a[i].v<<'\t'<<a[i].w<<endl;
    }
    int q;
    scanf("%d",&q);
    for(int j=0;j<q;j++){
        int c,k,wt;
        scanf("%d %d %d",&c,&k,&wt);
        if(c==1){
            a[k].w = wt;
        }
        if(c==2){
            cout<<"Hi"<<endl;
            for(int i=0;i<n-1;i++){
                if(a[i].u == k && a[i].v == wt){
                    printf("%d\n",a[i].w);
                    break;
                }
            }
        }
    }
    return 0;
}
