#include "arbol.h"
#include <cassert>
#include <iostream>
#include <fstream>

//------------------------------------------//
//                  ARBOLES                 //
//------------------------------------------//

//Implementa un subprograma que calcule la altura de un árbol binario.
template <typename T>
int alturaArbolBin(const Abin<T>& a){
    return alturaArbolBin_rec(A.raiz(), A);
}

template <typename T>
int alturaArbolBin_rec(typename Abin<T>::nodo n, const Abin<T> &A){
    if(n == Abin<T>::NODO_NULO){
        return -1;
    }else{
        return 1 + max(alturaArbolBin_rec(A.hijoIzqdo(n),A), alturaArbolBin_rec(A.hijoDcho(n),A));
    }
};

//Implementa un subprograma que, dados un árbol binario y un nodo del mismo, determine
// la profundidad de este nodo en dicho árbol.
template <typename T>
int profunididadNodo(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == A.raiz()){
        return 0;
    }else{
        return 1 + profunididadNodo(A.padre(n),A);
    }
};


//Implementa un subprograma que determine el nivel de desequilibrio de un árbol binario,
//definido como el máximo desequilibrio de todos sus nodos. El desequilibrio de un nodo se
//define como la diferencia entre las alturas de los subárboles del mismo.
template <typename T>
int desequilibrioAbin(const Abin<T>& A){
    return desequilibrioAbinRec(A.raiz(n),A);
}

template <typename T>
int desequilibrioAbinRec(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }else{
        int dese = abs(alturaArbolBin_rec(A.hijoIzqdo(n),A) - alturaArbolBin_rec(a.hijoDcho(n),A));
        return max(dese, desequilibrioAbinRec(a.hijoIzqdo(n),A), desequilibrioAbinRec(A.hijoDrcho(n),A));
    }
}

//Implementa un subprograma que determine si un árbol binario es o no pseudocompleto.
//En este problema entenderemos que un árbol es pseudocompleto, si en el penúltimo nivel
//del mismo cada uno de los nodos tiene dos hijos o ninguno.
template <typename T>
bool pseudocompleto(const Abin<T>& A){
    return pseudocompletoRec(A.raiz(n),alturaArbolBin_rec(A.raiz(),A), 0 , A);
}

template <typename T>
bool pseudocompletoRec(typename Abin<T>::nodo n, int altura, int profundidad, const Abin<T>& A){
    typedef Abin<T>::NODO_NULO NODO_NULO;
    if(n == Abin<T>::NODO_NULO){
        return true;
    }else{
        if(profundidad = altura - 1){
            if(A.hijoIzqdo(n) == NODO_NULO && A.hijoDrcho(n) == NODO_NULO)
                return true;
            else if(A.hijoIzqdo(n) != NODO_NULO && A.hijoDrcho(n) != NODO_NULO)
                return true;
            else
                return false;
        }else{
            return pseudocompletoRec(A.hijoIzqdo(n), altura, profundidad + 1, A) && pseudocompletoRec(A.hijoDrcho(n), altura, profundidad + 1, A)
        }
    }
}

//Dos �rboles binarios son similares cuando tienen id�ntica estructura de ramificaci�n,
//es decir, ambos son vac�os, o en caso contrario, tienen sub�rboles izquierdo y derecho
//similares. Implementa un subprograma que determine si dos �rboles binarios son
//similares.
template <typename T>
bool similaresAbin(const Abin<T>& A, const Abin<T>& B){
    return similaresAbinRec(A.raiz(n), B.raiz(n), A , B);
}

template <typename T>
bool similaresAbinRec(typename Abin<T>::nodo nA,typename Abin<T>::nodo nB, const Abin<T>& A, const Abin<T>& B){
    if(nA == Abin<T>::NODO_NULO && nB == Abin<T>::NODO_NULO){
        return true;
    }else{
        if(nA != Abin<T>::NODO_NULO && nB != Abin<T>::NODO_NULO)
            return similaresAbinRec(A.hijoIzqdo(nA),B.hijoIzqdo(nB),A,B) && similaresAbinRec(A.hijoDrcho(nA),B.hijoDrcho(nB),A,B);
        else   
            return false;       
    }
}

//Contar los nodos verdes que sean nostalgicos (mas antecesores que descendientes)
template <typename T>
int numNostalgiscos(const Abin<T>& A){
    return numNostalgiscosRec(A.raiz(n),A);
}

template <typename T>
int numNostalgiscosRec(typename Abin<T>::nodo n, const Abin<T>& A){
    
}
