#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"

template <typename T>
int nNodosAnte(typename Abin<T>::nodo n,const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
    {
        return -1;
    }
    else
    {
        return 1 + nNodosAnte(A.padre(n),A);
    }
}

template <typename T>
int nNodosDesc(typename Abin<T>::nodo n,const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        return 1 + nNodosDesc(A.hijoIzqdo(n),A) + nNodosDesc(A.hijoDrcho(n),A);
    }

}


template <typename T>
int nNodosNostal(const Abin<T>& A)
{
    return nNodosNostal_Rec(A.raiz(),A);
}

template <typename T>
int nNodosNostal_Rec(typename Abin<T>::nodo n,const Abin<T>& A)
{
    if (n == Abin<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        if(nNodosAnte(n,A) > nNodosDesc(n,A))
        {
            return 1 + nNodosNostal_Rec(A.hijoIzqdo(n),A) + nNodosNostal_Rec(A.hijoDrcho(n),A);
        }
        else
        {
            return nNodosNostal_Rec(A.hijoIzqdo(n),A) + nNodosNostal_Rec(A.hijoDrcho(n),A);
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
    cout<<"\tNumero de nodos: "<<nNodosNostal(A)<<endl;
}