#include<stdio.h>
#include<stdlib.h>
#include".\Elem\ElemInt.h"
#include".\DicBin\DicBin.h"
#include".\AVL\AVL.h"
#include".\AVL\Imprimir.h"

void probarCaso(int caso, int* valores, int n) {
    printf("\n--- Caso %d ---\n", caso);
    AVL a = vacioAB();
    for (int i = 0; i < n; i++) {
        a = consAVL(valores[i], a);
    }

    printf("Recorrido InOrder (DFS):\n");
    imprimirInOrder(a);
    printf("\n");

    printf("Recorrido BFS:\n");
    imprimirBFS(a);
    printf("\n");
}

int main() {
    int caso1[] = {30, 10, 20};                        // Rotación doble IZQ-DER
    int caso2[] = {10, 30, 20};                        // Rotación doble DER-IZQ
    int caso3[] = {50, 20, 60, 10, 40, 30};            // Rotación doble en 20
    int caso4[] = {10, 5, 60, 70, 40, 50};             // Rotación doble en 60
    int caso5[] = {500, 400, 300, 150, 15, 50, 100, 200}; // Árbol zig-zag

    probarCaso(1, caso1, sizeof(caso1)/sizeof(caso1[0]));
    probarCaso(2, caso2, sizeof(caso2)/sizeof(caso2[0]));
    probarCaso(3, caso3, sizeof(caso3)/sizeof(caso3[0]));
    probarCaso(4, caso4, sizeof(caso4)/sizeof(caso4[0]));
    probarCaso(5, caso5, sizeof(caso5)/sizeof(caso5[0]));

    return 0;
}