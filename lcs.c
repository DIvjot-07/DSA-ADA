#include <stdio.h>
#include <string.h>
#define M 10

char X[] = "ABC";
char Y[] = "XYZ";

int max(int a,int b){
    return (a>b)?a:b;
}

int table[M][M];

int lcs(int i,int j){
    if(i==0 || j==0){
        return 0;
    }
    else{
        if(X[i-1]==Y[j-1]){
            if(table[i-1][j-1]!=-1){
                return (1 + table[i-1][j-1]);
            }
            else{
                table[i-1][j-1]=lcs(i-1,j-1);
                return (1 + table[i-1][j-1]);
            }
        }
        else{
            if(table[i-1][j]!=-1 && table[i][j-1]!=-1){
                return max(table[i-1][j],table[i][j-1]);
            }
            if(table[i-1][j]==-1){
                table[i-1][j]=lcs(i-1,j);
            }
            if(table[i][j-1]==-1){
                table[i][j-1]=lcs(i,j-1);
            }
            return max(table[i-1][j], table[i][j-1]);
        }
    }
}

int main(){
    int i=strlen(X);
    int j=strlen(Y);

    for (int k=0;k<M;k++)
        for (int l=0;l<M;l++)
            table[k][l] = -1;

    printf("Length of LCS is %d", lcs(i,j));
    return 0;
}
