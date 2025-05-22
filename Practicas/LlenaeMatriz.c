# include <stdio.h>

void llenar_matriz(int a[][100], int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &a[i][j]);
        }
    }
}

void imprimir_matriz(int a[][100], int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%d", a[i][j]);
        }
        puts("");
    }
}

int main(){
    int a[100][100];
    llenar_matriz(a,3,3);
    imprimir_matriz(a,3,3);
    return 0;
}