#include<iostream>
#include<cstdio>
#include<deque>
#include<algorithm>
#include<set>
#include<cstring>
using namespace std;

int PToPDash(string t,string s[],int start,int en,deque<int>p[]){
    int deletedValues[t.length()];
    for(int i=0;i<t.length();i++){
        deletedValues[i]=0;
    }
    for(int i=0;i<2;i++){
        deque<int>::iterator it;
        it = p[s[i].at(0)].begin();
        int count=0;
        while(it != p[s[i].at(0)].end()){
            int ind= *it;
            cout<<"The index is "<<*it<<endl;
            if(deletedValues[ind]==0){
                int flag = 0;
                cout<<"Checking values:"<<endl;
                for(int j=0;j<s[i].length();j++){
                    cout<<ind+j<<" ";
                    if(t[ind+j]!=s[i].at(j)||deletedValues[ind+j]==1){
                        flag = 1;
                        cout<<"failed"<<endl;
                        break;
                    }
                    cout<<"passed"<<endl;
                }
                if(flag == 0){
                    cout<<"The del vals are:"<<endl;
                    for(int j=0;j<s[i].length();j++){
                        deletedValues[ind+j]=1;
                        cout<<ind+j<<endl;
                    }
                    count++;
                }
            }
            it++;
        }
        cout<<i<<" "<<count<<endl;
    }
}

int main(){
    deque<int>q[128];
    string a;
    string temp;
    getline(cin,temp);
    while(temp.length()>0){
        a = a + temp;
        getline(cin,temp);
    }
    for(int i=0;i<a.length();i++){
       q[a[i]].push_back(i);
    }
    string b[4]={" live"," to ","o","t"};
    deque<int>::iterator it;
    int count[4]={0};
    int max = -1;
    for(int i=0;i<4;i++){
        it = q[b[i].at(0)].begin();
        while(it != q[b[i].at(0)].end()){
            int ind= *it;
            int flag = 0;
            for(int j=0;j<b[i].length();j++){
                if(a[ind+j]!=b[i].at(j)){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                count[i]++;
            }
            it++;
        }
        cout<<count[i]<<endl;
        if(count[i]>max){
            max = count[i];
        }
    }
    cout<<"Max is "<<max<<endl;
    string s[2]={" live"," to "};
    string t = a;
    PToPDash(t,s,0,t.length()-1,q);
    return 0;
}
