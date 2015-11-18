#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findMax(vector<int> v[],int a[],int visit[],int n){
    int max = 0;
    int maxind = -1;
    for(int i=0;i<n;i++){
        if(visit[i]==1){
            for(vector<int>::iterator it = v[i].begin();it != v[i].end(); it++){
                int j = *it;
                if(a[j]>max && visit[j]==0){
                    max = a[j];
                    maxind = j;
                }
            }
        }
    }
    return maxind;
}

int findPrevMax(vector<int> v[],int a[],int visit[],int n){
    int max = 0;
    int maxind = -1;
    for(int i=0;i<n;i++){
        if(visit[i]==2){
            for(vector<int>::iterator it = v[i].begin();it!=v[i].end();it++){
                int j = *it;
                if(a[j]>max && visit[j]==0){
                    max = a[j];
                    maxind = j;
                }
            }
        }
    }
    return maxind;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    int visit[n];
    int max = 0;
    int maxind = -1;
    int prevmax = 0;
    int prevind = -1;
    vector<int> v[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        visit[i]=0;
        if(a[i]>max){
            max = a[i];
            maxind = i;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]>prevmax && i != maxind){
            prevind = i;
            prevmax = a[i];
        }
    }
    for(int i=0;i<n-1;i++){
        int s,e;
        cin>>s>>e;
        v[s-1].push_back(e-1);
        v[e-1].push_back(s-1);
    }
    if(maxind != -1)
        visit[maxind]=1;
    if(prevind != -1)
        visit[prevind]=2;
    int k = 0;
    while(k<n-1){
        maxind = findMax(v,a,visit,n);
        if(maxind != -1)
            visit[maxind]=1;
        prevind = findPrevMax(v,a,visit,n);
        if(prevind != -1)
            visit[prevind]=2;
        k++;
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if(visit[i]==1){
            count+=a[i];
        }
    }
    cout<<count;
    return 0;
}
