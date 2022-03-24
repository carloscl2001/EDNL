#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"

template <typename T>
int prof(typename Abin<T>::nodo n,const Abin<T>& A){
    if(n == A.raiz()){
        return 0;
    }
    else{
        return 1 + prof(A.padre(n),A); 
    }
}


template <typename T>
int recorrer(typename Abin<T>::nodo n1, const Abin<T>& A, int p){
    if(n1 != Abin<T>::NODO_NULO){
        if(p == prof(n1,A)){
            return 1 + recorrer(A.hijoIzqdo(n1),A,p) + recorrer(A.hijoDrcho(n1),A,p);
        }
        else{
            return recorrer(A.hijoIzqdo(n1),A,p) + recorrer(A.hijoDrcho(n1),A,p);
        }
    }
    else{
        return 0;
    }
}

template <typename T>
int mismoNivel_Rec(typename Abin<T>::nodo n1, const Abin<T>& A){
    if(n1 == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        if(recorrer(A.raiz(),A,prof(n1,A)) > 2){
            return 1 + mismoNivel_Rec(A.hijoIzqdo(n1),A) + mismoNivel_Rec(A.hijoDrcho(n1),A);
        }
        else{
            return mismoNivel_Rec(A.hijoIzqdo(n1),A) + mismoNivel_Rec(A.hijoDrcho(n1),A);
        }
    }
}

template <typename T>
int mismoNivel(const Abin<T>& A){
    if(!A.arbolVacio()){
        return mismoNivel_Rec(A.raiz(),A);
    }
    else{
        return 0;
    }
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
    cout<<mismoNivel(A)<<endl;

}