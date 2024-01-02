#include "arbol.h"
#include "agenDinamica.h"
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------------//
//                  ARBOLES                 //
//------------------------------------------//

//Implementa un subprograma que calcule la altura de un árbol binario.
template <typename T>
int alturaArbolBin(const Abin<T>& a){
    return alturaArbolBin_rec(A.raiz(), A);
}

template <typename T>
int alturaArbolBin_rec(typename Abin<T>::nodo n, const Abin<T> &A){
    if(n == Abin<T>::NODO_NULO){
        return -1;
    }else{
        return 1 + max(alturaArbolBin_rec(A.hijoIzqdo(n),A), alturaArbolBin_rec(A.hijoDcho(n),A));
    }
};

//Implementa un subprograma que, dados un árbol binario y un nodo del mismo, determine
// la profundidad de este nodo en dicho árbol.
template <typename T>
int profunididadNodo(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == A.raiz()){
        return 0;
    }else{
        return 1 + profunididadNodo(A.padre(n),A);
    }
};


//Implementa un subprograma que determine el nivel de desequilibrio de un árbol binario,
//definido como el máximo desequilibrio de todos sus nodos. El desequilibrio de un nodo se
//define como la diferencia entre las alturas de los subárboles del mismo.
template <typename T>
int desequilibrioAbin(const Abin<T>& A){
    return desequilibrioAbinRec(A.raiz(n),A);
}

template <typename T>
int desequilibrioAbinRec(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }else{
        int dese = abs(alturaArbolBin_rec(A.hijoIzqdo(n),A) - alturaArbolBin_rec(a.hijoDcho(n),A));
        return max(dese, desequilibrioAbinRec(a.hijoIzqdo(n),A), desequilibrioAbinRec(A.hijoDrcho(n),A));
    }
}

//Implementa un subprograma que determine si un árbol binario es o no pseudocompleto.
//En este problema entenderemos que un árbol es pseudocompleto, si en el penúltimo nivel
//del mismo cada uno de los nodos tiene dos hijos o ninguno.
template <typename T>
bool pseudocompleto(const Abin<T>& A){
    return pseudocompletoRec(A.raiz(n),alturaArbolBin_rec(A.raiz(),A), 0 , A);
}

template <typename T>
bool pseudocompletoRec(typename Abin<T>::nodo n, int altura, int profundidad, const Abin<T>& A){
    typedef Abin<T>::NODO_NULO NODO_NULO;
    if(n == Abin<T>::NODO_NULO){
        return true;
    }else{
        if(profundidad = altura - 1){
            if(A.hijoIzqdo(n) == NODO_NULO && A.hijoDrcho(n) == NODO_NULO)
                return true;
            else if(A.hijoIzqdo(n) != NODO_NULO && A.hijoDrcho(n) != NODO_NULO)
                return true;
            else
                return false;
        }else{
            return pseudocompletoRec(A.hijoIzqdo(n), altura, profundidad + 1, A) && pseudocompletoRec(A.hijoDrcho(n), altura, profundidad + 1, A)
        }
    }
}

//Dos �rboles binarios son similares cuando tienen id�ntica estructura de ramificaci�n,
//es decir, ambos son vac�os, o en caso contrario, tienen sub�rboles izquierdo y derecho
//similares. Implementa un subprograma que determine si dos �rboles binarios son
//similares.
template <typename T>
bool similaresAbin(const Abin<T>& A, const Abin<T>& B){
    return similaresAbinRec(A.raiz(n), B.raiz(n), A , B);
}

template <typename T>
bool similaresAbinRec(typename Abin<T>::nodo nA,typename Abin<T>::nodo nB, const Abin<T>& A, const Abin<T>& B){
    if(nA == Abin<T>::NODO_NULO && nB == Abin<T>::NODO_NULO){
        return true;
    }else{
        if(nA != Abin<T>::NODO_NULO && nB != Abin<T>::NODO_NULO)
            return similaresAbinRec(A.hijoIzqdo(nA),B.hijoIzqdo(nB),A,B) && similaresAbinRec(A.hijoDrcho(nA),B.hijoDrcho(nB),A,B);
        else   
            return false;       
    }
}

//Contar los nodos verdes que sean nostalgicos (mas antecesores que descendientes)
template <typename T>
int numNostalgiscos(const Abin<T>& A){
    return numNostalgiscosRec(A.raiz(n),A);
}

template <typename T>
int numNostalgiscosRec(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }else{
        if(profunididadNodo(n,A) > decendientes(n,A))
            return 1 + numNostalgiscosRec(A.hijoIzqdo(n),A) + numNostalgiscosRec(A.hijoDrcho(n),A);
        else
            return numNostalgiscosRec(A.hijoIzqdo(n),A) + numNostalgiscosRec(A.hijoDrcho(n),A);
    }
}

template <typename T>
int descendientes(typename Abin<T>::nodo n, const Abin<T>& A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        return 1 + contar_descendientes(A.hijoIzqdo(n), A) + contar_descendientes(A.hijoDrcho(n), A);
    }
}


//Calcula el indice de prosperidad de una poblacion, calcula el porcentaje de nodos prosperos, el elemento del nodo nos indica la 
//riqueza, se considera que un nodo es prospero cuando su dinero es mayor que el de sus antecesores propios y su dinero es menor que sus 
//descendientes propios.
template <typename T>
float prosperidadAbin(const Abin<T>& A){
    return numNodosProsperos(A.raiz(n),A)/contarNodos(A) * 100;
}

template <typename T>
int numNodosProsperos(typename Abin<T>::nnodo n, Abin<T>& A){
    if(n == Abin<T>::NODO_NULO || n == A.raiz()){
        return 0;
    }else{
        if(A.elemento(A.padre(n)) < A.elemento(n) && A.elemento(n) < dinero_Hijos(n,A))
            return 1 + numNodosProsperos(A.hijoIzqdo(n),A) + numNodosProsperos(A.hijoDrcho(n),A);
        else
            return numNodosProsperos(A.hijoIzqdo(n),A) + numNodosProsperos(A.hijoDrcho(n),A);
    }
}

template <typename T>
int dinero_Hijos(typename Abin<T>::NODO n, const Abin<T> &A){
    if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        if(A.hijoDrcho(n) == Abin<T>::NODO_NULO){
            return A.elemento(A.hijoIzqdo(n));
        }
        else if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO){
            return A.elemento(A.hijoDrcho(n));
        }
        else{
            return A.elemento(A.hijoIzqdo(n)) +  A.elemento(A.hijoDrcho(n));
        }
    }
}


//Contar nodos verdes (aquellos que tienen 4 o mas descendientes)
template <typename T>
int contarVerdes(const Abin<T>& A){
    return contarVerdesRec(A.raiz(),A);
}

template <typename T>
int contarVerdesRec(typename Abin<T>::nodo n, Abin<T>& A){
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        if(numDescenientes(n,A) - 1 >= 4)
            return 1 + contarVerdesRec(A.hijoIzqdo(n),A) + contarVerdesRec(A.hijoDrcho(n),B);
        else
            return contarVerdesRec(A.hijoIzqdo(n),A) + contarVerdesRec(A.hijoDrcho(n),B);
}

template <typename T>
int numDescenientes(typename Abin<T>::nodo n, Abin<T>& A){
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else 
        return 1 + numDescenientes(A.hijoIzqdo(n),A) + numDescenientes(A.hijoDrcho(n,A));
}


//Contar los nodos que tengan 3 nietos
template <typename T>
int contarNietosRec(const Abin<T>& A){
    return contarNietosRec(A.raiz(),A);
}

template <typename T>
int contarNietosRec(typename Abin<T>::nodo n, Abin<T>& A){
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        if(TresNietos(n,A) == 3)
            return 1 + contarNietosRec(A.hijoIzqdo(n),A) + contarNietosRec(A.hijoDrcho(n),B);
        else
            return contarNietosRec(A.hijoIzqdo(n),A) + contarNietosRec(A.hijoDrcho(n),B);
}

template <typename T>
int TresNietos(typename Abin<T>::nodo n, Abin<T>& A){
    return contarHijos(A.hijoIzqdo(n),A) + contarHijos(A.hijoDrcho(n),A);
}

template <typename T>
int contarHijos(typename Abin<T>::nodo n, Abin<T>& A){
    if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO)
        return 2;
    else if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO)
        return 0;
    else 
        return 1;
}


//------------------------Generales----------------------------------------------------------------------------------------

//Implementa un subprograma que dado un árbol general nos calcule su grado (numero maximo de hijos que tiene un arbol)
template <typename T>
int grado(const Agen<T>& A){
    return gradoAgen(A.raiz(),A);
}
template <typename T>
int gradoAgen(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else{
        int gradoMax = 0;
        typename Agen<T>::nodo hijo;
        hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO){
            gradoMax = contarHijos(n,A);
            //gradoMax = contarHijos(A.hijoIzqdo(n),A);
            gradoMax = max(gradoMax, gradoAgen(A.hijoIzqdo(n),A), gradoAgen(A.hermDrcho(n),A));
            hijo = A.hermDrcho(hijo);
        }
    }
}

template <typename T>
int contarHijos(typename Agen<T>::nodo n, const Agen<T>& A){
    typename Agen<T>::nodo hijo;
    hijo = A.hijoIzqdo(n);
    if(hijo == Agen<T>::NODO_NULO){
        return 0;
    }else{
        int numHijos = 0;
        while(hijo != Agen<T>::NODO_NULO){
            numHijos++;
            hijo = A.hermDrcho(hijo);
        }
        return numHijos;
    }
}


template <typename T>
int contarHijosAle(typename Agen<T>::nodo n, const Agen<T>& A){
    if( n == Agen<T>::NODO_NULO)
        return 0;
    else{
        return 1 + contarHijosAle(A.hermDrcho(n),A);
    }
}


//Se define el desequilibrio de un árbol general como la máxima diferencia entre las alturas
//de los subárboles más bajo y más alto de cada nivel. Implementa un subprograma que calcule
//el grado de desequilibrio de un árbol general.
template <typename T>
int desequilibrioAgen(const Agen<T>& A){
    return desequilibrioAgenRec(A.raiz(),A);
}

template <typename T>
int desequilibrioAgenRec(typename Agen<T>::nodo n, const Agen<T>& A){
{
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else
    {
        unsigned desequilibrioMax = 0, alturaMinima = alturaMin(n, A), desNodo = std::fabs(alturaAgen(n, A) - alturaMinima );
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO)
        {
            desequilibrioMax = std::max(desNodo, desequilibrioRec(hijo, A));
            hijo = A.hermDrcho(hijo);
        }
        return desequilibrioMax;
    }
}

}

template <typename T>
int alturaAgen(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO)
        return -1;
    else{
        int altura = 0;
        typename Agen<T>::nodo hijo;
        hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO){
            altura = max(altura, alturaAgen(hijo,A));
            hijo = A.hermDrcho(n);
        }
        return 1 + altura;
    }   
}

template <typename T>
int alturaMin(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO)
        return -1;
    else{
        int altura = 0;
        typename Agen<T>::nodo hijo;
        hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO){
            altura = min(altura, alturaAgen(hijo,A));
            hijo = A.hermDrcho(n);
        }
        return 1 + altura;
    }   
}

