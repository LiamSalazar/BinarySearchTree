# include <stdio.h>

void llenar_matriz(int a[][100], int r, int c);
void imprimir_matriz(int a[][100], int r, int c);
void imprimir_matriz_ordenada_renglon(int a[][100], int r, int c);
void imprimir_renglon(int array[], int n);
void burbuja(int a[], int n);
void imprimir_matriz_ordenada_completa(int a[][100], int r, int c);
void ordenar_columna_en_matriz(int a[][100], int r, int c);
void imprimir_matriz_ordenada_columna(int a[][100], int r, int c);


int main(){
    int a[100][100];
    int r;
    int c;
    puts("Ingrese r: ");
    scanf("%d", &r);
    puts("Ingrese c: ");
    scanf("%d", &c);
    llenar_matriz(a,r,c);
    puts("Impresión de la matriz: ");
    imprimir_matriz(a,r,c);
    imprimir_matriz_ordenada_renglon(a,r,c);
    imprimir_matriz_ordenada_columna(a,r,c);
    imprimir_matriz_ordenada_completa(a,r,c);
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
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%d\t", a[i][j]);
        }
        puts("");
    }
}


void imprimir_matriz_ordenada_renglon(int a[][100], int r, int c){
    puts("Impresión de la matriz con renglones ordenados: ");
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

void imprimir_matriz_ordenada_completa(int a[][100], int r, int c){
    puts("Impresión ordenada de toda la matriz: ");
    int size = r * c;
    int array[10000];
    int contador = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            array[contador++] = a[i][j];
        }
    }
    burbuja(array, size);
    contador = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            a[i][j] = array[contador++];
        }
    }
    imprimir_matriz(a, r, c);
}

void ordenar_columna_en_matriz(int a[][100], int r, int col) {
    int temp[100];
    for(int i = 0; i < r; i++) {
        temp[i] = a[i][col];
    }
    burbuja(temp, r);
    for(int i = 0; i < r; i++) {
        a[i][col] = temp[i];
    }
}

void imprimir_matriz_ordenada_columna(int a[][100], int r, int c) {
    for(int j = 0; j < c; j++) {
        ordenar_columna_en_matriz(a, r, j);
    }
    puts("Impresión de la matriz con columnas ordenadas: ");
    imprimir_matriz(a, r, c);
}


// Caso de prueba:
// 9 1 5 7 2 8 3 6 4 0 10 11