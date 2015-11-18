#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

int main() {
    int t;
    cin>>t;
    while(t>0){
        string a;
        cin>>a;
        string b[a.length()];
        b[0] = a;
        for(int i=1;i<a.length();i++){
            b[i] = a.substr(i,a.length()-i);
        }
        long long int res=0;
        for(int i=0;i<a.length();i++){
            for(int j = 0;j<b[i].length();j++){
                if(a.at(j)==b[i].at(j)){
                    res++;
                }else{
                    break;
                }
            }
        }
        printf("%lld\n",res);
        t--;
    }
    return 0;
}

