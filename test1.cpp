#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

void markMultiples(bool arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
}

// A function to print all prime numbers smaller than n
void SieveOfEratosthenes(int n,int a[],int max)
{
    // There are no prime numbers smaller than 2
    if (n >= 2)
    {
        // Create an array of size n and initialize all elements as 0
        bool arr[max];
        for(int i=0;i<max;i++)
            arr[i]=false;

        /* Following property is maintained in the below for loop
           arr[i] == 0 means i + 1 is prime
           arr[i] == 1 means i + 1 is not prime */
        for (int i=1; i<max; ++i)
        {
            if ( arr[i] == false )
            {
                markMultiples(arr, i+1, max);
            }
        }
        for(int i=0;i<n;i++){
            if(arr[a[i]-1] == false){
                cout<<a[i]<<" ";
            }
        }
    }
}

// Driver Program to test above function
int main()
{
    int n;
    cout<<"Enter the no of array elements";
    cin>>n;
    cout<<"Enter the elements"<<endl;
    int a[n];
    int max = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>max){
            max = a[i];
        }
    }
    SieveOfEratosthenes(n,a,max);
    return 0;
}
