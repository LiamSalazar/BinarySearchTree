#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include".\Elem\ElemInt.h"
#include".\DicBin\DicBin.h"

void ImpInOrder(DicBin);

int main(){
    DicBin a=vacioAB();
    int i;
    srand(time(NULL));
    for(i=1;i<=10;i++)
         a=InsOrd(1+rand()%30,a);
    puts("Elementos del diccionario:");
    ImpInOrder(a);

    return 0;
}

void ImpInOrder(DicBin a){
    if(!esvacioAB(a)){
        ImpInOrder(izqAB(a));
        ImpElem(raiz(a));
        ImpInOrder(derAB(a));
    }
};
