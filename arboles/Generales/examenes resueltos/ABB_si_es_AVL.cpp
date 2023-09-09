//Devolver si un arbol Abin es un arbol AVL

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"

template <typename T>
bool Abin_comprobar_AVL(const Abin<T>& A){
    if(A.arbolVacio()){
        return false;
    }else{
        return comprobarABB(A.raiz()) && comprobarAVL(A.raiz());
    }
}

//funcion que comprueba que sea un arbol binario de busqueda(ordenado)
template <typename T>
bool comprobarABB(typename Abin<T>::nodo n, const Abin<T>& A){
    return comprobacionSubArboles(n,A) && comprobarABB(A.hijoIzqdo(n),A) && comprobarABB(A.hijoDrcho(n),A);
}

//funcion que comprueba que sea un arbol equilibrado(equilibrio maximo del arbol -1 0 1)
template <typename T>
bool comprobarAVL(typename Abin<T>::nodo n, const Abin<T>& A){
    
}

template <typename T>
bool comprobarSubArboles(typename Abin<T>::nodo n, const Abin<T>& A){
    return comprobarSubArbolIzq(A.hijoIzqdo(n),A,A.elemento(n)) && comprobacionSubArbolDcho(A.hijoDrcho(n),A,A.elemento(n));
}

template <typename T>
bool comprobarSubArbolIzq(typename Abin<T>::nodo n, const Abin<T>& A){
    if(comprobarSubArbolIzqRec < A.elemento(n),A){
        return true;
    }else{
        return false;
    }
}

template <typename T>
int comprobarSubArbolIzqRec(typename Abin<T>::nodo n, const Abin<T>& A, T& maximo){
    if(n != NODO_NULO){
        return max(maximo, comprobacionSubArbolIzqdo(A.hijoIzqdo(n),A,maximo) && comprobarSubArbolIzqdo(A.hijoDrcho(n),A,amximo));
    }
}

template <typename T>
bool comprobacionSubArbolDcho(typename Abin<T>::nodo n, const Abin<T>& A, T& minimo){
    minimo = min(minimo, A.elemento(n));
    if(minimo > A.elemento(n)){
        return true && comprobacionSubArbolDcho(A.hijoIzqdo(n),A,minimo) && comprobarSubArbolDcho(A.hijoDrcho(n),A,minimo);
    }else{
        return false;
    }
}