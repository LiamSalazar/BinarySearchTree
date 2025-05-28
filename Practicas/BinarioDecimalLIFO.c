#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Lista.h"
#include "UsaLista.h"

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
    while (binario != NULL){
        printf("%d", cabeza(binario));
        binario = resto(binario);
    }
    printf("\n");
}

void convertirDecimalAOctal(int n){
    Lista octal = vacia();
    while (n > 0){
        octal = cons(n % 8, octal);
        n /= 8;
    }
    printf("El número en octal es: ");
    while (octal != NULL){
        printf("%d", cabeza(octal));
        octal = resto(octal);
    }
    printf("\n");
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

void convertirHexadecimalADecimal(char* hex){
    int len = strlen(hex);
    int base = 1;
    int resultado = 0;
    for(int i = len - 1; i >= 0; i--){
        if(hex[i] >= '0' && hex[i] <= '9'){
            resultado += (hex[i] - '0') * base;
        } else if(hex[i] >= 'A' && hex[i] <= 'F'){
            resultado += (hex[i] - 'A' + 10) * base;
        } else if(hex[i] >= 'a' && hex[i] <= 'f'){
            resultado += (hex[i] - 'a' + 10) * base;
        }
        base *= 16;
    }
    printf("La conversión a decimal desde hexadecimal es: %d\n", resultado);
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Lista.h"
#include "UsaLista.h"

// Función para imprimir cualquier lista
void imprimirLista(Lista lista) {
    Lista inversa = vacia();
    while (lista != NULL) {
        inversa = cons(cabeza(lista), inversa);
        lista = resto(lista);
    }
    while (inversa != NULL) {
        printf("%d ", cabeza(inversa));
        inversa = resto(inversa);
    }
    printf("\n");
}

int main() {
    Lista binaria = vacia();
    printf("=== Conversión de binario a decimal ===\n");
    binaria = llenarLista(binaria);
    printf("Bits ingresados: ");
    imprimirLista(binaria);
    volverDecimal(binaria);

    printf("\n=== Conversión de decimal a binario y octal ===\n");
    int numero;
    printf("Ingrese un número decimal: ");
    scanf("%d", &numero);
    convertirDecimalABinario(numero);
    convertirDecimalAOctal(numero);

    printf("\n=== Conversión de octal a decimal ===\n");
    Lista octal = vacia();
    int digito;
    printf("Ingrese 3 dígitos octales:\n");
    for (int i = 0; i < 3; i++) {
        printf("Dígito %d (0-7): ", i + 1);
        scanf("%d", &digito);
        if (digito >= 0 && digito <= 7) {
            octal = cons(digito, octal);
        } else {
            printf("Valor inválido, debe ser entre 0 y 7.\n");
            i--; // repetir este índice
        }
    }
    printf("Octal ingresado: ");
    imprimirLista(octal);
    convertirOctalADecimal(octal);

    printf("\n=== Conversión de hexadecimal a decimal ===\n");
    char hex[10];
    printf("Ingrese un número hexadecimal (sin 0x): ");
    scanf("%s", hex);
    convertirHexadecimalADecimal(hex);

    return 0;
}
