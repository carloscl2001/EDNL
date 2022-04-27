#include "agenDinamica.h"

template <typename T>
const Agen<T>& reflejarAgen(const Agen<T>& A)
{
    if(!A.arbolVacio())
    {
        reflejarAgenRec(A.raiz(),A);
    }
}

template <typename T>
void reflejarAgenRec(typename Agen<T>::nodo n, const Agen<T>& A)
{
    Agen<T> B;
    Agen<T>::nodo hijo;
    hijo = A.hijoIzqdo(n);
    while (hijo != Agen<T>::NODO_NULO)
    {
       insertarnodo(A.hijoIzqdo(n),B);
       hijo = A.hermDrcho(hijo); 
    }
    
}

template <typename T>
const Agen<T>& insertarnodo(typename Agen<T>::nodo n, Agen<T>& B)
{
    if(!B.raiz())
    {
        B.insertarRaiz(n);
    }
    else
    {
        Agen<T>::nodo hijo;
        insertarnodo(B.hijoIzqdo(n))
        hijo = B.hijoIzqdo();
    }
}