//Dime el numero de nodos que tiene 3 nietos -> Agen
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "agenDinamica.h"
#include "abin_E-S.h"

template <typename T>
int TresNietosAgen(const Agen<T>& A){
    if(A.arbolVacio()) return 0;
    else return TresNietosAgen(A.raiz(),A);
}

template <typename T>
int TresNietosAgen(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == NODO_NULO){
        return 0;
    }else{
        int acumulado = 0;
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n)
        while(hijo != NODO_NULO){
            if(contarNietos(hijo,A) == 3){
                acumulados++; 
            }
            acumulados += TresNietosAgen(A.hijoIzqdo(n),A);
            hijo = A.hermanoDcho(n);
        }
        return acumulado + TresNietosAgen(A.hijoIzqdo(n),A);
    }
}


template <typename T>
int contarNietos(typename Agen<T>::nodo n, const Agen<T>& A){
    int numero_nietos = 0;
    typename Agen<T>::nodo nieto = A.hijoIzqdo(A.hijoIzqdo(n))
    while(nieto != NODO_NULO){
        numero_nietos++;
        nieto = A.hermanoDcho(nieto);
    }
    return numero_nietos
}