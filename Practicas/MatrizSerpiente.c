#include <stdio.h>
#define N 4

int main() {
    int matriz[N][N];
    int top = 0;
    int bottom = N - 1;
    int left = 0;
    int right = N - 1;
    int count = 1;

    while (count <= N * N) {
        for (int i = left; i <= right && count <= N * N; i++)
            matriz[top][i] = count++;
        top++;

        for (int i = top; i <= bottom && count <= N * N; i++)
            matriz[i][right] = count++;
        right--;

        for (int i = right; i >= left && count <= N * N; i--)
            matriz[bottom][i] = count++;
        bottom--;

        for (int i = bottom; i >= top && count <= N * N; i--)
            matriz[i][left] = count++;
        left++;
    }

    // Imprimir la matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d\t ", matriz[i][j]);
        printf("\n");
    }

    return 0;
}
