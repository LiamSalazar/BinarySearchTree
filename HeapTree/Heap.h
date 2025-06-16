# include ".\ArBin.h"
# include ".\ElemInt.h"

typedef ArBin Heap;

Heap HazHeap(Elem e, Heap i, Heap d){
    if(esvacioAB(i))  // La precondición implica que EsVacio(d)=Cierto
        return consAB(e,i,d);
    else if(esvacioAB(d))
            if(EsMayor_o_Igual(e,raiz(i)))
                return consAB(e,i,d);
            else
                return consAB(raiz(i),consAB(e,vacioAB(),vacioAB()),d);
        else if((EsMayor_o_Igual(e,raiz(i)))&&(EsMayor_o_Igual(e,raiz(d))))
                return consAB(e,i,d);
            else if(EsMayor_o_Igual(raiz(i),raiz(d)))
                    return consAB(raiz(i),HazHeap(e,izqAB(i),derAB(i)),d);
                else
                    return consAB(raiz(d),i,HazHeap(e,izqAB(d),derAB(d)));
}

Heap consHeap(Heap a){
    if(esvacioAB(a))
        return a;
    else
        return HazHeap(raiz(a),consHeap(izqAB(a)),consHeap(derAB(a)));
}
