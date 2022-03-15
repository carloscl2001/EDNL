#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"


//=>jercicio 1
template <typename T>
int nNodosVerdes3Nietos(Abin<T> A)
{
    return nNodosVerdes3Nietos_Rec(A.raiz(), A);
}

template <typename T>
int nNodosVerdes3Nietos_Rec(typename Abin<T>::nodo n, Abin<T>& A)
{

    if(n = Abin<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        if( funcionAux == true)
        {
            return 1 +  nNodosVerdes3Nietos_Rec(A.hijoIzqdo(n,A)) + nNodosVerdes3Nietos_Rec(A.hijoDrcho(n,A));
        }
        else
        {
            return nNodosVerdes3Nietos_Rec(A.hijoIzqdo(n,A)) + nNodosVerdes3Nietos_Rec(A.hijoDrcho(n,A));
        }
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
    cout<<"-------------------- NODO VERDES CON 3 NIETOS --------------------"<<endl;
    cout<<"\tNumero de nodos: "<<nNodosVerdes3Nietos(A)<<endl;
}