# include ".\ArBin.h"
# include ".\ElemInt.h"

typedef ArBin Heap;

int numNodos(Heap h) {
    if (esvacioAB(h)) return 0;
    return 1 + numNodos(izqAB(h)) + numNodos(derAB(h));
}

Heap intercambiaRaiz(Heap h, Heap hijoMayor) {
    if (h == hijoMayor)
        return consAB(raiz(h), izqAB(h), derAB(h));
    if (hijoMayor == izqAB(h)) {
        return consAB(raiz(hijoMayor), intercambiaRaiz(izqAB(h), hijoMayor), derAB(h));
    } else {
        return consAB(raiz(hijoMayor), izqAB(h), intercambiaRaiz(derAB(h), hijoMayor));
    }
}

Heap hazHeap(Heap h) {
    if (esvacioAB(h)) return h;

    Heap hi = izqAB(h);
    Heap hd = derAB(h);
    Heap mayor = h;

    if (!esvacioAB(hi) && raiz(hi) > raiz(mayor))
        mayor = hi;
    if (!esvacioAB(hd) && raiz(hd) > raiz(mayor))
        mayor = hd;

    if (mayor != h) {
        h = intercambiaRaiz(h, mayor);
        h = consAB(raiz(h), hazHeap(izqAB(h)), hazHeap(derAB(h)));
    }

    return h;
}

Heap consHeap(Heap h, Elem e) {
    if (esvacioAB(h))
        return consAB(e, vacioAB(), vacioAB());

    int nIzq = numNodos(izqAB(h));
    int nDer = numNodos(derAB(h));

    Heap nuevo;
    if (nIzq <= nDer) {
        nuevo = consAB(raiz(h), consHeap(izqAB(h), e), derAB(h));
    } else {
        nuevo = consAB(raiz(h), izqAB(h), consHeap(derAB(h), e));
    }

    return hazHeap(nuevo);
}
