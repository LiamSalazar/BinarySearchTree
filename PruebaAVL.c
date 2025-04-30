#include<stdio.h>
#include<stdlib.h>
#include".\Elem\ElemInt.h"
#include".\DicBin\DicBin.h"
#include".\AVL\AVL.h"
#include".\AVL\Imprimir.h"

int main() {
    AVL arbol = vacioAB();

    // Crear árbol complejo con los valores propuestos
    int valores[] = {6, 3, 7, 2, 5, 4, 1};
    int n = sizeof(valores) / sizeof(valores[0]);

    // Insertar cada elemento al árbol AVL
    for (int i = 0; i < n; i++) {
        arbol = consAVL(valores[i], arbol);
    }

    // Imprimir el árbol usando InOrder (DFS)
    printf("Recorrido InOrder (DFS):\n");
    imprimirInOrder(arbol);
    printf("\n\n");

    // Imprimir el árbol usando BFS sin colas
    printf("Recorrido BFS:\n");
    imprimirBFS(arbol);
    printf("\n");

    // Eliminar un valor y volver a imprimir
    arbol = deConsAVL(arbol, 150);

    printf("InOrder después de eliminar 150:\n");
    imprimirInOrder(arbol);
    printf("\n");

    printf("BFS después de eliminar 150:\n");
    imprimirBFS(arbol);
    printf("\n");

    return 0;
}
