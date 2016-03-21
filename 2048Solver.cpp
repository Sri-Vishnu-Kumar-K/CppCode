#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<unistd.h>
using namespace std;

double weights[4][4]={{0.135759,0.121925,0.102812,0.099937},{0.0997992,0.0888405,0.076711,0.0724143},{0.060654,0.0562579,0.037116,0.0161889},{0.0125498,0.00992495,0.00575871,0.00335193}};
int twoci = 0;
int twocii = 0;
double costi(int a[][4]){
	double c = 0,cl = 0, cr = 0, cu = 0 , cd = 0, cm = 0;
	int indi = rand()%4;
	int indj = rand()%4;
	bool flag = true;
	if(a[indi][indj]!=0){
		for(int i =0;i<4;i++){
			for(int j=0;j<4;j++){
				if(a[i][j]==0){
					if(twocii <= 9){
						a[i][j] = 2;
						twocii++;
					}else{
						a[i][j]=4;
						twocii=0;
					}
					flag = false;
					break;
				}
			}
			if(!flag){
				break;
			}
		}
	}else{
		if(twocii<=9){
			a[indi][indj] = 2;
			twocii++;
		}else{
			a[indi][indj] = 4;
			twocii = 0;
		}
		flag = false;
	}	
	int left[4][4],right[4][4],up[4][4],down[4][4];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			left[i][j] =  a[i][j];
			right[i][j] = a[i][j];
			up[i][j] = a[i][j];
			down[i][j] = a[i][j];
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(!up[j][i]){
				for(int k=j+1;k<4;k++){
					if(up[k][i]){
						up[j][i]=up[k][i];
						up[k][i]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(up[j][i]&&up[j][i]==up[j+1][i]){
				up[j][i]+=up[j+1][i];
				up[j+1][i]=0;
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(!up[j][i]){
				for(int k=j+1;k<4;k++){
					if(up[k][i]){
						up[j][i]=up[k][i];
						up[k][i]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cu+=up[i][j] * weights[i][j];
		}
	}
	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(!down[j][i]){
				for(int k=j-1;k>=0;k--){
					if(down[k][i]){
						down[j][i]=down[k][i];
						down[k][i]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=3;j>0;j--){
			if(down[j][i]&&down[j][i]==down[j-1][i]){
				down[j][i]+=down[j-1][i];
				down[j-1][i]=0;
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(!down[j][i]){
				for(int k=j-1;k>=0;k--){
					if(down[k][i]){
						down[j][i]=down[k][i];
						down[k][i]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cd+=down[i][j] * weights[i][j];
		}
	}
			
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(!left[i][j]){
				for(int k=j+1;k<4;k++){
					if(left[i][k]){
						left[i][j]=left[i][k];
						left[i][k]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(left[i][j]&&left[i][j]==left[i][j+1]){
				left[i][j]+=left[i][j+1];
				left[i][j+1]=0;
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(!left[i][j]){
				for(int k=j+1;k<4;k++){
					if(left[i][k]){
						left[i][j]=left[i][k];
						left[i][k]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cl+=left[i][j] * weights[i][j];
		}
	}
	
	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(!right[i][j]){
				for(int k=j-1;k>=0;k--){
					if(right[i][k]){
						right[i][j]=right[i][k];
						right[i][k]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=3;j>0;j--){
			if(right[i][j]&&right[i][j]==right[i][j-1]){
				right[i][j]+=right[i][j-1];
				right[i][j-1]=0;
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(!right[i][j]){
				for(int k=j-1;k>=0;k--){
					if(right[i][k]){
						right[i][j]=right[i][k];
						right[i][k]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cr+=right[i][j] * weights[i][j];
		}
	}
	cm = max(cu,max(cd,max(cr,cl)));
	return cm;	
}

double cost(int a[][4]){
	double c = 0,cl = 0, cr = 0, cu = 0 , cd = 0, cm = 0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			c+=a[i][j] * weights[i][j];
		}
	}
	int indi = rand()%4;
	int indj = rand()%4;
	bool flag = true;
	if(a[indi][indj]!=0){
		for(int i =0;i<4;i++){
			for(int j=0;j<4;j++){
				if(a[i][j]==0){
					if(twoci <= 9){
						a[i][j] = 2;
						twoci++;
					}else{
						a[i][j]=4;
						twoci=0;
					}
					flag = false;
					break;
				}
			}
			if(!flag){
				break;
			}
		}
	}else{
		if(twoci<=9){
			a[indi][indj] = 2;
			twoci++;
		}else{
			a[indi][indj] = 4;
			twoci = 0;
		}
		flag = false;
	}	
	int left[4][4],right[4][4],up[4][4],down[4][4];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			left[i][j] =  a[i][j];
			right[i][j] = a[i][j];
			up[i][j] = a[i][j];
			down[i][j] = a[i][j];
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(!up[j][i]){
				for(int k=j+1;k<4;k++){
					if(up[k][i]){
						up[j][i]=up[k][i];
						up[k][i]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(up[j][i]&&up[j][i]==up[j+1][i]){
				up[j][i]+=up[j+1][i];
				up[j+1][i]=0;
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(!up[j][i]){
				for(int k=j+1;k<4;k++){
					if(up[k][i]){
						up[j][i]=up[k][i];
						up[k][i]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cu+=up[i][j] * weights[i][j];
		}
	}
	cu += costi(up);
	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(!down[j][i]){
				for(int k=j-1;k>=0;k--){
					if(down[k][i]){
						down[j][i]=down[k][i];
						down[k][i]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=3;j>0;j--){
			if(down[j][i]&&down[j][i]==down[j-1][i]){
				down[j][i]+=down[j-1][i];
				down[j-1][i]=0;
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(!down[j][i]){
				for(int k=j-1;k>=0;k--){
					if(down[k][i]){
						down[j][i]=down[k][i];
						down[k][i]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cd+=down[i][j] * weights[i][j];
		}
	}
	cd += costi(down);
			
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(!left[i][j]){
				for(int k=j+1;k<4;k++){
					if(left[i][k]){
						left[i][j]=left[i][k];
						left[i][k]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(left[i][j]&&left[i][j]==left[i][j+1]){
				left[i][j]+=left[i][j+1];
				left[i][j+1]=0;
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(!left[i][j]){
				for(int k=j+1;k<4;k++){
					if(left[i][k]){
						left[i][j]=left[i][k];
						left[i][k]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cl+=left[i][j] * weights[i][j];
		}
	}
	cl+=costi(left);
	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(!right[i][j]){
				for(int k=j-1;k>=0;k--){
					if(right[i][k]){
						right[i][j]=right[i][k];
						right[i][k]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=3;j>0;j--){
			if(right[i][j]&&right[i][j]==right[i][j-1]){
				right[i][j]+=right[i][j-1];
				right[i][j-1]=0;
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(!right[i][j]){
				for(int k=j-1;k>=0;k--){
					if(right[i][k]){
						right[i][j]=right[i][k];
						right[i][k]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cr+=right[i][j] * weights[i][j];
		}
	}
	cr+=costi(right);
	cm = max(cu,max(cd,max(cr,cl)));
	return c+cm;
}

double costprev = 0;
int nextMove(int a[][4],int d){
	int left[4][4],right[4][4],up[4][4],down[4][4];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			left[i][j] =  a[i][j];
			right[i][j] = a[i][j];
			up[i][j] = a[i][j];
			down[i][j] = a[i][j];
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(!up[j][i]){
				for(int k=j+1;k<4;k++){
					if(up[k][i]){
						up[j][i]=up[k][i];
						up[k][i]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(up[j][i]&&up[j][i]==up[j+1][i]){
				up[j][i]+=up[j+1][i];
				up[j+1][i]=0;
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(!up[j][i]){
				for(int k=j+1;k<4;k++){
					if(up[k][i]){
						up[j][i]=up[k][i];
						up[k][i]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(!down[j][i]){
				for(int k=j-1;k>=0;k--){
					if(down[k][i]){
						down[j][i]=down[k][i];
						down[k][i]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=3;j>0;j--){
			if(down[j][i]&&down[j][i]==down[j-1][i]){
				down[j][i]+=down[j-1][i];
				down[j-1][i]=0;
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(!down[j][i]){
				for(int k=j-1;k>=0;k--){
					if(down[k][i]){
						down[j][i]=down[k][i];
						down[k][i]=0;
						break;
					}
				}
			}
		}
	}
			
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(!left[i][j]){
				for(int k=j+1;k<4;k++){
					if(left[i][k]){
						left[i][j]=left[i][k];
						left[i][k]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(left[i][j]&&left[i][j]==left[i][j+1]){
				left[i][j]+=left[i][j+1];
				left[i][j+1]=0;
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(!left[i][j]){
				for(int k=j+1;k<4;k++){
					if(left[i][k]){
						left[i][j]=left[i][k];
						left[i][k]=0;
						break;
					}
				}
			}
		}
	}
	
	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(!right[i][j]){
				for(int k=j-1;k>=0;k--){
					if(right[i][k]){
						right[i][j]=right[i][k];
						right[i][k]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=3;j>0;j--){
			if(right[i][j]&&right[i][j]==right[i][j-1]){
				right[i][j]+=right[i][j-1];
				right[i][j-1]=0;
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(!right[i][j]){
				for(int k=j-1;k>=0;k--){
					if(right[i][k]){
						right[i][j]=right[i][k];
						right[i][k]=0;
						break;
					}
				}
			}
		}
	}
/*	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<up[i][j]<<' ';
		}
		cout<<endl;
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<down[i][j]<<' ';
		}
		cout<<endl;
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<left[i][j]<<' ';
		}
		cout<<endl;
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<right[i][j]<<' ';
		}
		cout<<endl;
	}*/
	double maxu,maxd,maxl,maxr;
	maxu = cost(up);
	maxd = cost(down);
	maxl = cost(left);
	maxr = cost(right);
	cout<<"up "<<maxu<<" down "<<maxd<<" left "<<maxl<<" right "<<maxr<<endl;
	if(maxu==costprev && maxd == costprev && maxl == costprev && maxr == costprev){
		return -1;
	}else if(maxu>maxd && maxu>maxl && maxu>maxr){
		costprev = maxu;
		return 0;
	}else if(maxd>maxu && maxd>maxl && maxd>maxr){
		costprev = maxd;
		return 1;
	}else if(maxl>maxr && maxl>maxu && maxl>maxd){
		costprev = maxl;
		return 2;
	}else if(maxr>maxl && maxr>maxu && maxr>maxd){
		costprev = maxr;
		return 3;
	}else{
		costprev = maxu;
		if(maxd>maxr)
			return 1;
		else
			return 3;
	}
}

int main(){
	int a[4][4];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			a[i][j]=0;
		}
	}
	srand(0);
	int indi = rand()%4, indj = rand()%4;
	a[indi][indj] = 2;
	int twoc = 1;
	int sum = 0;
	while(true){
		indi = rand()%4;
		indj = rand()%4;
		bool flag = true;
		if(a[indi][indj]!=0){
			for(int i =0;i<4;i++){
				for(int j=0;j<4;j++){
					if(a[i][j]==0){
						if(twoc <= 9){
							a[i][j] = 2;
							twoc++;
						}else{
							a[i][j]=4;
							twoc=0;
						}
						flag = false;
						break;
					}
				}
				if(!flag){
					break;
				}
			}
		}else{
			if(twoc<=9){
				a[indi][indj] = 2;
				twoc++;
			}else{
				a[indi][indj] = 4;
				twoc = 0;
			}
			flag = false;
		}
		cout<<"Current State"<<endl;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cout<<a[i][j]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
		int d = nextMove(a,2);
		cout<<"d Value is "<<d<<endl;
		if(d == 0){
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					if(!a[j][i]){
						for(int k=j+1;k<4;k++){
							if(a[k][i]){
								a[j][i]=a[k][i];
								a[k][i]=0;
								break;
							}
						}
					}
				}
			}
			for(int i=0;i<4;i++){
				for(int j=0;j<3;j++){
					if(a[j][i]&&a[j][i]==a[j+1][i]){
						a[j][i]+=a[j+1][i];
						sum += a[j][i];
						a[j+1][i]=0;
					}
				}
			}
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					if(!a[j][i]){
						for(int k=j+1;k<4;k++){
							if(a[k][i]){
								a[j][i]=a[k][i];
								a[k][i]=0;
								break;
							}
						}
					}
				}
			}			
		}else if(d == 1 ){
			for(int i=0;i<4;i++){
				for(int j=3;j>=0;j--){
					if(!a[j][i]){
						for(int k=j-1;k>=0;k--){
							if(a[k][i]){
								a[j][i]=a[k][i];
								a[k][i]=0;
								break;
							}
						}
					}
				}
			}
			for(int i=0;i<4;i++){
				for(int j=3;j>0;j--){
					if(a[j][i]&&a[j][i]==a[j-1][i]){
						a[j][i]+=a[j-1][i];
						sum += a[j][i];
						a[j-1][i]=0;
					}
				}
			}
			for(int i=0;i<4;i++){
				for(int j=3;j>=0;j--){
					if(!a[j][i]){
						for(int k=j-1;k>=0;k--){
							if(a[k][i]){
								a[j][i]=a[k][i];
								a[k][i]=0;
								break;
							}
						}
					}
				}
			}			
		}else if(d == 2){
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					if(!a[i][j]){
						for(int k=j+1;k<4;k++){
							if(a[i][k]){
								a[i][j]=a[i][k];
								a[i][k]=0;
								break;
							}
						}
					}
				}
			}
			for(int i=0;i<4;i++){
				for(int j=0;j<3;j++){
					if(a[i][j]&&a[i][j]==a[i][j+1]){
						a[i][j]+=a[i][j+1];
						sum += a[i][j];
						a[i][j+1]=0;
					}
				}
			}
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					if(!a[i][j]){
						for(int k=j+1;k<4;k++){
							if(a[i][k]){
								a[i][j]=a[i][k];
								a[i][k]=0;
								break;
							}
						}
					}
				}
			}
		}else if(d == 3){
			for(int i=0;i<4;i++){
				for(int j=3;j>=0;j--){
					if(!a[i][j]){
						for(int k=j-1;k>=0;k--){
							if(a[i][k]){
								a[i][j]=a[i][k];
								a[i][k]=0;
								break;
							}
						}
					}
				}
			}
			for(int i=0;i<4;i++){
				for(int j=3;j>0;j--){
					if(a[i][j]&&a[i][j]==a[i][j-1]){
						a[i][j]+=a[i][j-1];
						sum += a[i][j];
						a[i][j-1]=0;
					}
				}
			}
			for(int i=0;i<4;i++){
				for(int j=3;j>=0;j--){
					if(!a[i][j]){
						for(int k=j-1;k>=0;k--){
							if(a[i][k]){
								a[i][j]=a[i][k];
								a[i][k]=0;
								break;
							}
						}
					}
				}
			}			
		}else if(d == -1){
			cout<<"Game Over"<<endl;
			return 0;
		}
		usleep(500000);
		cout<<"Next Moved State"<<endl;
		int score = 0;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cout<<a[i][j]<<' ';
				//score += a[i][j];
			}
			cout<<endl;
		}
		cout<<"Score: "<<sum<<endl;
		//cout<<"Bubye"<<endl;
		//break;
	}
	return 0;
}
