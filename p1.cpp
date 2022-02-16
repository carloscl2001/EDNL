#include <iostream>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"

//ejercicio 1
template <typename T>
int nNodos(Abin<T> arbol)
{
    return nNodos_Rec(arbol,arbol.raiz());
}
template <typename T>
int nNodos_Rec(Abin<T> arbol, typename  Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO)
    {
        return 0;
        //cout<<"elemento del ndodo"<<arbol.elemento(n)<<endl;
    }else{
        //cout<<"elemento del nodo"<<arbol.elemento(n)<<endl;
        return 1 + nNodos_Rec(arbol, arbol.hijoIzqdo(n)) + nNodos_Rec(arbol, arbol.hijoDrcho(n));
    }
}

//ejercicio2
template <typename T>
int altura(Abin<T> arbol)
{
    return nNodos_Rec(arbol,arbol.raiz());
}
template <typename T>
int alturaRec(Abin<T> arbol, typename  Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO)
    {
        return -1;
        cout<<"elemento del ndodo"<<arbol.elemento(n)<<endl;
    }else{
        cout<<"elemento del nodo"<<arbol.elemento(n)<<endl;
        return 1 + max(alturaRec(arbol, arbol.hijoIzqdo(n)), alturaRec(arbol, arbol.hijoDrcho(n)));
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
    cout<<"-------------------------------------"<<endl;
    cout<<"Numero de nodos: "<<nNodos(A)<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Altura de arbol: "<<altura(A)<<endl;
    //ordenador
    //final
}