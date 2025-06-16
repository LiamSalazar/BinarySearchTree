# include ".\ElemInt.h"
# include <stdlib.h>

typedef struct Nodo{
      struct Nodo *i;
      Elem r;
      struct Nodo *d;
}*ArBin;

ArBin vacioAB(){return NULL;}
ArBin consAB(Elem r, ArBin i, ArBin d){
     ArBin t=(ArBin)malloc(sizeof(struct Nodo));
     t->r=r;
     t->i=i;
     t->d=d;
     return t;
}
int esvacioAB(ArBin a){return a==vacioAB();}
Elem raiz(ArBin a){return a->r;}
ArBin izqAB(ArBin a){return a->i;}
ArBin derAB(ArBin a){return a->d;}
