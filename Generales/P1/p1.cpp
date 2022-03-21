#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"


//=>jercicio 1
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


//=>ejercicio2
template <typename T>
int altura(const Abin<T>& A)
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


//=>ejercicio3
template <typename T>
int profNodoAbin(typename Abin<T>::nodo n, const Abin<T>& A){

    if(n == A.raiz()) return 0;
    /*if(n == Abin<T>::NODO_NULO)
    {
        return -1;
    }
    */
    else return 1 + profNodoAbin(A.padre(n), A);
}


//=>ejercicio6
template <typename T>
int desequilibrio(const Abin<T>& A){
    return desequilibrio_Rec(A.raiz(),A);
}

template <typename T>
int desequilibrio_Rec(typename Abin<T>::nodo n, const Abin<T>& A){
    if (n == Abin<T>::NODO_NULO) return 0;

    else{
        return std::max(abs(alturaRec(A.hijoIzqdo(n), A) - alturaRec(A.hijoDrcho(n), A)),std::max(desequilibrio_Rec(A.hijoIzqdo(n), A), desequilibrio_Rec(A.hijoDrcho(n), A))
        );
    }
}


//=>ejercicio7 
template <typename T>
bool pseudoAbinA(Abin<T>& A){

    return pseudoAbinARec(A.raiz(),A);
}

template <typename T>
bool pseudoAbinARec(typename Abin<T>::nodo n, Abin<T>& A)
{
   if(alturaRec(n,A) == 1)
   {
       return (nNodos_Rec(n,A) != 1);
   }
   else
   {
       if(alturaRec(A.hijoIzqdo(n),A) > alturaRec(A.hijoDrcho(n),A))
       {
           return pseudoAbinARec(A.hijoDrcho(n),A);
       }
        else
        {
            return (pseudoAbinARec(A.hijoIzqdo(n),A) && pseudoAbinARec(A.hijoDrcho(n),A));
        }
   }
}


//=>ejercicio8
template <typename T>
Abin<T> reflexAbin(const Abin<T>& A)
{
    Abin<T> C;
    if(A.arbolVacio() == true){
        return A;
    }
    else{
        C.insertarRaiz(A.elemento(A.raiz()));
        reflexAbin_Rec(A.raiz(),C.raiz(),A,C);
        return C;
    }
}

template <typename T>
void reflexAbin_Rec(typename Abin<T>::nodo n, typename Abin<T>::nodo m, const Abin<T>& A, Abin<T>& C)
{
    if(n != Abin<T>::NODO_NULO){
        if((A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO) || (A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO)){
            if( A.hijoIzqdo(n) != Abin<T>::NODO_NULO){
            C.insertarHijoDrcho(m,A.elemento(A.hijoIzqdo(n)));
            reflexAbin_Rec(A.hijoIzqdo(n),A.hijoDrcho(m),A,C);
            
            }
            if( A.hijoDrcho(n) != Abin<T>::NODO_NULO){
                C.insertarHijoIzqdo(m,A.elemento(A.hijoDrcho(n)));
                reflexAbin_Rec(A.hijoDrcho(n),A.hijoIzqdo(m),A,C);
            }
        }
        else{
            if( A.hijoIzqdo(n) != Abin<T>::NODO_NULO){
                C.insertarHijoIzqdo(m,A.elemento(A.hijoIzqdo(n)));
                reflexAbin_Rec(A.hijoIzqdo(n),A.hijoIzqdo(m),A,C);
            }
            if( A.hijoDrcho(n) != Abin<T>::NODO_NULO){
                C.insertarHijoDrcho(m,A.elemento(A.hijoDrcho(n)));
                reflexAbin_Rec(A.hijoDrcho(n),A.hijoDrcho(m),A,C);
            }
        }
    }
}

//=>ejercicio9
/*
struct{
    float operando;
    char operador;
}tdatos
*/
template <typename T>
float resultOperacion(const Abin<T>& E){
    return resultOperacionRec(E.raiz(),E);
}

template <typename T>
float resultOperacionRec(typename Abin<T>::nodo n, const Abin<T> E){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        if(E.hijoIzqdo(n) == Abin<T>::NODO_NULO && E.hijoDrcho(n) == Abin<T>::NODO_NULO){
            switch(E.elemento(E.padre(n)).operador)
            {
                case "+":   return(E.elemento(n).operando + resultOperacionRec(E.hijoDrcho(E.padre(n)),E); 
                case "-":   return(E.elemento(n).operando - resultOperacionRec(E.hijoDrcho(E.padre(n)),E);
                case "*":   return(E.elemento(n).operando * resultOperacionRec(E.hijoDrcho(E.padre(n)),E);
                case "/":   return(E.elemento(n).operando / resultOperacionRec(E.hijoDrcho(E.padre(n)),E);
            }
        }
        else{
            resultOperacionRec(E.hijoIzqdo(n),E);
            resultOperacionRec(E.hijoDrcho(n),E);
        }
    }
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
    cout<<"C--------------------EJ2--------------------"<<endl;
    cout<<"\tAltura de arbol: "<<altura(A)<<endl;
    cout<<"--------------------EJ3--------------------"<<endl;
    cout<<"\tProfundiad del nodo: "<<profNodoAbin(A.hijoIzqdo(A.hijoIzqdo(A.raiz())),A)<<endl;
    cout<<"--------------------EJ4--------------------"<<endl;
    cout<<"\tAltura del nodo: "<<A.altura(A.raiz())<<endl;
    cout<<"--------------------EJ6--------------------"<<endl;
    cout<<"\tDesequilibrio del arbol: "<<desequilibrio(A)<<endl;
    cout<<"--------------------EJ7--------------------"<<endl;
    cout<<"\tEs un arbol pseudocompleto: "<<pseudoAbinA(A)<<endl;
    cout<<"--------------------EJ8//solo cambia los nodos con 1 hijo--------------------"<<endl;
    imprimirAbin(reflexAbin(A));
    cout<<"--------------------EJ9--------------------"<<endl;

}