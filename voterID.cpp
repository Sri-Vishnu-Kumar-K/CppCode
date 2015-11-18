#include<iostream>
#include<cstdio>
#include<list>
#include<algorithm>
using namespace std;

bool search(int a, int b[],int n){
    for(int i=0;i<n;i++){
        if(b[i]==a){
            return true;
        }
    }
    return false;
}

int main(){
    int n1,n2,n3,n4;
    scanf("%d %d %d",&n1,&n2,&n3);
    int *a,*b,*c,*d;
    a = new int[n1];
    b = new int[n2];
    c = new int[n3];
    if(n1<n2<n3){
        n4=n1;
    }else if(n2<n3){
        n4=n2;
    }else{
        n4=n3;
    }
    d = new int[n4];
    for(int i=0;i<n1;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n2;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<n3;i++){
        scanf("%d",&c[i]);
    }
    list<int>l;
    list<int>::iterator it;
    int k=0;
    for(int i=0;i<n1;i++){
        it=find(l.begin(),l.end(),a[i]);
        if(search(a[i],b,n2)&&it==l.end()){
            d[k]=a[i];
            k++;
            l.push_back(a[i]);
        }
    }
    for(int i=0;i<n2;i++){
        it = find(l.begin(),l.end(),b[i]);
        if(search(b[i],c,n3)&& it==l.end()){
            d[k]=b[i];
            k++;
            l.push_back(b[i]);
        }
    }
    for(int i=0;i<n3;i++){
        it = find(l.begin(),l.end(),c[i]);
        if(search(c[i],a,n1&& it==l.end())){
            d[k]=c[i];
            k++;
            l.push_back(c[i]);
        }
    }
    printf("%d\n",k);
    for(int i=0;i<k;i++){
        printf("%d\n",d[i]);
    }
    return 0;
}
