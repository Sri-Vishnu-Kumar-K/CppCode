#include<iostream>
#include<stack>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        stack<int> s;
        string sol = "YES";
        int low = -1;
        for(int i=0;i<n;i++){
            if(low>-1 && a[i]<low){
                sol = "NO";
                break;
            }
            while(!s.empty() && s.top()<a[i]){
                low = s.top();
                s.pop();
            }
            s.push(a[i]);
        }
        cout<<sol<<endl;
        t--;
    }

    return 0;
}
