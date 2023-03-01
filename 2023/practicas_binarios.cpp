#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"
using namespace std;

//=>ejercicio1 => Numero de nodos
template <typename T>
int nNodos(const Abin<T>& A){
    if(A.arbolVacio())
        return 0;
    else
        return numNodos(A.raiz(), A);
}

template <typename T>
int numNodos(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + numNodos(A.hijoIzqdo(n),A) + numNodos(A.hijoDrcho(n),A);
}


//=>ejercicio2 => Altura de un arbol binario
template <typename T>
int alturaAbin(const Abin<T>& A){
    if(A.arbolVacio())
        return 0;
    else
        return alturaAbinRec(A.raiz(), A);
}

template <typename T>
int alturaAbinRec(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + max(alturaAbinRec(A.hijoIzqdo(n),A),alturaAbinRec(A.hijoDrcho(n),A));

}

//=>ejercicio3 => Profundidad del nodo en el arbol
template <typename T>
int profundidadAbin(typename Abin<T>::nodo n, const Abin<T>& A){
    if(A.arbolVacio())
        return 0;
    else
        return profundidadAbinRec(n,A);
}

template <typename T>
int profundidadAbinRec(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == A.raiz())
        return 0;
    else
        return 1 + profundidadAbinRec(A.padre(n),A);
}





using namespace std;
typedef char tElto;
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
    cout<<"\tNumero de nodos: "<<nNodos(A)<<endl;
    cout<<"--------------------EJ2--------------------"<<endl;
    cout<<"\tAltura de arbol: "<<alturaAbin(A)<<endl;
    cout<<"--------------------EJ3--------------------"<<endl;
    cout<<"\tProfundiad del nodo: "<<profundidadAbin(A.hijoIzqdo(A.hijoIzqdo(A.raiz())),A)<<endl;
    // cout<<"--------------------EJ4--------------------"<<endl;
    // cout<<"\tAltura del nodo: "<<A.altura(A.raiz())<<endl;
    // cout<<"--------------------EJ6--------------------"<<endl;
    // cout<<"\tDesequilibrio del arbol: "<<desequilibrio(A)<<endl;
    // cout<<"--------------------EJ7--------------------"<<endl;
    // cout<<"\tEs un arbol pseudocompleto: "<<pseudoAbinA(A)<<endl;
    // cout<<"--------------------EJ8//solo cambia los nodos con 1 hijo--------------------"<<endl;
    // imprimirAbin(reflexAbin(A));
    // cout<<"--------------------EJ9--------------------"<<endl;

}