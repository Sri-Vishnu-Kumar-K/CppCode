#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        int snakes[100];
        int ladders[100];
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int s,e;
            cin>>s>>e;
            ladders[s] = e;
        }
        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            int s,e;
            cin>>s>>e;
            snakes[s] = e;
        }
        t--;
    }
    return 0;
}
