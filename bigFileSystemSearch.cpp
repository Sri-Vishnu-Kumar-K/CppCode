#include<iostream>
using namespace std;

struct files{
    int size;
    long a[300];
};

int query_all(files f[],long arr[],int visit[],int n,int k){
    int count = 0;
    for(int i=0;i<n;i++){
        int count1=0;
        for(int j=0;j<f[i].size;j++){
            for(int l =0;l<k;l++){
                if(f[i].a[j]==arr[l] && visit[l]!=1){
                    count1++;
                    visit[l]=1;
                }
            }
        }
        if(count1 == k){
            count++;
        }
        for(int p=0;p<k;p++){
            visit[p]=0;
        }
    }
    return count;
}

int query_any(files f[],long arr[],int visit[],int n,int k){
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<f[i].size;j++){
            bool flag = true;
            for(int l=0;l<k;l++){
                if(f[i].a[j]==arr[l]){
                    count++;
                    flag = false;
                    break;
                }
            }
            if(flag == false){
                break;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    files f[n];
    for(int x=0;x<n;x++){
        cin>>f[x].size;
        for(int i=0;i<f[x].size;i++){
            cin>>f[x].a[i];
        }
    }
    int q;
    cin>>q;
    while(q>0){
        int t,k;
        cin>>t>>k;
        long arr[k];
        int visit[k];
        for(int i=0;i<k;i++){
            visit[i]=0;
        }
        for(int i=0;i<k;i++){
            cin>>arr[i];
        }
        if(t==1){
            cout<<query_all(f,arr,visit,n,k)<<endl;
        }else if(t==2){
            cout<<query_any(f,arr,visit,n,k)<<endl;
        }else if(t==3){
            cout<<query_any(f,arr,visit,n,k)-query_all(f,arr,visit,n,k)<<endl;
        }
        q--;
    }
    return 0;
}
