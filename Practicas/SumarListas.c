# include <stdio.h>
# include "Lista.h"
# include "ElemInt.h"
# include "UsaLista.h"

int sizeList(Lista l){
    int contador = 0;
    while(!esvacia(l)){
        contador++;
        l = resto(l);
    }
    return contador;
}

Lista rellenarLista(Lista l, int n){
    for(int i = 0; i < n; i++){
        l = cons(0,l);
    }
    return l;
}

Lista sumarListas(Lista a, Lista b){
    int acarreo = 0;
    int sizeA = sizeList(a);
    int sizeB = sizeList(b);
    Lista resultado = vacia();
    if(sizeA > sizeB)
        b = rellenarLista(b, sizeA-sizeB);
    else
        a = rellenarLista(a, sizeB-sizeA);
    while(!esvacia(a)){
        int sumaT = cabeza(a)+cabeza(b)+acarreo;
        printf("\nSUMAElem: %d\n",sumaT);
        if(sumaT < 10){
            resultado = cons(sumaT, resultado);
            acarreo = 0;
        }else{
            int unidad = sumaT-10;
            resultado = cons(unidad, resultado);
            acarreo = 1;
        }
        a = resto(a);
        b = resto(b);
    }
    resultado = PegaListas(cons(acarreo,vacia()), resultado);
    return resultado;
}

int main(){
    Lista a = vacia();
    Lista b = vacia();
    a = cons(1, cons(2, cons(3, a)));
    b = cons(9, cons(9, b));
    Lista r = sumarListas(a,b);
    printf("\nNumero 1: \n");
    ImpLista(a);
    printf("\nNumero 2: \n");
    ImpLista(b);
    printf("\nSUMA: \n");
    ImpLista(r);
    return 0;
}