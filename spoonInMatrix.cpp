#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    char arr[100][101];
    int t,r,c,i,j,flag;
    scanf("%d", &t);
    while(t--){
        flag = 0;
        scanf("%d %d", &r, &c);
        gets(arr[0]);
        for(i = 0; i < r; i++){
            gets(arr[i]);
        }
        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
                if((arr[i][j] == 's' || arr[i][j] == 'S') && j+4 < c){
                    if((arr[i][j+1] == 'p' || arr[i][j+1] == 'P') && (arr[i][j+2] == 'o' || arr[i][j+2] == 'O') && (arr[i][j+3] == 'o' || arr[i][j+3] == 'O') && (arr[i][j+4] == 'n' || arr[i][j+4] == 'N')){
                        flag = 1;
                        break;
                    }
                }
                if((arr[i][j] == 's' || arr[i][j] == 'S') && i+4 < r){
                    if((arr[i+1][j] == 'p' || arr[i+1][j] == 'P') && (arr[i+2][j] == 'o' || arr[i+2][j] == 'O') && (arr[i+3][j] == 'o' || arr[i+3][j] == 'O') && (arr[i+4][j] == 'n' || arr[i+4][j] == 'N')){
                        flag = 1;
                        break;
                    }
                }
            }
        if(flag)
            break;
        }
        if(flag == 1){
            printf("There is a spoon!\n");
        }else{
            printf("There is indeed no spoon!\n");
        }
    }
    return 0;
}
