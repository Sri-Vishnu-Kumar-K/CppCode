#include<stdio.h>

int main(){
    int a,b,c,d,ma,mb,mc,md;
    printf("Enter the octets\n");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("Enter the bit masks\n");
    scanf("%d %d %d %d",&ma,&mb,&mc,&md);
    printf("The bit masked op is\n");
    printf("%d.%d.%d.%d",a&ma,b&mb,c&mc,d&md);
    return 0;
}
