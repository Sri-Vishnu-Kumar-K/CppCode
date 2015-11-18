#include<iostream>
#include<cstdio>


int main(){
    int testCase;
    int noCities;
    int minPopulation;
    int population;
    long long int sum;

    scanf("%d",&testCase);

    while(testCase--) {

        scanf("%d",&noCities);
        sum = 0;
        minPopulation = 1000001;
        while(noCities--) {
            scanf("%d",&population);
            sum = sum + population;
            if(population < minPopulation){
                minPopulation = population;
            }
        }
        sum = sum - minPopulation;
        sum = sum * minPopulation;
        printf("%lld\n",sum);
    }
    return 0;
}
