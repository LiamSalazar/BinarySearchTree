#include"ElemInt.h"
#include"Lista.h"
# pragma once

int NumElems(Lista x){
    if(esvacia(x))
        return 0;
    else
        return 1+NumElems(resto(x));

}
int iNumElems(Lista x){
    int n=0;
    while(!esvacia(x)){
        n++;
        x=resto(x);
    }
    return n;
}

void ImpLista(Lista l){
    if(!esvacia(l)){
        ImpElem(cabeza(l));
        ImpLista(resto(l));
    }
}
int EstaEn(Elem e, Lista l){
    if(esvacia(l))
        return 0;
    else if(SonIguales(e,cabeza(l)))
            return 1;
        else
            return EstaEn(e,resto(l));
}
Lista PegaListas(Lista l1, Lista l2){
    if(esvacia(l1))
        return l2;
    else
        return cons(cabeza(l1),PegaListas(resto(l1),l2));
}

Lista InvierteLista(Lista l){
    if(esvacia(l))
        return l;
    else
        return PegaListas(InvierteLista(resto(l)),cons(cabeza(l),vacia()));
}
Lista InsOrd(Elem e, Lista l){
    if(esvacia(l))
        return cons(e,l);
    else if(EsMoI(e,cabeza(l)))
            return cons(e,l);
        else
            return cons(cabeza(l),InsOrd(e,resto(l)));
}
Lista OrdenaLista(Lista l){
    if(esvacia(l))
        return l;
    else
        return InsOrd(cabeza(l),OrdenaLista(resto(l)));
}
Lista eliminarElemento(Elem e, Lista l){
    if(esvacia(l))
        return l;
    else if(SonIguales(e, cabeza(l)))
        return eliminarElemento(e, resto(l));
    else
        return cons(cabeza(l), eliminarElemento(e, resto(l)));
}

Lista eliminarDuplicados(Lista l){
    if(esvacia(l))
        return l;
    else
        return cons(cabeza(l), eliminarDuplicados(eliminarElemento(cabeza(l), resto(l))));
}


int reaparece(Elem e, Lista l){
    if (esvacia(l)) return 0;
    if (SonIguales(e, cabeza(l))) return 1;
    return reaparece(e, resto(l));
}

Lista eliminarSiRepite(Lista l){
    if(esvacia(l))
        return l;
    else if (reaparece(cabeza(l), resto(l)))
        return eliminarSiRepite(eliminarElemento(cabeza(l),resto(l)));
    else
        return cons(cabeza(l), eliminarSiRepite(resto(l)));
}