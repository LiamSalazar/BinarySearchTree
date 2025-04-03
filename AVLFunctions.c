#pragma once
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

int abs(int x){
    return (x >= 0)? x:-x; 
}

int esAVL(DicBin a){
    if (abs(factorBalanceo(a))>1)
        return 0;
    else return 1;
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

DicBin hacerAVL(DicBin a){
    while(!esAVL(a)){
        a = balancear(a);
    }
    return a;
}

int esHoja(DicBin e){
    if(izqAB(e) == NULL && derAB(e) == NULL) return 1;
    return 0;
}

Elem maxIzq(DicBin a){
    if(esHoja(a))
        return raiz(a);
    else if (esvacioAB(derAB(a)))
        return raiz(a);
    return maxIzq(derAB(a));
}

Elem minDer(DicBin a){
    if(esHoja(a))
        return raiz(a);
    else if(!esvacioAB(izqAB(a)))
        return minDer(izqAB(a));
}

DicBin eliminaMaximo(DicBin a){
    if(esvacioAB(derAB(a)))
        return NULL;
    return consAB(raiz(a),izqAB(a),eliminaMaximo(derAB(a)));
}

DicBin eliminaMinimo(DicBin a){
    if(esvacioAB(izqAB(a)))
        return NULL;
    return consAB(raiz(a), eliminaMinimo(izqAB(a)), derAB(a));
}

DicBin eliminaRaiz(DicBin a){
    if(esHoja(a))
        return vacioAB();
    else if(esvacioAB(izqAB(a)))
        return derAB(a);
    else if(esvacioAB(derAB(a)))
        return izqAB(a);    
    return consAB(maxIzq(izqAB(a)), eliminaMaximo(izqAB(a)),derAB(a));
}

DicBin eliminaElemento(DicBin a, Elem e){
    if(!esvacioAB(a))
        return vacioAB();
    else if(SonIguales(raiz(a), e))
        return eliminaRaiz(a);
    else if(EsMenor(raiz(a),e))
        return consAB(raiz(a), izqAB(a),eliminaElemento(derAB(a), e));
    return consAB(raiz(a), eliminaElemento(izqAB(a), e), derAB(a));
    
}
