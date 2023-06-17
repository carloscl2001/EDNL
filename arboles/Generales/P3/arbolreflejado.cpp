#include <iostream>
#include <fstream>
#include "agenDinamica.h"
#include "agen_E-S.h"

template <typename T>
Agen<T>& reflejarAgen(const Agen<T>& A)
{
    Agen<T> B;
    if(!A.arbolVacio()){
        B.insertarRaiz(A.elemento(A.raiz()));
        reflejarAgenRec(A.raiz(), B.raiz(), A, B);
    }

    return B;
}

template <typename T>
void reflejarAgenRec(typename Agen<T>::nodo nA, typename Agen<T>::nodo nB, const Agen<T>& A, Agen<T>& B){
    
    if(nA != Agen<T>::NODO_NULO && nB != Agen<T>::NODO_NULO){
        
        typename Agen<T>::nodo hijoA = A.hijoIzqdo(nA);
        
        if(hijoA != Agen<T>::NODO_NULO) {
            
            B.insertarHijoIzqdo(nB, A.elemento(hijoA));
            typename Agen<T>::nodo hijoB = B.hijoIzqdo(nB);
            reflejarAgenRec(hijoA,hijoB,A,B);
            hijoA = A.hermDrcho(hijoA);
            
            while(hijoA != Agen<T>::NODO_NULO){
                B.insertarHijoIzqdo(nB, A.elemento(hijoA));
                reflejarAgenRec(hijoA,hijoB,A,B);

                 hijoA = A.hermDrcho(hijoA);
                 hijoB = B.hijoIzqdo(nB);
            }
        }  
    }
}


using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura
int main (){
    Agen<tElto> A, B;
    ifstream fe("agen.dat"); // Abrir fichero de entrada.
    rellenarAgen(fe, A); // Desde fichero.

    fe.close();
    B = reflejarAgen(A);
    cout<<B.arbolVacio();
    imprimirAgen(B); // En std::cout
} 