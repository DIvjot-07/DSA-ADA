#include <stdio.h>
#define N 10

int A[N], S[N], F[N];

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(int num){
    for(int i = 0; i < num - 1; i++){
        for(int j = 0; j < num - i - 1; j++){
            if(F[j] > F[j + 1]){
                swap(&F[j], &F[j + 1]);
                swap(&S[j], &S[j + 1]);
                swap(&A[j], &A[j + 1]);
            }
        }
    }
}

void Act_sel(int num){
    printf("Activity Done: A%d ", A[0] + 1);

    int Finish = F[0];

    for(int i = 1; i < num; i++){
        if(S[i] >= Finish){
            printf("A%d ", A[i] + 1);
            Finish = F[i];
        }
    }
    printf("\n");
}

int main() {
    int num;

    printf("Enter Number of Activities: ");
    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        A[i] = i;

        printf("For A%d\n", A[i] + 1);

        printf("Enter Start Time: ");
        scanf("%d", &S[i]);

        printf("Enter Finish Time: ");
        scanf("%d", &F[i]);

        printf("\n");
    }

    bubble(num);
    Act_sel(num);

    return 0;
}
