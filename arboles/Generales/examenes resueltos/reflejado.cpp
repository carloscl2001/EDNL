#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"

//Dado un árbol binario de un tipo genérico T calcular el número de nodos que siendo hermanos entre
//sí tienen misma raíz y sus subárboles son reflejados (respecto a sus elementos)

template <typename T>
int nNodosReflejados(const Abin<T>& A){
    return nNodosReflejadosRec(A.raiz(), A);
}

template <typename T>
int nNodosReflejadosRec(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n != typename Abin<T>::NODO_NULO){
        if(n == A.raiz()){
            return 0 + nNodosReflejadosRec(A.hijoIzqdo(n),A) + nNodosReflejadosRec(A.hijoDrcho(n),A);
        }
    }
}