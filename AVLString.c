#include<stdio.h>
#include<stdlib.h>
#include".\Elem\ElemStr.h"
#include".\DicBin\DicBin.h"
#include".\AVL\AVL.h"
#include".\AVL\Imprimir.h"

int main() {
    AVL a = vacioAB();

    // Insertamos palabras
    char* palabras[] = {"perro", "gato", "zorro", "conejo", "leon", "jirafa", "abeja"};
    // 6, 3, 7, 2, 5, 4, 1
    int n = sizeof(palabras) / sizeof(palabras[0]);

    for (int i = 0; i < n; i++) {
        a = consAVL(palabras[i], a);
    }

    printf("\nRecorrido InOrder (DFS):\n");
    imprimirInOrder(a);
    printf("\n\nRecorrido BFS (por niveles):\n");
    imprimirBFS(a);
    printf("\n");

    return 0;
}
