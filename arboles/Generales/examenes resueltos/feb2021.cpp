#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"

/*Transformar un arbol binario de tipo genérico, eliminando los descendientes propios de 
todos aquellos nodos cuyo contenido sea, al mismo tiempo, mayor o igual
que el de sus ascendientes propios y menor o igual que el de sus decendientes propios.
*/
template <typename T>
void transformarAbin(Abin<T>& A){
    transformarAbinRec(A.raiz(),A);
}

template <typename T>
void transformarAbinRec(c){
    if(n != Abin<T>::NODO_NULO){
        if(comprobarAntecesores && comprobarSucesores){
            eliminarNodo(n,A);
        }else{
            transformarAbinRec(A.hijoIzqdo(n),A);
            transformarAbinRec(A.hijoDrcho(n),A);
        }
    }
}

template <typename T>
bool comprobarAntecesores(typename Abin<T>::nodo n, Abin<T>& A){
    if(n == A.raiz(n)){
        return true;
    }else{
        return(A.elemento(A.padre(n)) <= A.elemento(n))
    }
}

template <typename T>
bool comprobarSucesores(typename Abin<T>::nodo n, Abin<T>& A){
    if(A.elemento(A.hijoIzqdo(n)) >= A.elemento(n) && A.elemento(A.hijoDrcho(n)) >= A.elemento(n))
        return true;
    else
        return false;
}

template <typename T>
void eliminarNodo(typename Abin<T>::nodo n, Abin<T>& A){
    if(esHoja(A.hijoIzqdo(n),A)){
        A.eliminarHijoIzqdo(n);
    }else{
        eliminarNodo(A.hijoIzqdo(n),A);
    }

    if(esHoja(A.hijoDrcho(n),A)){
        A.eliminarHijoDrcho(n);
    }else{
        eliminarNodo(A.hijoDrho(n),A);
    }
}


template <typename T>
bool esHoja(typename Abin<T>::nodo n, Abin<T>& A){
    if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDcho(n) == Abin<T>::NODO_NULO)
        return true;
    else 
        return false;
};