#include <stdio.h>
#include <string.h>
#define N 50

char T[N],P[N];
int count=0;

void brute(){
    int m=strlen(T);
    int n=strlen(P);
    for(int i=0;i<m;i++){
        int j=0;
        if(P[0]==T[i]){
            for(j=0;j<n;j++){
                if(P[j]!=T[j+i]){
                    break;
                }
            }
        }
        if(j==n){
            printf("Pattern found at index %d \n",i);
            count++;
        }
    }
    if(count==0){
        printf("Pattern not found\n");
    }
}

int main(){
    printf("Enter String:");
    scanf("%s",T);
    printf("Enter Pattern:");
    scanf("%s",P);
    brute();
    return 0;
}
