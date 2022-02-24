#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"

//*ejercicio 1
template <typename T>
int nNodos(Abin<T> A)
{
    return nNodos_Rec(A.raiz(), A);
}

template <typename T>
int nNodos_Rec(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO)
    {
        return 0;
        //cout<<"elemento del ndodo"<<A.elemento(n)<<endl;
    }else{
        //cout<<"elemento del nodo"<<A.elemento(n)<<endl;
        return 1 + nNodos_Rec(A.hijoIzqdo(n), A) + nNodos_Rec(A.hijoDrcho(n), A);
    }
}

//*ejercicio2
template <typename T>
int altura(Abin<T>& A)
{
    return alturaRec(A.raiz(), A);
}
template <typename T>
int alturaRec(typename  Abin<T>::nodo n, const Abin<T>& A){
    using namespace std;
    if(n == Abin<T>::NODO_NULO) 
    {
        return -1;
    }
    else{
        return 1 + max(alturaRec(A.hijoIzqdo(n), A), alturaRec(A.hijoDrcho(n), A));
    }
}




//*ejercicio3
template <typename T>
int profNodoAbin(typename Abin<T>::nodo n, const Abin<T>& A){

    if(n == A.raiz())
    {
        return 0;
    }
    /*if(n == Abin<T>::NODO_NULO)
    {
        return -1;
    }
    */
    else{
        return 1 + profNodoAbin(A.padre(n), A);
    }
}

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.
int main (){
    
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
    cout<<"\tNumero de nodos: "<<nNodos(A)<<endl;
    cout<<"--------------------EJ2--------------------"<<endl;
    cout<<"\tAltura de arbol: "<<altura(A)<<endl;
    cout<<"--------------------EJ3--------------------"<<endl;
    cout<<"\tProfundiad del nodo: "<<profNodoAbin(A.hijoIzqdo(A.hijoIzqdo(A.raiz())),A)<<endl;
    cout<<"--------------------EJ4--------------------"<<endl;
    cout<<"\tAltura del nodo: "<<A.altura(A.raiz())<<endl;
}
