#include <iostream>
#include <fstream>
#include "agenDinamica.h"
#include "agen_E-S.h"
using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura

//=>ejercicio 3
template <typename T>
int desequilibrio(const Agen<T>& A)
{
    return desequilibrioIter(A.raiz(),A);
}

template <typename T>
int desequilibrioIter(typename Agen<T>::nodo n, const Agen<T>& A)
{
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else
    {
        if(A.hijoIzqdo(n) != Agen<T>::NODO_NULO)
        {
            int desequi;
            desequi = calcularDesequilibrio(A.hijoIzqdo(n),A);
            typename Agen<T>::nodo hijo;
            hijo = A.hijoIzqdo(n);
            while( hijo != Agen<T>::NODO_NULO)
            {
                desequi = std::max(desequi, calcularDesequilibrio(hijo,A));
                hijo = A.hermDrcho(n);          
            }
            return desequi;
        }
        else
        {
            return 0;
        }
    }
}

template <typename T>
int calcularDesequilibrio(typename Agen<T>::nodo n, const Agen<T>& A)
{
    
    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        int dif, altMax, altMin = 0;
        altMax = altura(A.hijoIzqdo(n),A);
        altMin = altura(A.hijoIzqdo(n),A);
        if(A.hermDrcho(A.hijoIzqdo(n)) != Agen<T>::NODO_NULO)
        {
            typename Agen<T>::nodo nodo;
            nodo = A.hermDrcho(A.hijoIzqdo(n));
            while(nodo != Agen<T>::NODO_NULO)
            {
                altMax = std::max(altMax, altura(nodo,A));
                altMin = std::min(altMin, altura(nodo,A));
                nodo = A.hermDrcho(nodo);  
            }
            dif = altMax - altMin;
            return dif;
        }
        else
        {
            dif = altMax - altMin;
            return dif;
        }
    }
}

template <typename T>
int altura(typename Agen<T>::nodo n, const Agen<T>& A)
{
    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        int alt = 0;
        typename Agen<T>::nodo nodo;
        nodo = A.hijoIzqdo(n);
        while(nodo != Agen<T>::NODO_NULO)
        {
            alt = std::max(alt, altura(nodo,A));
            nodo = A.hermDrcho(nodo);
        }
        return 1 + alt;
    }
}



//=>ejercicio 4
template <typename T>
void podaAgen(typename Agen<T>::nodo n, Agen<T>& A)
{
    if(n != Agen<T>::NODO_NULO)
    {
        if(n == A.raiz() && A.hijoIzqdo(n) == Agen<T>::NODO_NULO){
            A.eliminarRaiz();
        }
        else{
            typename Agen<T>::nodo hijo;
            hijo = A.hijoIzqdo(n);
            while (hijo != Agen<T>::NODO_NULO)
            {
               podaNodo(hijo, A);
               hijo = A.hermDrcho(hijo);
            }
        }
    }
}

template <typename T>
void podaNodo(typename Agen<T>::nodo n, Agen<T>& A)
{
    typename Agen<T>::nodo hijo;
    hijo = A.hijoIzqdo(n);
    while (hijo != Agen<T>::NODO_NULO)
    {
        if(A.hijoIzqdo(hijo) == Agen<T>::NODO_NULO)
        {
            A.eliminarHijoIzqdo(n);
        }
        else
        {
            podaNodo(A.hijoIzqdo(n),A);
        }
        hijo = A.hermDrcho(hijo);
    }
    //A.eliminarHijoIzqdo(A.padre(n));
    
}




int main (){
    Agen<tElto> A;
    ifstream fe("agen.dat"); // Abrir fichero de entrada.
    rellenarAgen(fe, A); // Desde fichero.

    fe.close();

    cout<<"----------------------"<<endl;
    imprimirAgen(A); // En std::cout
    cout<<"----------------------"<<endl;
    //cout<< calcularDesequilibrio(A.raiz(),A)<<endl;
    podaAgen(A.raiz(),A);
    imprimirAgen(A); // En std::cout

    
}