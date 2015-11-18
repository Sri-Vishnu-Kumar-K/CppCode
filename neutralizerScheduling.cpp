#include <stdio.h>
#include <stdlib.h>
#include<iostream>

using namespace std;

struct processor{
    int proNo;
    int noProc;
};
struct MaxHeap{
    int size;
    processor* array;
};
void swap(processor* a, processor* b) {
    processor t = *a;
    *a = *b;
    *b = t;
}
int maxHeapify(struct MaxHeap* maxHeap, int idx){
    int largest = idx;
    int left = (idx << 1) + 1;
    int right = (idx + 1) << 1;
    if (left < maxHeap->size && maxHeap->array[left].noProc > maxHeap->array[largest].noProc)
        largest = left;
    if (right < maxHeap->size && maxHeap->array[right].noProc > maxHeap->array[largest].noProc)
        largest = right;
    if (largest != idx){
        swap(&maxHeap->array[largest], &maxHeap->array[idx]);
        maxHeapify(maxHeap, largest);
    }
    return 0;
}
struct MaxHeap* createAndBuildHeap(processor *array, int size){
    int i;
    struct MaxHeap* maxHeap = (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size = size;
    maxHeap->array = array;
    for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
        maxHeapify(maxHeap, i);
    return maxHeap;
}
int heapSort(processor* array, int size){
    struct MaxHeap* maxHeap = createAndBuildHeap(array, size);
    while (maxHeap->size > 1){
        swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
        --maxHeap->size;
        maxHeapify(maxHeap, 0);
    }
    return 0;
}

int printArray(processor* arr, int size){
    int i;
    for (i = 0; i < size; ++i)
        printf("The processor id is %d no of processes are %d\n",arr[i].proNo,arr[i].noProc);
    return 0;
}

int AvgWait(int **a,processor array[],int size){
    int count = 0;
    for(int count=0;count<size;count++){
        int change = 1;
        int wait = 0;
        int i = array[count].proNo-1;
        int j = 0;
        int k = array[count].noProc - 1;
        int wait1=0;
        while(j<k){
            if(array[count].noProc == 1){
                break;
            }
            if(change%2 == 1){
                wait += a[i][j];
                j++;
            }else{
                wait += a[i][k];
                k--;
            }
            change++;
            wait1 += wait;
        }
        cout<<"The avg wait time for pid "<<array[count].proNo<<" is "<<(float)wait1/array[count].noProc<<endl;
    }
    return 0;
}

int main(){
    processor *arr;
    int size ;
    cout<<"Enter no of processors"<<endl;
    cin>>size;
    arr = new processor[size];
    cout<<"Enter processor id and no of processes"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i].proNo>>arr[i].noProc;
    }
    printf("Given processors are \n");
    printArray(arr, size);
    int **a;
    a = new int*[size];
    for(int i=0;i<size;i++){
        a[i] = new int[10];
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<arr[i].noProc;j++){
            cout<<"Enter burst time for process no "<<j+1<<" in "<<i+1<<" processor"<<endl;
            cin>>a[i][j];
        }
        for(int j = arr[i].noProc;j<10;j++){
            a[i][j]=0;
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<arr[i].noProc-1;j++){
            for(int k=j+1;k<arr[i].noProc;k++){
                if(a[i][j]>a[i][k]){
                    int p = a[i][j];
                    a[i][j]=a[i][k];
                    a[i][k] = p;
                }
            }
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<10;j++){
            cout<<a[i][j]<<"  ";
        }
        cout<<endl;
    }
    heapSort(arr, size);
    printArray(arr, size);
    /*AvgWait(a,arr,size);*/
    char newProc ;
    cout<<"Enter y if new process enters"<<endl;
    cin>>newProc;
    while(newProc=='y'){
        int pNo = arr[0].proNo -1;
        arr[0].noProc +=1;
        cout<<"Enter burst time of process"<<endl;
        cin>>a[pNo][arr[0].noProc-1];
        for(int j=0;j<arr[0].noProc-1;j++){
            for(int k = j+1;k<arr[0].noProc;k++){
                if(a[pNo][j]>a[pNo][k]){
                    int p = a[pNo][j];
                    a[pNo][j]=a[pNo][j];
                    a[pNo][k] = p;
                }
            }
        }
        heapSort(arr, size);
        printArray(arr, size);
        /*AvgWait(a,arr,size);*/
        for(int i=0;i<size;i++){
            for(int j=0;j<10;j++){
                cout<<a[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<"Enter y if new process enters"<<endl;
        cin>>newProc;
    }
    return 0;
}
