#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct DatoPrioridad {
    int dato;
    int prioridad;
} *Elem;

int EsMayorPrioridad(Elem e1, Elem e2) {
    return e1->prioridad > e2->prioridad;
}

int EsMayor(Elem e1, Elem e2) {
    return e1->dato > e2->dato;
}

Elem crearDato(int dato, int prioridad) {
    Elem nuevo = (Elem)malloc(sizeof(struct DatoPrioridad));
    if (!nuevo) {
        printf("Error de memoria\n");
        exit(1);
    }
    nuevo->dato = dato;
    nuevo->prioridad = prioridad;
    return nuevo;
}

void ImpElem(Elem e) {
    printf("Dato: %d Prioridad: %d\n", e->dato, e->prioridad);
}

int SonIguales(Elem e1, Elem e2){
    return e1->dato == e2->dato;
}

int EsMoI(Elem e1, Elem e2){
    return e1->dato >= e2->dato;
}
