#include <iostream>
#include <fstream>
#include "agenDinamica.h"
#include "agen_E-S.h"
using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura

int main (){
    Agen<tElto> A;
    ifstream fe("agen.dat"); // Abrir fichero de entrada.
    rellenarAgen(fe, A); // Desde fichero.

    fe.close();

    //int n = gradoAgen(A);
    //std::cout << n << std::endl;
    //std::cout << profundidadNodoAgen(A, A.hijoIzqdo(A.hijoIzqdo(A.raiz())));

    //podaAgen('g',A);
    
    imprimirAgen(A); // En std::cout
}