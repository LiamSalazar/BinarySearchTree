#include <stdio.h>

#define MAX 10 


void obtenerSubmatriz(int origen[MAX][MAX], int destino[MAX][MAX], int n, int columnaExcluir) {
    for (int i = 1; i < n; i++) { 
        int colDestino = 0;
        for (int j = 0; j < n; j++) {
            if (j == columnaExcluir) continue;
            destino[i - 1][colDestino] = origen[i][j];
            colDestino++;
        }
    }
}

int calcularDeterminante(int matriz[MAX][MAX], int n) {
    if (n == 1) return matriz[0][0];

    if (n == 2)
        return matriz[0][0]*matriz[1][1] - matriz[0][1]*matriz[1][0];

    int submatriz[MAX][MAX];
    int determinante = 0;

    for (int i = 0; i < n; i++) {
        obtenerSubmatriz(matriz, submatriz, n, i);
        int signo = (i % 2 == 0) ? 1 : -1;
        determinante += signo * matriz[0][i] * calcularDeterminante(submatriz, n - 1);
    }

    return determinante;
}

int main() {
    int n = 3;
    int matriz[MAX][MAX] = {
        {6, 1, 1},
        {4, -2, 5},
        {2, 8, 7}
    };

    printf("Matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    int resultado = calcularDeterminante(matriz, n);
    printf("\nDeterminante: %d\n", resultado);

    return 0;
}
