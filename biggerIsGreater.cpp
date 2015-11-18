#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char s[100];
        cin>>s;
        bool flag1 = true;
        for(int i = strlen(s)-1;i>=1;i--){
            bool flag = true;
            for(int j = i-1;j>=0;j--){
                if(s[i]>s[j]){
                    char temp = s[i];
                    s[i]=s[j];
                    s[j]=temp;
                    for(int k = i+1; k<strlen(s);k++){
                        if(s[i]>s[k]){
                            char temp1 = s[i];
                            s[i] = s[k];
                            s[k] = temp1;
                        }
                    }
                    flag = false;
                    flag1 = false;
                    break;
                }
            }
            if(flag == false){
                break;
            }
        }
        if(flag1 == true){
            cout<<"no answer"<<endl;
        }else{
            cout<<s<<endl;
        }
    }
    return 0;
}
