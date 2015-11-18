#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int fact(long long p){
    long long f = 1;
    for(long long i = 2;i<=p;i++){
        f *=i;
    }
    return f;
}


int main() {
    int t;
    cin>>t;
    while(t>0){
        string s;
        cin>>s;
        long long int sum = 0;
        for(int i=0;i<s.length();i++){
            sum+= s.at(i)-48;
        }
        long long int f = fact(s.length()-1);
        sum = sum*f;
        double mul = 1;
        for(int i=1;i<s.length();i++){
            mul = mul + pow(10,i);
        }
        cout<<sum*mul<<endl;
        t--;
    }
    return 0;
}
