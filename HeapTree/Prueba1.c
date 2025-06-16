#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include ".\HeapTree.h"  
#include ".\Imprimir.h"
#include ".\ElemInt.h"

int main() {
    srand(time(NULL)); 
    Heap h = vacioAB();

    printf("Insertando elementos aleatorios:\n");
    for (int i = 0; i < 5; i++) {
        int num = rand() % 100;  
        printf("%d ", num);
        h = consHeap(h, num);
    }

    printf("\n\nRecorrido inOrder del heap:\n");
    imprimirInOrder(h);

    printf("\n\nImpresión por niveles (BFS):\n");
    imprimirBFS(h);

    return 0;
}
