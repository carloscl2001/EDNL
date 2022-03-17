#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"

bool rebelde(typename Abin<bool>::nodo n, const Abin<bool>& A)
{

}


int nNodosRebel(const Abin<bool>& A)
{
    return nNodosRebelRec(A.raiz(),A);
}


int nNodosRebelRec(typename Abin<bool>::nodo n, const Abin<bool>& A)
{
    if(n == Abin<bool>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        if(rebelde(n,A))
        {
            return 1 + nNodosRebelRec(A.hijoIzqdo(n),A) + nNodosRebelRec(A.hijoDrcho(n),A);
        }
        else
        {
            return 0 + nNodosRebelRec(A.hijoIzqdo(n),A) + nNodosRebelRec(A.hijoDrcho(n),A);
        }
    }
}

using namespace std;
typedef bool tElto;
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