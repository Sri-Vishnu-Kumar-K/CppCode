#include<iostream>

using namespace std;

int main(){
    int rpm;
    cin>>rpm;
    int p = rpm;
    int a[4];
    int k = 3;
    while(rpm!=0){
        a[k] = rpm%10;
        rpm = rpm/10;
        k--;
    }
    int start = 0;
    for(int i=0;i<10;i++){//considering each iteration as a year.
        int sumOfSquares = 0;
        for(int j=0;j<4;j++){
            sumOfSquares += a[j]*a[j];
        }
        cout<<"Sum of squares is "<<sumOfSquares<<endl;
        int multi = sumOfSquares*323;
        cout<<"Multi "<<multi<<endl;
        int temp = a[3];
        for(int i=3;i>0;i--){
            a[i]=a[i-1];
        }
        a[0] = temp;
        for(int i=0;i<4;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        int lastTwo = a[2]*10 + a[3];
        cout<<"Last two "<<lastTwo<<endl;
        int newRpm = multi + lastTwo;
        cout<<newRpm<<endl;
        if(newRpm > 8*p){
            break;
        }
        rpm = newRpm;
    }
    return 0;
}
