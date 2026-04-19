#include <stdio.h>
#define N 10

int wt[N];
int value[N];
float ratio[N];

void bubble(int num){
    for(int i=0;i<num-1;i++){
        for(int j=0;j<num-1-i;j++){
            if(ratio[j] < ratio[j+1]){
                float temp1=ratio[j+1];
                ratio[j+1]=ratio[j];
                ratio[j]=temp1;

                int temp2=wt[j+1];
                wt[j+1]=wt[j];
                wt[j]=temp2;

                int temp3=value[j+1];
                value[j+1]=value[j];
                value[j]=temp3;
            }
        }
    }
}

float FKS(int M, int n){
    float total = 0;
    for(int i = 0; i < n; i++){
        if(wt[i] <= M){
            total += value[i];
            M -= wt[i];
        }
        else{
            total += ratio[i] * M;
            break;
        }
    }
    return total;
}

int main() {
    int num, M;

    printf("Enter Fractional Knapsack Capacity: ");
    scanf("%d", &M);

    printf("Enter Number of Objects: ");
    scanf("%d", &num);

    printf("\n");

    for(int i=0;i<num;i++){
        printf("For Object %d\n", i+1);

        printf("Enter Weight: ");
        scanf("%d", &wt[i]);

        printf("Enter Value: ");
        scanf("%d", &value[i]);

        printf("\n");

        ratio[i] = (float)value[i] / wt[i];
    }

    bubble(num);

    printf("Maximum Profit is %.2f", FKS(M, num));

    return 0;
}
