#pragma once
#include"..\ArBin\ArBin.h"
typedef ArBin DicBin;

DicBin InsOrd(Elem e, DicBin a){
     if(esvacioAB(a))
        return consAB(e,vacioAB(),vacioAB());
     else if(EsMenor(e,raiz(a)))
              return   consAB(raiz(a),InsOrd(e,izqAB(a)),derAB(a));
          else
              return consAB(raiz(a),izqAB(a),InsOrd(e,derAB(a)));
}
