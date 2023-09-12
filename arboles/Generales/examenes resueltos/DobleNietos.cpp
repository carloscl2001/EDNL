//Dime el numero de nodos que tiene el doble de nietos que de bisnietos
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "agenDinamica.h"
#include "abin_E-S.h"

/*
template <typename T>
int numNietos(typename Agen<T>::nodo n, const Agen<T>& A){
    int numeroNietos = 0;
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    typename Agen<T>::nodo nieto;
    while (hijo != NODO_NULO)
    {
        nieto = A.hijoIzqdo(hijo);
        while(nieto != NODO_NULO)
        {
            numeroNietos++;
            nieto = A.hermDrcho(nieto);
        }
        
    }
    return numeroNietos;
}

template <typename T>
int numBisnietos(typename Agen<T>::nodo n, const Agen<T>& A){
    int numeroBisNietos = 0;
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    while(hijo != NODO_NULO){
        numeroBisNietos += numNietos(hijo,A);
        hijo = A.hermDrcho(hijo,A);
    }
    return numeroBisNietos;
}

template <typename T>
bool condicion(typename Agen<T>::nodo n, const Agen<T>& A){
    int numeroNietos = numNietos(n,A);
    int numeroBisNietos = numBisNietos(n,A);
    if(numeroNietos == numeroBisNietos*2){
        return true;
    }else{
        return false;
    }
}

template <typename T>
int DobleNietosAgen(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == NODO_NULO){
        return 0;
    }else{
        int numero_total = 0;
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != NODO_NULO){
            if(condicion(n,A)){
                numero_total += 1 + DobleNietosAgen(hijo,A);
            }else{
                numero_total += DobleNietosAgen(hijo,A);
            }
            hijo = A.hermDrcho(hijo);
        }
        return numero_total;
    }
}
*/
template <typename T>
size_t nNietos(typename Agen<T>::nodo n, const Agen<T>& A){
    
}

template <typename T>
size_t nBisnietosNietos(typename Agen<T>::nodo n, const Agen<T>& A){
    
}


template <typename T>
size_t nNodosAgen(typename Agen<T>::nodo n, const Agen<T>& A){
    
}