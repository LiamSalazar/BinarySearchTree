# include ".\HeapTree.h"

int altura(Heap a){
    if(a == NULL)
        return 0;
    else{
        int izquierda = altura(izqAB(a));
        int derecha = altura(derAB(a));
        return 1 + (izquierda > derecha ? izquierda : derecha);
    }
}

void imprimirInOrder(Heap a) {
    if (!esvacioAB(a)) {
        imprimirInOrder(izqAB(a));
        ImpElem(raiz(a));
        printf(" ");
        imprimirInOrder(derAB(a));
    }
}

void imprimirNivel(Heap a, int nivel) {
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

void imprimirBFS(Heap a) {
    int h = altura(a);
    for (int i = 1; i <= h; i++) {
        imprimirNivel(a, i);
        printf("\n");
    }
}
