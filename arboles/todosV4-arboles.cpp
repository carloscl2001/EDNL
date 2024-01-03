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


//Ejercicio 4: Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice
//la poda de A a partir de x. Se asume que no hay elementos repetidos en A.
template <typename T>
void podaAgen(Agen<T>& A, T x){
    podaAgenRec(A.raiz(),A, x);
}

template <typename T>
void podaAgenRec(typename Agen<T>::nodo n, Agen<T>& A, T x){
    if(n != Agen<T>::NODO_NULO){
        if(A.elemento(n) == x){
            eliminarSubarbol(n,A);
        }else{
            typename Agen<T>::nodo hijo;
            hijo = A.hijoIzqdo(n);
            while(hijo != Agen<T>::NODO_NULO){
                podaAgenRec(hijo,A);
                hijo = A.hermDrcho(hijo);
            }
        }
        
    }
}
//sin eliminar el nodo x
template <typename T>
void eliminarSubarbol(typename Agen<T>::nodo n, Agen<T>& A){
    if(n != Agen<T>::NODO_NULO){
        //nodo sea hoja
        if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO){
            A.eliminarHijoIzqdo(A.padre(n),A);
        }
        //no es hoja
        else{
            typename Agen<T>::nodo hijo;
            hijo = A.hijoIzqdo(n);
            while(hijo != Agen<T>::NODO_NULO){
                eliminarSubarbol(hijo,A);
                hijo = A.hermDrcho(hijo);
            }
        }
    }
}
 //eliminando el nodo x
template <typename T>
void eliminarSubarbol(typename Agen<T>::nodo n, Agen<T>& A, T x){
    if(n != Agen<T>::NODO_NULO){
        //nodo sea hoja
        if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO){
            A.eliminarHijoIzqdo(A.padre(n));
        }
        //no es hoja
        else{
            typename Agen<T>::nodo hijo;
            hijo = A.hijoIzqdo(n);
            while(hijo != Agen<T>::NODO_NULO){
                eliminarSubarbol(hijo,A);
                hijo = A.hermDrcho(hijo);
            }
            if(A.elemento(n) == x){
                n = A.padre(n);
                typename Agen<T>::nodo hijo;
                hijo = A.hijoIzqdo(n);
                if(A.elemento(hijo) == x){
                    A.eliminarHijoIzqdo(A.padre(n));
                }else{
                    while(hijo != Agen<T>::NODO_NULO && A.elemento(A.hermDrcho(hijo)) != x){
                        hijo = A.hermDrcho(hijo);
                    }
                    A.eliminarHermDrcho(hijo);
                }
                
            }
        }
    }
}


/***Calcular densidad de un arbol
    La densidad se define como el Grado maximo de un Arbol partido
    del numero de nodos hojas.***/
template <typename T>
float densidad(const Agen<T>& A){
    return gradoMax(A.raiz(),A)/numHojas(A.raiz(),A) * 100;
}

template <typename T>  
int gradoMax(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }else{
        int grado = contarHijos(n,A);
        int contador = 0;
        typename Agen<T>::nodo hijo;
        hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO){
            grado = max(grado, gradoMax(hijo,A));
            hijo = A.hermDrcho(hijo);
        }
        return grado;
    }
}

template <typename T>  
int contarHojas(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }else{
        if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO){
            return 1 + contarHojas(A.hermDrcho(n),A);
        }else{
            return contarHojas(A.hijoIzqdo(n),A) + contarHojas(A.hermDrcho(n),A);
        }
    }

}


/*
Implementa un subprograma que devuelva el porcentaje de descendientes 
propios de un árbol general que sean múltiplos de 3.
*/
template <typename T>  
float porcentajeDescendientes(const Agen<T>& A){
    return numDescendientesPropios(A.raiz(),A)*100/contarNodosAgen(A.raiz(),A);
}

template <typename T> 
int numDescendientesPropios(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }else{
        if(contarHijos(n,A) % 3 == 0)
            return 1 + numDescendientesPropios(A.hijoIzqdo(n),A) + numDescendientesPropios(A.hermDrcho(n),A);
        else  
            return numDescendientesPropios(A.hijoIzqdo(n),A) + numDescendientesPropios(A.hermDrcho(n),A);
    }
}

template <typename T> 
int contarNodosAgen(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else
        return 1 + contarNodosAgen(A.hijoIzqdo(n),A) + contarNodosAgen(A.hermDrcho(n),A);
}

//Contar nodos verdes de un arbol general, donde un nodo verde es aquel, cuyo numero de nietos es el doble al numero de hijos
template <typename T>
int verdes(const Agen<T> &A){
    return verdes_Rec(A.raiz(), A);
}

template <typename T>
int verdes_Rec(typename Agen<T>::nodo n, const Agen<T> &A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        if(contar_nietos(A.hijoIzqdo(n), A) = 2 * contar_hijos(A.hijoIzqdo(n), A)){
            return 1 + verdes_Rec(A.hijoIzqdo(n), A) + verdes_Rec(A.hermDrcho(n), A);
        }
        else{
            return verdes_Rec(A.hijoIzqdo(n), A) + verdes_Rec(A.hermDrcho(n), A);
        }
    }
}

template <typename T>
int contar_hijos(typename Agen<T>::nodo n, const Agen<T> &A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        return 1 + contar_hijos(A.hermDrcho(n), A);
    }
}

template <typename T>
int contar_nietos(typename Agen<T>::nodo n, const Agen<T> &A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        return contar_hijos(A.hijoIzqdo(n), A) + contar_nietos(A.hermDrcho(n), A);
    }
}


// Se da un árbol general, cuyos nodos pueden estar vivos o muertos,
// y tienen una cantidad de *riqueza*. Se pide una función que tome
// un nodo vivo del árbol, lo ponga a muerto y redistribuya su riqueza
// con sus herederos.
//
// Los herederos de un nodo son sus hijos vivos, y sus hijos muertos
// con descendientes vivos* (importante). Cuando se tenga que distribuir
// riquezas, se dividirán a parte siguales para todos los herederos.
// Si se da riqueza a un nodo muerto, este proceso anterior se repite
// con sus herederos.

struct T{
    bool vivo;
    float dinero;
};

template <typename T>
void herencia(typename Agen<T>::nodo n, Agen<T> &A){
    if(n != Agen<T>::NODO_NULO){
        A.elemento(n).vivo = false;
        float dineroRepartir = A.elemento(n).dinero/contarHijos(n,A);
        A.elemento(n).dinero = 0;
        repartir(n,A,dineroRepartir);   
    }
    
}

template <typename T>
void repartir(typename Agen<T>::nodo n, Agen<T> &A, float dineroRepartir){
    if(n != Agen<T>::NODO_NULO){
        typename Agen<T>::nodo hijo;
        hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO){
            A.elemento(hijo).dinero += dineroRepartir;
            if(A.elemento(hijo).vivo == false){
                herencia(hijo,A);
            }
            hijo = A.hermDrcho(hijo);
        }
    }
}