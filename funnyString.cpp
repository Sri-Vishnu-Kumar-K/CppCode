#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        string a;
        cin>>a;
        int flag = 0;
        for(int i=0;i<a.length()-1;i++){
            int val,val1;
            if(a.at(i)>a.at(i+1)){
                val = a.at(i) - a.at(i+1);
            }else{
                val = a.at(i+1) - a.at(i);
            }
            if(a.at(a.length()-2-i)>a.at(a.length()-i-1)){
                val1 = a.at(a.length()-2-i) - a.at(a.length()-i-1);
            }else{
                val1 = a.at(a.length()-1-i) - a.at(a.length()-i-2);
            }
            if(val == val1){
                flag =1;
            }else{
                flag = 0;
                break;
            }
        }
        if(flag ==1){
            cout<<"Funny"<<endl;
        }else{
            cout<<"Not Funny"<<endl;
        }
        t--;
    }
    return 0;
}
