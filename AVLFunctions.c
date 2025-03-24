#include<stdio.h>
#include<stdlib.h>
#include".\Elem\ElemInt.h"
#include".\DicBin\DicBin.h"

int altura(DicBin a){
    if(a == NULL)
        return 0;
    else{
        int izquierda = altura(izqAB(a));
        int derecha = altura(derAB(a));
        return 1 + (izquierda > derecha ? izquierda : derecha);
    }
}

DicBin rotarDerecha(DicBin a){ 
    DicBin nuevo = izqAB(a); // Nueva raíz
    DicBin nuevoHijo = derAB(nuevo); // Guardo el derecho porque el nuevo derecho es raiz anterior
    return consAB(raiz(nuevo), izqAB(nuevo), consAB(raiz(a), nuevoHijo, derAB(a)));
}

DicBin rotarIzquierda(DicBin a){
    DicBin nuevo = derAB(a); // Nueva raíz
    DicBin nuevoHijo = izqAB(nuevo); // Guardo el izquierdo porque el nuevo izquierdo es raiz anterior
    return consAB(raiz(nuevo), consAB(raiz(a), izqAB(a), nuevoHijo), derAB(nuevo));
}

int factorBalanceo(DicBin a){
    return altura(izqAB(a)) - altura(derAB(a));
}

DicBin balancear(DicBin a){
    if(esvacioAB(a)) return vacioAB();
    DicBin izq = balancear(izqAB(a)); // Balanceo arboles izquierdos
    DicBin der = balancear(derAB(a)); // Balanceo arboles derechos
    DicBin nuevo = consAB(raiz(a), izq, der); // Arbol con subs balanceados
    int fb = factorBalanceo(nuevo);
    if(fb > 1){ // Mas a la izquierda
        if(factorBalanceo(izqAB(nuevo)) >= 0) // No zig zag porque más a la izquierda
            return rotarDerecha(nuevo);
        else if(factorBalanceo(izqAB(nuevo)) < 0) // Zig zag en izq porque más altura a la derecha
            return rotarDerecha(consAB(raiz(nuevo), rotarIzquierda(izqAB(nuevo)),derAB(nuevo))); // COnserva raíz y derecha 
    }
    else if(fb < -1){ // Mas a la derecha
        if(factorBalanceo(derAB(nuevo)) <= 0) // No hay zig zag porque balanceado o mas a la derecha
            return rotarIzquierda(nuevo);
        else if(factorBalanceo(derAB(nuevo)) > 0) // Zig zag en der porque mas altura a la izquierda
            return rotarIzquierda(consAB(raiz(nuevo), izqAB(nuevo), rotarDerecha(derAB(nuevo))));
    }
    return nuevo;
}

