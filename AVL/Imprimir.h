# include ".\AVL.h"

void imprimirInOrder(AVL a) {
    if (!esvacioAB(a)) {
        imprimirInOrder(izqAB(a));
        ImpElem(raiz(a));
        printf(" ");
        imprimirInOrder(derAB(a));
    }
}

void imprimirNivel(AVL a, int nivel) {
    if (a == NULL){
        return;
    } 
    if (nivel == 1) {
        ImpElem(raiz(a));
        printf(" ");
    } else {
        imprimirNivel(izqAB(a), nivel - 1);
        imprimirNivel(derAB(a), nivel - 1);
    }
}

void imprimirBFS(AVL a) {
    int h = altura(a);
    for (int i = 1; i <= h; i++) {
        imprimirNivel(a, i);
        printf("\n");
    }
}
