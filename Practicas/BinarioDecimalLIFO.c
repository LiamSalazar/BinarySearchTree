#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Lista.h"
#include "UsaLista.h"

Lista llenarListaBinario(Lista lista){
    int c, valor;
    printf("Ingrese 8 números en binario (0-1):\n");
    int i = 0;
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

Lista llenarListaOctal(Lista lista) {
    int c, valor;
    printf("Ingrese 3 números en octales (0-7):\n");
    int i = 0;
    while (i < 3) {
        c = getchar();
        if (c >= '0' && c <= '7') {
            valor = c - '0';
            lista = cons(valor, lista);
            i++;
        }
    }
    return lista;
}

Lista llenarListaHexadecimal(Lista lista) {
    int c;
    printf("Ingrese 4 dígitos hexadecimales (0-9 o A-F):\n");
    int i = 0;
    while (i < 4) {
        c = getchar();
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F')) {
            lista = cons(c, lista);  
            i++;
        }
    }
    return lista;
}


void imprimirLista(Lista lista) {
    while (lista != NULL) {
        printf("%d", cabeza(lista));
        lista = resto(lista);
    }
    printf("\n");
}


void volverDecimal(Lista decimal){
    int multiplicador = 1;
    int resultado = 0;
    while(decimal != NULL){
        resultado += (multiplicador * cabeza(decimal));
        multiplicador *= 2;
        decimal = resto(decimal);
    }
    printf("La conversión a decimal de binario de la lista es: %d\n", resultado);
}

void convertirDecimalABinario(int n){
    Lista binario = vacia();
    int i = 0;
    while (n > 0 && i < 8){
        binario = cons(n % 2, binario);
        n /= 2;
        i++;
    }
    printf("El número en binario es: ");
    imprimirLista(binario);
}

void convertirDecimalAOctal(int n){
    Lista octal = vacia();
    while (n > 0){
        octal = cons(n % 8, octal);
        n /= 8;
    }
    printf("El número en octal es: ");
    imprimirLista(octal);
}

void convertirOctalADecimal(Lista octal){
    int resultado = 0;
    int potencia = 0;
    while (octal != NULL){
        resultado += cabeza(octal) * pow(8, potencia);
        potencia++;
        octal = resto(octal);
    }
    printf("La conversión a decimal desde octal es: %d\n", resultado);
}

void convertirHexADecimal(Lista hexadecimal) {
    int resultado = 0;
    int potencia = 0;
    while (hexadecimal != NULL) {
        char c = (char)cabeza(hexadecimal);
        int valor;
        if (c >= '0' && c <= '9') {
            valor = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            valor = c - 'A' + 10;
        } else {
            valor = 0; 
        }
        resultado += valor * pow(16, potencia);
        potencia++;
        hexadecimal = resto(hexadecimal);
    }

    printf("La conversión a decimal de hexadecimaladecimal es: %d\n", resultado);
}


int main() {
    Lista binaria = vacia();
    printf("Conversión de binario a decimal: \n");
    binaria = llenarListaBinario(binaria);
    volverDecimal(binaria);

    printf("\nConversión de decimal a binario y octal: \n");
    int numero = 0;
    printf("Ingrese un número decimal: ");
    scanf("%d", &numero);
    convertirDecimalABinario(numero);
    convertirDecimalAOctal(numero);

    printf("\nConversión de octal a decimal: \n");
    Lista octal = vacia();
    octal = llenarListaOctal(octal);
    convertirOctalADecimal(octal);

    printf("\nConversión de hexadecimal a decimal: \n");
    Lista hexadecimal = vacia();
    hexadecimal = llenarListaHexadecimal(hexadecimal);
    convertirHexADecimal(hexadecimal);

    return 0;
}
