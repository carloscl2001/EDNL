
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"


template <typename T>
void podaAbin_Rec(typename Abin<T>::nodo n, Abin<T>& A,const typename Abin<T>::nodo ori){

    if(A.hijoDrcho(n) != Abin<T>::NODO_NULO){
        podaAbin_Rec(A.hijoDrcho(n),A,ori);
    }
    if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO){
        podaAbin_Rec(A.hijoIzqdo(n),A,ori);
    }
    if( n != ori)
    {
        if( n == (A.hijoIzqdo(A.padre(n)))){
        A.eliminarHijoIzqdo(A.padre(n));
        }
        else{
            A.eliminarHijoDrcho(A.padre(n));
        }
    }
}

template <typename T>
Abin<T>& podaAbin(typename Abin<T>::nodo n, Abin<T>& A){
    if(!A.arbolVacio()){
        podaAbin_Rec(n,A,n);
        return A;
    }
}

template <typename T>
bool comprobarDescendientes(typename Abin<T>::nodo n, T nElto, Abin<T>& A){
    if(n != Abin<T>::NODO_NULO){
        if(nElto <= A.elemento(n)){
            return true && comprobarDescendientes(A.hijoDrcho(n), nElto, A) && comprobarDescendientes(A.hijoIzqdo(n), nElto, A);
        }
        else{
            return false;
        }
    }
}


template <typename T>
bool comprobarAscendientes(typename Abin<T>::nodo n, T nElto, Abin<T>& A){
    if(n != A.raiz() && A.padre(n) != Abin<T>::NODO_NULO){
        cout<<"ascendientesde "<<
        if(nElto >= A.elemento(n)){
            return true && comprobarAscendientes(A.padre(n), nElto, A);
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}


template <typename T>
void transformarAbin_Rec(typename Abin<T>::nodo n, Abin<T>& A){
    cout<<"hola"<<endl;
    if(n != Abin<T>::NODO_NULO){
        cout<<"feo"<<endl;
        
        if(comprobarAscendientes(n, A.elemento(n), A) && comprobarDescendientes(n, A.elemento(n), A)){
            cout<<"vamos a podar"<<endl ;
            podaAbin(n, A);
        }
        cout<<"NO PODAMOS";
        if(A.hijoDrcho(n) != Abin<T>::NODO_NULO)
            cout<<"recursivaIZQDO";
            transformarAbin_Rec(A.hijoDrcho(n), A);
        if(A.hijoDrcho(n) != Abin<T>::NODO_NULO)
            cout<<"recursivaDRCHO";
            transformarAbin_Rec(A.hijoIzqdo(n), A);
    } 
}



template <typename T>
void transformarAbin(Abin<T>& A){
    if(!A.arbolVacio()){
        transformarAbin_Rec(A.raiz(), A);
    }
}



using namespace std;
typedef int tElto;
const tElto fin = '#'; // Fin de lectura.
int main (){
    using namespace std;
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
    transformarAbin(A);
    imprimirAbin(A);

}