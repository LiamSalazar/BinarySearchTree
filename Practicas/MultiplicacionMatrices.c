# include <stdio.h>
# define m 3
# define n 4
# define q 5

// (m x n) x (n x q) = mxq

int main(){
    int A[m][n] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };

    int B[n][q] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9,10},
        {11,12,13,14,15},
        {16,17,18,19,20}
    };
    int C[m][q];
    //Rellenar matriz resultado
    for(int i = 0; i < m; i++){
        for(int j = 0; j < q; j++){
            C[i][j] = 0;
        }
    }

    //Multiplicación de matrices
    for(int i = 0; i < m; i++){
        for(int j = 0; j < q; j++){
            for(int k = 0; k < n; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    //Imprimir resultado
    for(int i = 0; i < m; i++){
        for(int j = 0; j < q; j++){
            printf("%d\t", C[i][j]);
        }
        puts("");
    }

    return 0;
}