#include<stdio.h>
#include<stdlib.h>
#include".\Elem\ElemInt.h"
#include".\DicBin\DicBin.h"
#include".\AVLFunctions.h"

void dfsInOrder(DicBin a){
    if(esvacioAB(a))
        return;
    dfsInOrder(izqAB(a));
    ImpElem(raiz(a));
    dfsInOrder(derAB(a));
}

int main(){
    DicBin a = vacioAB();
    a = InsOrd(200,InsOrd(100,InsOrd(50,InsOrd(15,InsOrd(150,InsOrd(300,InsOrd(400,InsOrd(500,a))))))));
    a= hacerAVL(a);
    puts("");
    dfsInOrder(a);
    puts("Impresion de los niveles del arbol");
    printf("\n%d\n",raiz(a));
    printf("%d ",raiz(izqAB(a)));
    printf(" %d\n",raiz(derAB(a)));
    printf("%d ",raiz(izqAB(izqAB(a))));
    printf(" %d ",raiz(derAB(izqAB(a))));
    printf(" %d ",raiz(izqAB(derAB(a))));
    printf(" %d\n",raiz(derAB(derAB(a))));
    printf("%d\n",raiz(izqAB(izqAB(derAB(a)))));
    puts("");
    printf("MaxIzq: %d\n", maxIzq(izqAB(a)));
    printf("MinDer: %d\n", minDer(derAB(a)));
    a =eliminaRaiz(a);
    puts("");
    printf("NuevaRaiz: %d\n", raiz(a));
    dfsInOrder(a);
    puts("");
    puts("Eliminar 300");
    a = eliminaElemento(a, 300);
    dfsInOrder(a);
    puts("");
    return 0;
}