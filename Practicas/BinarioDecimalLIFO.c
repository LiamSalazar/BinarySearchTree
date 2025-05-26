#include <stdio.h>
#include "Lista.h"
#include "UsaLista.h"
// Hexadecimal a decimal
// Decimal a octal
// Binario a decimal
// Octal a decimal
// Decimal a Binario
Lista llenarLista(Lista lista){
    int c, valor;
    int i = 0;
    printf("Ingrese 8 bits\n");
    while(i < 8){
        c = getchar();
        if (c == '0' || c == '1') {
            valor = c - '0'; 
            lista = cons(valor, lista);
            i++;
        }
    }
    return lista;
}

void volverDecimal(Lista decimal){
    int multiplicador = 1;
    int resultado = 0;
    while(decimal != NULL){
        resultado += (multiplicador * cabeza(decimal));
        multiplicador *= 2;
        decimal = resto(decimal);
    }
    printf("La conversión a decimal de binario de la listaes: %d\n", resultado);
}

void convertirBinario(int n){
    int bin[8];
    int i = 0;
    while(1){
        bin[i] = n%2;
    }
}

int main(){
    Lista decimal = vacia();
    decimal = llenarLista(decimal);
    volverDecimal(decimal);
    return 0;
}
