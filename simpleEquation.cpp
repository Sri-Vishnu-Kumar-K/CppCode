#include <iostream>
#include <algorithm>
using namespace std;
long long f(int z,int N){

		if(N<0)
            return 0;
		return min(z+1,N+1);
}
long long f(int y,int z,int N){
		long long sum=0;
		for(int i=0;i<=y;i++){
            sum = sum + f(z,N-i);
        }
	return sum;
}
long long f(int x,int y,int z,int N){
		long long sum=0;
		for(int i=0;i<=x;i++)
			sum = sum + f(y,z,N-i);
    return sum;
}

int main(){
		int t;
		cin>>t;
		for(int i=0;i<t;i++){
            int x,y,z,n;
            cin>>n>>x>>y>>z;
            cout<<f(x,y,z,n)<<endl;
        }
    return 0;
}
