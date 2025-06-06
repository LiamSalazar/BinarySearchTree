# include <stdio.h>
# include "Conjuntos.h"

int main(){
    Conjunto c1 = Vacio();
    c1 = Inserta(1,Inserta(2,Inserta(3,c1)));
    puts("Conjunto 1:");
    ImpConjunto(c1);
    Conjunto c2 = Vacio();
    c2 = Inserta(3,Inserta(3,Inserta(4,c2)));
    puts("");
    puts("");
    puts("Conjunto 2:");
    ImpConjunto(c2);
    Conjunto c3 = Elimina(1,c1);
    puts("");
    puts("");
    puts("Conjunto 1 eliminando 1:");
    ImpConjunto(c3);
    Conjunto c4 = Union(c1,c2);
    puts("");
    puts("");
    puts("Conjunto Union:");
    ImpConjunto(c4);
    Conjunto c5 = Interseccion(c1,c2);
    puts("");
    puts("");
    puts("Conjunto Interseccion:");
    ImpConjunto(c5);
    Conjunto c6 = Diferencia(c1,c2);
    puts("");
    puts("");
    puts("Conjunto Diferencia:");
    ImpConjunto(c6);
    int cardinalidad = Cardinalidad(c1);
    puts("");
    puts("");
    printf("Cardinalidad del conjunto 1: %d\n", cardinalidad);

    return 0;
}