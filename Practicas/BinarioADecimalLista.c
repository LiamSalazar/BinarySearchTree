# include <stdio.h>
# include "Lista.h"

int contar(Lista decimal){
    if(decimal == NULL)
        return 0;
    return contar(resto(decimal)) + 1;
}

void volverDecimal(Lista decimal){
    int n = contar(decimal);
    printf("N: %d\n", n);
    int multiplicador = 1;
    int resultado = 0;
    for(int i = n-1; i >= 1; i--){
        multiplicador *= 2;
    }
    printf("Multiplicador: %d\n", multiplicador);
    while(decimal != NULL){
        resultado += cabeza(decimal) * multiplicador;
        
        multiplicador /= 2;
        decimal = resto(decimal);
    }
    printf("La conversión a decimal de la lista es: %d\n", resultado);
}

int main(){
    Lista decimal = vacia();
    decimal = cons(1, decimal);
    decimal = cons(0, decimal);
    decimal = cons(1, decimal);
    decimal = cons(0, decimal);
    decimal = cons(1, decimal);
    volverDecimal(decimal);
    return 0;
}