#include<iostream>

int max(int a,int b){
    return a>b?a:b;
}

int result(string s[],int visit[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && visit[i] ==0 && visit[j]==0){
                string sol = s[i]+s[j];
                solrev = sol;
                reverse(solrev.begin(),solrev.end());
                if(sol == solrev){
                    return
                }
            }
        }
    }
}


int main(){
    int n;
    cin>>n;
    string s[n];
    int visit[n];
    for(int i=0;i<n;i++){
        visit[i]=0;
    }
    cout<<result(s,n,visit);
    return 0;
}
