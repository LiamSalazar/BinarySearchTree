# include <stdio.h>
# define n 4

void crearMatriz(int matriz[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matriz[i][j] = j+1;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d", matriz[i][j]);
        }
        puts("");
    }
}

int main(){
    int matriz[n][n];
    crearMatriz(matriz);
    return 0;
}