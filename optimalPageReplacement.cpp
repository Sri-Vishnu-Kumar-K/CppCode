#include<stdio.h>

int main(){
    int n;
    printf("Enter the no of page requests\n");
    scanf("%d",&n);
    int a[100];
    printf("Enter the page requests\n");
    int max = -1;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(max<a[i]){
            max = a[i];
        }
    }
    int count[max+1];
    int noOfFrames;
    printf("Enter the no of frames\n");
    scanf("%d",&noOfFrames);
    int frames[100];
    for(int i=0;i<noOfFrames;i++){
        frames[i]=a[i];
    }
    int hits = 0;
    for(int i=noOfFrames;i<n;i++){
        bool flag = false;
        for(int j=0;j<noOfFrames;j++){
            if(a[i]==frames[j]){
                hits++;
                flag = true;
            }
        }
        if(flag == false){
            int min1 = 999;
            int minind = -1;
            for(int k = 0;k<noOfFrames;k++){
                int count1 = 0;
                for(int l = i ;l<n;l++){
                    if(frames[k]==a[l]){
                        count1++;
                    }
                }
                if(count1<min1){
                    min1 = count1;
                    minind = k;
                }
            }
            printf("%d has been replaced by %d\n",frames[minind],a[i]);
            frames[minind] = a[i];
        }
    }
    printf("The no of hits are %d\nThe no of misses are %d\n",hits,n-hits);
    return 0;
}
