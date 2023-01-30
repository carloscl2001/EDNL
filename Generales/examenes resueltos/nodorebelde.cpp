#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"

template <typename T>
int rebelde2(typename Abin<T>::nodo n,const T elemento, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO){
        return 1;
    }
    else{
        if(elemento != A.elemento(n)){
            return 1 + rebelde2(A.padre(n),elemento,A);
        }
        else{
            return -1 + rebelde2(A.padre(n),elemento,A);
        }
    }
}

template <typename T>
int nNodosRebel(const Abin<T>& A){
    return nNodosRebel_Rec(A.raiz(),A);
}

template <typename T>
int nNodosRebel_Rec(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        if(rebelde2(n,A.elemento(n),A) > 0){
            return 1 + nNodosRebel_Rec(A.hijoIzqdo(n),A) + nNodosRebel_Rec(A.hijoDrcho(n),A);
        }
        else{
            return 0 + nNodosRebel_Rec(A.hijoIzqdo(n),A) + nNodosRebel_Rec(A.hijoDrcho(n),A);
        }
    }
}

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.
int main(){
    
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
    cout<<"-------------------- NODO NOSTALGICO --------------------"<<endl;
    cout<<"\tNumero de nodos: "<<nNodosRebel(A)<<endl;
}