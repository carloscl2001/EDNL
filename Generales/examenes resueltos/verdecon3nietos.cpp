#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"


//=>jercicio 1

template <typename T>
bool nodoVerde(typename Abin<T>::nodo n,Abin<T>& A)
{
    if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO  && A.hijoDrcho(n) != Abin<T>::NODO_NULO)
    {
        typename Abin<T>::nodo nh1 = A.hijoIzqdo(A.hijoIzqdo(n));
        typename Abin<T>::nodo nh2 = A.hijoIzqdo(A.hijoDrcho(n));
        typename Abin<T>::nodo nd1 = A.hijoDrcho(A.hijoIzqdo(n));
        typename Abin<T>::nodo nd2 = A.hijoDrcho(A.hijoDrcho(n));


        if((nh1 != Abin<T>::NODO_NULO && nh2 != Abin<T>::NODO_NULO && nd1 != Abin<T>::NODO_NULO && nd2 == Abin<T>::NODO_NULO ) ||
        (nh1 != Abin<T>::NODO_NULO && nh2 != Abin<T>::NODO_NULO && nd1 == Abin<T>::NODO_NULO) && nd2 != Abin<T>::NODO_NULO|| 
        (nh1 != Abin<T>::NODO_NULO && nh2 == Abin<T>::NODO_NULO && nd1 != Abin<T>::NODO_NULO) && nd2 != Abin<T>::NODO_NULO  || 
        (nh1 == Abin<T>::NODO_NULO && nh2 != Abin<T>::NODO_NULO && nd1 != Abin<T>::NODO_NULO) && nd2 != Abin<T>::NODO_NULO)
            { return true;}
            else
            {
                return false;
            }
    }
    else{return false;}
}


template <typename T>
int nNodosVerdesNietos(Abin<T>& A)
{
    return nNodosVerdesNietos_Rec(A.raiz(), A);
}

template <typename T>
int nNodosVerdesNietos_Rec(typename Abin<T>::nodo n, Abin<T>& A)
{

    if(n == Abin<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {   
        
        if(nodoVerde(n,A) == true)
        {
            return 1 +  nNodosVerdesNietos_Rec(A.hijoIzqdo(n),A) + nNodosVerdesNietos_Rec(A.hijoDrcho(n),A);
        }
        else
        {
            return nNodosVerdesNietos_Rec(A.hijoIzqdo(n),A) + nNodosVerdesNietos_Rec(A.hijoDrcho(n),A);
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
    cout<<"-------------------- NODO VERDES CON 3 NIETOS --------------------"<<endl;
    cout<<"\tNumero de nodos: "<<nNodosVerdesNietos(A)<<endl;
}