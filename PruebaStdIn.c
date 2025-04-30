#include<stdio.h>
#include<stdlib.h>
#include".\Elem\ElemStr.h"
#include".\DicBin\DicBin.h"
#include".\AVL\AVL.h"
#include".\AVL\Imprimir.h"

int main(){
    DicBin a = vacioAB();
    int i;
    for(i=0;i<5;i++){
        a = consAVL(LeeElem(5),a);
    }
    imprimirInOrder(a);
    puts("");
    imprimirBFS(a);
    return 0;
}