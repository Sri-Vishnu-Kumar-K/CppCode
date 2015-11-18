#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string *a;
    a = new string[n];
    int *x;
    x = new int[m];
    int max = -32767;
    int maxc=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        x[i]=0;
    }
    for(int i=0;i<n-1;i++){
        int count=0;
        for(int j =i+1;j<n;j++){
            for(int k =0;k<m;k++){
                if(a[i].at(k)=='1' && x[k]!=1){
                    x[k]=1;
                    count ++;
                }else if(a[j].at(k)=='1' && x[k]!=1){
                    x[k]=1;
                    count++;
                }
            }
        }
        for(int q = 0;q<m;q++){
            x[q]=0;
        }
        if(count>=max){
            if(max == count){
               maxc+=1;
            }else{
                max = count;
                maxc=1;
            }
        }
    }
    cout<<max<<endl<<maxc;
    return 0;
}
