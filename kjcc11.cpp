#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int l1[a],l2[b],l3[c];
        for(int i=0;i<a;i++){
            scanf("%d",&l1[i]);
        }
        for(int i=0;i<b;i++){
            scanf("%d",&l2[i]);
        }
        for(int i=0;i<c;i++){
            scanf("%d",&l3[i]);
        }
        int l1l2 = 0, l1l3 = 0, l2l3 = 0, l1l2l3 = 0;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(l1[i]==l2[j]){
                    l1l2++;
                }
            }
        }
        for(int i=0;i<a;i++){
            for(int j=0;j<c;j++){
                if(l1[i]==l3[j]){
                    l1l3++;
                }
            }
        }
        for(int i=0;i<b;i++){
            for(int j=0;j<c;j++){
                if(l2[i]==l3[j]){
                    l2l3++;
                }
            }
        }
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                for(int k=0;k<c;k++){
                    if(l1[i]==l2[j] && l2[j] == l3[k]){
                        l1l2l3++;
                    }
                }
            }
        }
        printf("%d %d %d %d\n",l1l2, l2l3, l1l3, l1l2l3);
        t--;
    }

    return 0;
}
