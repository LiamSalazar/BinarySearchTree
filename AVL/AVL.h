#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"..\DicBin\DicBin.h"

typedef DicBin AVL;

int altura(AVL a){
    if(a == NULL)
        return 0;
    else{
        int izquierda = altura(izqAB(a));
        int derecha = altura(derAB(a));
        return 1 + (izquierda > derecha ? izquierda : derecha);
    }
}

AVL rotarDerecha(AVL a){ 
    AVL nuevo = izqAB(a); // Nueva raíz
    AVL nuevoHijo = derAB(nuevo); // Guardo el derecho porque el nuevo derecho es raiz anterior
    return consAB(raiz(nuevo), izqAB(nuevo), consAB(raiz(a), nuevoHijo, derAB(a)));
}

AVL rotarIzquierda(AVL a){
    AVL nuevo = derAB(a); // Nueva raíz
    AVL nuevoHijo = izqAB(nuevo); // Guardo el izquierdo porque el nuevo izquierdo es raiz anterior
    return consAB(raiz(nuevo), consAB(raiz(a), izqAB(a), nuevoHijo), derAB(nuevo));
}

int factorBalanceo(AVL a){
    return altura(izqAB(a)) - altura(derAB(a));
}

int abs(int x){
    return (x >= 0)? x:-x; 
}

int esAVL(AVL a){
    if (abs(factorBalanceo(a))>1)
        return 0;
    else return 1;
}

AVL balancear(AVL a){
    if(esvacioAB(a)) return vacioAB();
    AVL izq = balancear(izqAB(a)); // Balanceo arboles izquierdos
    AVL der = balancear(derAB(a)); // Balanceo arboles derechos
    AVL nuevo = consAB(raiz(a), izq, der); // Arbol con subs balanceados
    
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

AVL hacerAVL(AVL a){
    return balancear(a);  
}


int esHoja(AVL e){
    if(izqAB(e) == NULL && derAB(e) == NULL) return 1;
    return 0;
}

Elem maxIzq(AVL a){
    if(esHoja(a))
        return raiz(a);
    else if (esvacioAB(derAB(a)))
        return raiz(a);
    return maxIzq(derAB(a));
}

Elem minDer(AVL a){
    if(esHoja(a))
        return raiz(a);
    else if(!esvacioAB(izqAB(a)))
        return minDer(izqAB(a));
}

AVL eliminaMaximo(AVL a){
    if(esvacioAB(derAB(a)))
        return NULL;
    return consAB(raiz(a),izqAB(a),eliminaMaximo(derAB(a)));
}

AVL eliminaMinimo(AVL a){
    if(esvacioAB(izqAB(a)))
        return NULL;
    return consAB(raiz(a), eliminaMinimo(izqAB(a)), derAB(a));
}

AVL eliminaRaiz(AVL a){
    if(esHoja(a))
        return vacioAB();
    else if(esvacioAB(izqAB(a)))
        return derAB(a);
    else if(esvacioAB(derAB(a)))
        return izqAB(a);    
    return consAB(maxIzq(izqAB(a)), eliminaMaximo(izqAB(a)),derAB(a));
}

AVL deConsAVL(AVL a, Elem e){
    if(esvacioAB(a))
        return vacioAB();
    else if(SonIguales(raiz(a), e))
        return eliminaRaiz(a);
    else if(EsMenor(raiz(a), e))
        return consAB(raiz(a), izqAB(a), deConsAVL(derAB(a), e));
    return hacerAVL(consAB(raiz(a), deConsAVL(izqAB(a), e), derAB(a)));
}

AVL consAVL(Elem e, AVL a){
    a = InsOrd(e, a);
    return hacerAVL(a);
}

int perteneceAVL(Elem e, AVL a) {
    if (esvacioAB(a)) return 0;
    if (SonIguales(e, raiz(a))) return 1;
    if (EsMenor(e, raiz(a)))
        return perteneceAVL(e, izqAB(a));
    else
        return perteneceAVL(e, derAB(a));
}
