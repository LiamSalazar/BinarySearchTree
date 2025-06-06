#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Lista.h"
#include "ElemInt.h"
#include "UsaLista.h"

void imprimirLista(Lista l) {
    while (!esvacia(l)) {
        printf("%d", cabeza(l));
        l = resto(l);
    }
    printf("\n");
}

int sizeList(Lista l) {
    int contador = 0;
    while (!esvacia(l)) {
        contador++;
        l = resto(l);
    }
    return contador;
}

Lista rellenarLista(Lista l, int n) {
    l = InvierteLista(l);
    for (int i = 0; i < n; i++)
        l = cons(0, l);
    return InvierteLista(l);
}

Lista sumarListas(Lista a, Lista b) {
    int acarreo = 0;
    int sizeA = sizeList(a);
    int sizeB = sizeList(b);
    Lista resultado = vacia();

    if (sizeA > sizeB)
        b = rellenarLista(b, sizeA - sizeB);
    else
        a = rellenarLista(a, sizeB - sizeA);

    while (!esvacia(a)) {
        int suma = cabeza(a) + cabeza(b) + acarreo;
        resultado = cons(suma % 10, resultado);
        acarreo = suma / 10;
        a = resto(a);
        b = resto(b);
    }
    if (acarreo > 0)
        resultado = cons(acarreo, resultado);

    return InvierteLista(resultado);
}

Lista ingresarNumero() {
    Lista l = vacia();
    char c;
    printf("Ingrese los dígitos del número uno por uno:\n");
    while (1) {
        c = getchar();
        if (c == '\n') break;
        if (isdigit(c)) {
            int digito = c - '0';
            l = cons(digito, l); 
        }
    }
    return l;
}

int main() {
    printf("Número 1:\n");
    Lista num1 = ingresarNumero();
    printf("Número 2:\n");
    Lista num2 = ingresarNumero();
    Lista suma = sumarListas(num1, num2);
    Lista sumaImpresion = InvierteLista(suma);
    printf("Resultado de la suma: ");
    imprimirLista(sumaImpresion);

    return 0;
}
