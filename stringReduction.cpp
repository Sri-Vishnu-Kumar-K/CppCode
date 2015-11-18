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

int stringReduction(string a) {
    bool flag = false;
    while(flag == false){
        flag = true;
        for(int i=0;i<a.length()-1;i++){
            string b,c ;
            b = a.at(i);
            c = a.at(i+1);
            b.append(c);
            if(b=="bc" || b=="cb" ){
                flag = false;
                a.replace(i,2,"a");
            }
            if(b=="ba" || b=="ab" ){
                flag = false;
                a.replace(i,2,"c");
            }
            if(b=="ac" || b=="ca" ){
                flag = false;
                a.replace(i,2,"b");
            }
        }
    }
    return a.length();
}

int main() {
    int res, t, i;
    cin>>t;
    string a;
    for (i=0;i<t;i++) {
        cin>>a;
        res=stringReduction(a);
        printf("%d\n",res);
    }
    return 0;
}

