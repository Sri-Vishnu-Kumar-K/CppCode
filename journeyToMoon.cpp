#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>
#include <iterator>
using namespace std;

int main(){
    int n, e;
    cin>>n>>e;
    bool a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=false;
        }
    }
    for(int i=0;i<e;i++){
        int st,en;
        cin>>st>>en;
        a[st][en]=true;
        a[en][st]=true;
    }
    long long result = 0;
    vector<int>cluster(n);
    for(int i=0;i<n;i++){
        cluster[i]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] && cluster[i]!=cluster[j]){
                for(int k=0;k<n;k++){
                    if(cluster[k]==cluster[j]){
                        cluster[k]=cluster[i];
                    }
                }
            }
        }
    }
    vector <int>v(n,0);
    for(int i=0;i<n;i++){
        v[cluster[i]]++;
    }
    for(int i=0;i<n;i++){
        if(v[i]!=0){
            for(int j=i+1;j<n;j++){
                if(v[j]!=0){
                    result += v[i]*v[j];
                }
            }
        }
    }
    cout << result << endl;
    return 0;
}
