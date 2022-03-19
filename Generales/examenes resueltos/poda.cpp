#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"

template <typename T>
void poda_Rec(typename Abin<T>::nodo n, Abin<T>& A){

    if(A.hijoDrcho(n) != Abin<T>::NODO_NULO){
        poda(A.hijoDrcho(n),A);
    }
    if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO){
        poda(A.hijoIzqdo(n),A);
    }
    if( n == (A.hijoIzqdo(A.padre(n)))){
        A.eliminarHijoIzqdo(A.padre(n));
    }
    else{
        A.eliminarHijoDrcho(A.padre(n));
    }

}   
template <typename T>
Abin<T>& poda(typename Abin<T>::nodo n, Abin<T>& A){
    poda_Rec(n,A);
    return A;
}

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.
int main (){

    int a = 10;
    
    Abin<tElto> A, B;
    cout << "*** Lectura del arbol binario A ***\n";
    rellenarAbin(A, fin); // Desde std::cin
    ofstream fs("abin.dat"); // Abrir fichero de salida.
    imprimirAbin(fs, A, fin); // En fichero.
    fs.close();
    cout << "\n*** Arbol A guardado en fichero abin.dat ***\n";
    cout << "\n*** Lectura de arbol binario B de abin.dat ***\n";
    ifstream fe("abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, B); // Desde fichero.
    fe.close();
    cout << "\n*** Mostrar arbol binario B ***\n";
    imprimirAbin(B); // En std::cout
    cout<<"--------------------EJ1--------------------"<<endl;
    poda(A.hijoIzqdo(A.raiz()),A);
    imprimirAbin(A);
}