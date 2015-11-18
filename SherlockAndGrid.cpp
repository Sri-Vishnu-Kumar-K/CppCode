 #include<cstdio>

 int main(){
    int i,j,n,t;
    long count;
    scanf("%d",&t);
    while(t--){
        count=0;
        scanf("%d",&n);
        char a[n+1][n+1];
        int fnd[n];
        for(i=0;i<n;i++){
            gets(a[i]);
        }
        for(j=0;j<n;j++){
            fnd[j] = -1;
        }
        for(j=0;j<n;j++){
            for(i=n-1;i>=0;i--){
                if(a[i][j] == '#'){
                    fnd[j] = i;
                    break;
                }
            }
        }

        for(i=0;i<n;i++){
            for(j=n-1;j>=0;j--){
                if(a[i][j] == '.'){
                    if(i> fnd[j])
                        count++;
                }
                if(a[i][j] == '#')
                    break;
            }
        }
        printf("%d",count);
    }
    return 0;
}
