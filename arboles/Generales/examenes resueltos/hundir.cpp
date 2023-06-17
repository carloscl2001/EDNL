#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"
/*
template <typename T>
void hundirAbin(const Abin<T>& A){
    if(!A.arbolVacio()){
        return hundirAbin_Rec(A.raiz(),A);
    }
    else{
        return 0;
    }
}

template <typename T>
void hundirAbin_Rec(typename Abin<T>::nodo n, const Abin<T>&A){
    if(n != Abin<T>::NDODO_NULO){
        
    }
}
*/
template <typename T>
void hundimientoAbin(T elto, Abin<T> A){
    if(A.arbolVacio()){
        return;
    }
    else{
        typename Abin<T>::nodo nodoHundir  = buscarNodo(elto, A);
        return hundimientoAbin_Rec(nodoHundir, A);
    }
}

template <typename T>
typename Abin<T>::nodo buscarNodo(T elto, Abin<T> A){
    return buscarNodo_Rec(A.raiz(), elto, A);
}

template <typename T>
typename Abin<T>::nodo buscarNodo_Rec(const typename Abin<T>::nodo& n,const T& elto, const Abin<T>& A){
    cout << "Nodo Actual: " << A.elemento(n) <<endl;
    if(A.hijoDrcho(n) != Abin<T>::NODO_NULO)
        cout << "Hijo Drcho: " << A.elemento(A.hijoDrcho(n)) <<endl;
    if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO)
        cout << "Hijo Izqdo: " << A.elemento(A.hijoIzqdo(n)) <<endl;
    if(n != Abin<T>::NODO_NULO){
        if(A.elemento(n) == elto){
            return n;
        }
        else{
            if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO){
                buscarNodo_Rec(A.hijoIzqdo(n), elto,  A);
            }
            if(A.hijoDrcho(n) != Abin<T>::NODO_NULO){
                buscarNodo_Rec(A.hijoDrcho(n), elto, A);
            }
        }
    }
}

template<typename T>
void hundimientoAbin_Rec(typename Abin<T>::nodo n, Abin<T> A){
    if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO){
        std::swap(A.elemento(A.hijoIzqdo(n)), A.elemento(n));
        hundimientoAbin_Rec(A.hijoIzqdo(n), A);
    }
    else if(A.hijoDrcho(n) != Abin<T>::NODO_NULO){
        std::swap(A.elemento(A.hijoDrcho(n)), A.elemento(n));
        hundimientoAbin_Rec(A.hijoDrcho(n), A);
    }
    else{
        if(A.hijoDrcho(A.padre(n)) == n){
            A.eliminarHijoDrcho(A.padre(n));
        }
        else{
            A.eliminarHijoIzqdo(A.padre(n));
        }
    }
}


using namespace std;
typedef int tElto;
const tElto fin = '#'; // Fin de lectura.
int main (){
    Abin<tElto> A, B;
    cout << "\n*** Arbol A guardado en fichero abin.dat ***\n";
    cout << "\n*** Lectura de arbol binario B de abin.dat ***\n";
    ifstream fe("abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, B); // Desde fichero.
    fe.close();
    cout << "\n*** Mostrar arbol binario B ***\n";
    imprimirAbin(B); // En std::cout
    hundimientoAbin(6, B);
    imprimirAbin(B);
}