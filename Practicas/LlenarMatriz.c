# include <stdio.h>

void llenar_matriz(int a[][100], int r, int c);
void imprimir_matriz(int a[][100], int r, int c);
void imprimir_renglon(int array[], int n);
void burbuja(int a[], int n);

int main(){
    int a[100][100];
    int r;
    int c;
    puts("Ingrese r: ");
    scanf("%d", &r);
    puts("Ingrese c: ");
    scanf("%d", &c);
    llenar_matriz(a,r,c);
    imprimir_matriz(a,r,c);
    return 0;
}

void llenar_matriz(int a[][100], int r, int c){
    puts("Ingrese los valores");
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &a[i][j]);
        }
    }
}

void imprimir_matriz(int a[][100], int r, int c){
    puts("Impresión de la matriz: ");
    for(int i = 0; i < r; i++){
        imprimir_renglon(a[i], c);
        puts("");
    }
}

void burbuja(int a[], int n){
    int i, j, t;
    for(j = 0; j < n-1; j++){
        for(i = n-1; i > j; i--){
            if(a[i] < a[i-1]){
                t = a[i];
                a[i] = a[i-1];
                a[i-1] = t;
            }
        }
    }
}

void imprimir_renglon(int array[], int c){
    burbuja(array, c);
    for(int i = 0; i < c; i++){
        printf("%d\t", array[i]);
    }
}
