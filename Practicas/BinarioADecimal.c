# include <stdio.h>

void volverDecimal(int decimal[], int n){
    int multiplicador = 1;
    int resultado = 0;
    for(int i = n-1; i >= 0; i--){
        resultado += (decimal[i] * multiplicador);
        multiplicador *= 2;
    }
    printf("La conversión a decimal es: %d\n", resultado);
}

int main(){
    int decimal[8] = {1,0,1,0,1};
    volverDecimal(decimal, 5);
    return 0;
}