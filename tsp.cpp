#include<stdio.h>
#include<iostream>
#include<climits>
using namespace std;


int c = 0,cost = INT_MAX;

void swap (int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void copy_array(int *a, int n,int **graph){
    int i, sum = 0;
    for(i = 0; i <= n; i++){
        sum += graph[a[i % 4]][a[(i + 1) % 4]];
    }
    if (cost > sum){
        cost = sum;
    }
}
void permute(int *a, int i, int n,int **graph) {
   int j, k;
   if (i == n){
        copy_array(a, n,graph);
   }
   else{
        for (j = i; j <= n; j++){
            swap((a + i), (a + j));
            permute(a, i + 1, n,graph);
            swap((a + i), (a + j));
        }
    }
}
int main(){
   int i, j , **graph,*a;
   int n,t;
   scanf("%d %d",&n,&t);
   graph = new int *[n];
   a = new int[n];
   for(int i=0;i<n;i++){
        graph[i]=new int[n];
   }
   for(int i=0;i<n;i++){
    a[i]=i;
    for(int j=0;j<n;j++){
        scanf("%d",&graph[i][j]);
    }
   }
   permute(a, 0, n-1,graph);
   printf("%d",cost);
   if(cost==t){
    printf("possible\n");
   }else{
    printf("impossible\n");
   }
}
