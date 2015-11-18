#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int n,i,j,c;
	scanf("%d",&n);
	while(n--){
		c=0;
		scanf("%d %d",&i,&j);
		while(i!=j){
			if(i>j){
				i=i>>1;
			}else{
				j=j>>1;
			}
			c++;
		}
		printf("%d\n",c);
	}
	return 0;
}
