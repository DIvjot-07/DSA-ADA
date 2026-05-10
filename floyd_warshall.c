#include <stdio.h>

#define N 5
#define INF 99999

int D[N][N];

void floyd(int num){
    for(int k = 0; k < num; k++){
        for(int i = 0; i < num; i++){
            for(int j = 0; j < num; j++){
                if(D[i][j] > D[i][k] + D[k][j]){
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

void display(int num){
    printf("\nMatrix\n");

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){

            if(D[i][j] == INF){
                printf("INF\t");
            }
            else{
                printf("%d\t", D[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n");
}

int main(){

    int num;

    printf("Enter Value of n for n×n matrix: ");
    scanf("%d", &num);

    printf("Enter -1 for not known\n");

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){

            printf("Enter %d -> %d: ", i, j);
            scanf("%d", &D[i][j]);

            if(D[i][j] == -1){
                D[i][j] = INF;
            }
        }
    }

    // Distance from node to itself should be 0
    for(int i = 0; i < num; i++){
        D[i][i] = 0;
    }

    printf("\nBefore Floyd Warshall:\n");
    display(num);

    floyd(num);

    printf("After Floyd Warshall:\n");
    display(num);

    return 0;
}
