#include <iostream>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"

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
    }else{
        return 1 + nNodos_Rec(arbol, arbol.hijoIzqdo(n)) + nNodos_Rec(arbol, arbol.hijoDrcho(n));
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
    cout<<"Numero de nodos: "<<nNodos(A)<<endl;
    ///

}