#include <stdio.h>
#define N 5

int main() {
    int matriz[N][N];
    int top = 0;
    int down = N - 1;
    int left = 0;
    int right = N - 1;
    int num = 1;

    while (num <= N * N) {
        for (int i = left; i <= right && num <= N * N; i++)
            matriz[top][i] = num++;
        top++;

        for (int i = top; i <= down && num <= N * N; i++)
            matriz[i][right] = num++;
        right--;

        for (int i = right; i >= left && num <= N * N; i--)
            matriz[down][i] = num++;
        down--;

        for (int i = down; i >= top && num <= N * N; i--)
            matriz[i][left] = num++;
        left++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d\t ", matriz[i][j]);
        printf("\n");
    }

    return 0;
}
