# include "Lista.h"
# include "ElemInt.h"

typedef Lista Conjunto;

Conjunto Vacio(){return vacia();}

int EsVacio(Conjunto s){return s == Vacio();}

int Contiene(Elem e, Conjunto s){
    if(SonIguales(e, cabeza(s)) || EsVacio(s))
        return e == cabeza(s);
    else
        Contiene(e, resto(s));
}

Conjunto Inserta(Elem e, Conjunto s){
    if(!Contiene(e,s)){
        return cons(e,s);
    }
    else return s;
}

Conjunto Elimina(Elem e, Conjunto  s){
    if(EsVacio(s))
        return s;
    else if(SonIguales(e, cabeza(s)))
        return cons(e, resto(s));
    else
        return cons(cabeza(s), Elimina(e, resto(s)));
}

Conjunto Union(Conjunto s1, Conjunto s2){
    if(EsVacio(s1))
        return s2;
    else
        return Inserta(cabeza(s1),Union(resto(s1),s2));
}

Conjunto Interseccion(Conjunto s1, Conjunto s2){
    if(EsVacio(s1) || EsVacio(s2))
        return s1;
    else{
        Conjunto intersecta = Vacio();
        while(!EsVacio(s1)){
            if(Contiene(cabeza(s1), s2)){
                Inserta(cabeza(s1),intersecta);
            }
            s1 = resto(s1);
        }
        return intersecta;
    }
}

Conjunto Diferencia(Conjunto s1, Conjunto s2){
    if(EsVacio(s2))
        return s1;
    else if(EsVacio(s1))
        return s2;
    else{
        Conjunto distintos = Vacio();
        while(!EsVacio(s1)){
            if(!Contiene(cabeza(s1), s2)){
                Inserta(cabeza(s1),distintos);
            }
            s1 = resto(s1);
        }
        return distintos;
    }
}

int Cardinalidad(Conjunto s1){
    int contador = 0;
    while(!EsVacio(s1)){
        contador++;
        s1 = resto(s1);
    }
    return contador;
}