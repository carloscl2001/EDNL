#include "arbol.h"
#include <cassert>
#include <iostream>
#include <fstream>

//------------------------------------------//
//                  ARBOLES                 //
//------------------------------------------//

//Implementa un subprograma que calcule el número de nodos de un árbol binario

template <typename T>
int numNodos(const Abin<T> &A){
    return numNodos_rec(A.raiz(), A);
}

template <typename T>
int numNodos_rec (typename Abin<T>::nodo n, const Abin<T> &A){
    if(n == abin<T>::NODO_NULO){
        return 0;
    }
    else{
        return 1 + numNodos_rec(A.hijoIzqdo(n), A) + numNodos_rec(A.hijoDrcho(n), A);
    }
}

//Implementa un subprograma que calcule la altura de un árbol binario.

template <typename T>
int alturaArbolBin(const Abin<T>& a){
    return alturaArbolBin_rec(A.raiz(), A);
}

template <typename T>
int alturaArbolBin_rec(typename Abin<T>::nodo n, cosnt Abin<T> &A){
    if(n == Abin<T>::NODO_NULO){
        return -1;
    }
    else{
        return (1 + std::max((alturaArbolBin_rec(A.hijoIzqdo(n)), A), alturaArbolBin_rec(A.hijoDrcho(n), A)));
    }
}

//Implementa un subprograma que, dados un árbol binario y un nodo del mismo, determine
// la profundidad de este nodo en dicho árbol.

template <typename T>
int profundidadArbolB_rec(typename Abin<T>::nodo n, const Abin<T> &A){
    if(n == Abin<T>::NODO_NULO){
        return -1;
    }
    else{
        return 1 + profundidadArbolB_rec(A.padre(n), A);
    }
}

//Implementa un subprograma que determine el nivel de desequilibrio de un árbol binario,
//definido como el máximo desequilibrio de todos sus nodos. El desequilibrio de un nodo se
//define como la diferencia entre las alturas de los subárboles del mismo.

template <typename T>
int desequilibrio(const Abin<T> &A){
    return desequilibroo_rec(A.raiz(), A);
}

template <typename T>
int desequilibroo_rec(typename Abin<T>::nodo n, const Abin<T> &A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        int desequilibrio = std::abs(alturaArbolBin_rec(A.hijoIzqdo(n), A), alturaArbolBin_rec(A.hijoDrcho(n), A));
        return std::max(desequilibrio, desequilibroo_rec(A.hijoIzqdo(n), A), desequilibroo_rec(A.hijoDrcho(n), A));
    }
}

//Implementa un subprograma que determine si un árbol binario es o no pseudocompleto.
//En este problema entenderemos que un árbol es pseudocompleto, si en el penúltimo nivel
//del mismo cada uno de los nodos tiene dos hijos o ninguno.

template <typename T>
bool pseudocompleto(const Abin<T> &A){
    return pseudocompleto_rec(A.raiz(), A);
}

template <typename T>
bool pseudocompleto_rec(typename Abin<T>::nodo n, const Abin<T> &A){
    if(n == abin<t>::NODO_NULO){
        return true;
    }
    else{
        if(profundidadArbolB_rec(n, A) == alturaArbol(A) - 1){
            if(A.hijoDrcho(n) == Abin<T>::NODO_NULO || A.hijoIzqdo(n) == Abin<T>::NODO_NULO){
                return true;
            }
            else if(A.hijoDrcho(n) != Abin<T>::NODO_NULO || A.hijoIzqdo(n) 1= Abin<T>::NODO_NULO){
                return true;
            }
            else{
                return false;
            }
        }

        return pseudocompleto_rec(A.hijoIzqdo(n), A) && pseudocompleto_rec(A.hijoDrcho(n), A);
    }
}

//Dos �rboles binarios son similares cuando tienen id�ntica estructura de ramificaci�n,
//es decir, ambos son vac�os, o en caso contrario, tienen sub�rboles izquierdo y derecho
//similares. Implementa un subprograma que determine si dos �rboles binarios son
//similares.

template <typename T>

bool similares(const abin<T> &A, const Abin<T> &B){
    return similares_rec(A.raiz(), B.raiz(), A, B);
}

bool similares_rec(typename Abin<T>::nodo a, typename Abin<T>::nodo b, const abin<T> &A, const Abin<T> &B){
    if(a == abin<T>::NODO_NULO && b == abin<T>::NODO_NULO){
        return true;
    }
    else{
        if(a == abin<T>::NODO_NULO || b == abin<T>::NODO_NULO) {
            return false;
        }
        else{
            return similares_rec(A.hijoIzqdo(a), B.hijoIzqdo(b), A, B) && similares_rec(A.hijoDrcho(a), B.hijoDrcho(b), A, B);
        }
    }
}


//Contar los nodos verdes que sean nostalgicos (mas antecesores que descendientes)

template <typename T>

int nodos_Verdes(const Abin<T> &A){
    return nodos_Verdes(A.raiz(), A);
}

int nodos_Verdes_rec(typename Abin<T>::nodo n, const Abin<T> &A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        if(profundidad(n, A) > contar_descendientes(n, A)){
            return 1 + nodos_Verdes_rec(A.hijoIzqdo(n), A) + nodos_Verdes_rec(A.hijoDrcho(n), A);
        }
        else{
            return nodos_Verdes_rec(A.hijoIzqdo(n), A) + nodos_Verdes_rec(A.hijoDrcho(n), A);
        }
    }
}

int contar_descendientes(typename Abin<T>::nodo A, const Abin<T> &A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        return 1 + contar_descendientes(A.hijoIzqdo(n), A) + contar_descendientes(A.hijoDrcho(n), A)
    }
}

//Contar nodos verdes de un arbol binario, donde un nodo verde es aquel, cuyo numero de nietos es el doble al numero de hijos

template <typename T>
int verdes(cosnt Abin<T> &A){
    return verdes_Rec(A.raiz(), A);
}

template <typename T>
int verdes_Rec(typename Abin<T>::nodo n, A){
    if(Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        if(contar_nietos(n, A) = 2*contar_hijos(n, A)){
            return 1 + verdes_Rec(A.hijoIzqdo(n), A) + verdes_Rec(A.hijoDrcho(n), A);
        }
        else{
            return verdes_Rec(A.hijoIzqdo(n), A) + verdes_Rec(A.hijoDrcho(n), A);
        }
    }
}

template <typename T>
int contar_hijos(typename Abin<T>::nodo n, cosnt Abin<T> &A){
    if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO){
        return 0;
    }
    else if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO){
        return 2;
    }
    else{
        return 1;
    }
}

template <typename T>
int contar_nietos(typename Abin<T>::nodo n, const Abin<T> &A){
    return contar_hijos(A.hijoIzqdo(n), A) + contar_hijos(A.hijoDrcho(n), A);
}

//Calcula el indice de prosperidad de una poblacion, calcula el porcentaje de nodos prosperos, el elemento del nodo nos indica la 
//riqueza, se considera que un nodo es prospero cuando su dinero es mayor que el de sus antecesores propios y su dinero es menor que sus 
//descendientes propios.

template <typename T>
float prosperidad(const Abin<T> &A){
    return ((Prosperos(A.raiz(), A) / numeroNodos(A.raiz(), A)) * 100);
}

template <typename T>
int Prosperos(typename Abin<T>::nodo N, const Abin<T> &A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        if(A.elemento(A.padre(n)) < A.elemento(n) && A.elemento(n) < dinero_Hijos(n, A)){
            return 1 + Prosperos(a.hijoIzqdo(n), A) + Prosperos(a.hijoDrcho(n), A);
        }
        else{
            return Prosperos(a.hijoIzqdo(n), A) + Prosperos(a.hijoDrcho(n), A);
        }
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

int numeroNodos(typename Abin<T>::nodo n, cosnt Abin<T> &A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        return 1 + numeroNodos(A.hijoIzqdo(n) ,A) + numeroNodos(A.hijoDrcho(n) ,A);
    }
}

//Contar nodos verdes (aquellos que tienen 4 o mas descendientes)

template <typename T>
int nodosVerdes(const Abin<T> &A){
    return nodosVerdes_rec(A.raiz(), A);
}

template <typename T>
int nodosVerdes_rec(typename Abin<T>::nodo n, const Abin<T> &A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        if(contarDescendientes(n, A) >= 4){
            return 1 + nodosVerdes_rec(A.hijoIzqdo(n), A) + nodosVerdes_rec(A.hijoDrcho(n), A);
        }
        else{
            return nodosVerdes_rec(A.hijoIzqdo(n), A) + nodosVerdes_rec(A.hijoDrcho(n), A);
        }
    }
}

template <typename T>
int contarDescendientes(typename Abin<T>::nodo n, const Abin<T> &A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        return 1 + contarDescendientes(A.hijoIzqdo(n), A) + contarDescendientes(A.hijoDrcho(n), A);
    }
}

//Contar los nodos que tengan 3 nietos

template <typename T>
int nietos(const Abin<T> &A){
    return nietos_rec(A.raiz(), A);
}

template <typename T>
int nietos_rec(typename Abin<T>::nodo n, const Abin<T> &A){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        if(nietos(A.hijoIzqdo(n), A.hijoDrcho(n), A) == 3){
            return 1 + nietos_rec(A.hijoIzqdo(n), A) + nietos_rec(A.hijoDrcho(n), A);
        }
        else{
            return nietos_rec(A.hijoIzqdo(n), A) + nietos_rec(A.hijoDrcho(n), A);
        }
    }
}

template <typename T>
int nietos(typename Abin<T>::nodo izqdo, typename Abin<T>::nodo drcho, const Abin<T> &A){
    return contar_hijos(izqdo, A) + contar_Hijos(drcho, A);
}

template <typename T>
int contar_hijos(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        return 1 + contar_hijos(A.hermDrcho(n), A);
    }
}

//------------------------Generales----------------------------------------------------------------------------------------

//Implementa un subprograma que dado un árbol general nos calcule su grado (numero maximo de hijos que tiene un arbol)

template <typename T>
int grado(const Agen<T> &A){
    return grado_Rec(A.raiz(), A);
}

template <typename T>
int grado_Rec(typename Agen<T>::nodo n, cosnt Agen<T> &A){
    typename Agen<T>::nodo hijo;
    int MaxHijos;

    if(n == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        maxHijos = contar_Hijos(A.hijoIzqdo(n), A);
        hijo = A.hijoIzqdo(n);

        while(hijo != Agen<T>::NODO_NULO){
            MaxHijos = std::max(MaxHijos, grado_rec(hijo, A));
            hijo = A.hermDrcho(hijo);
        }

        return maxHijos;
    }
}

int contar_Hijos(typename Agen<T>::nodo n, const Agen<T> &A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        return 1 + contar_Hijos(A.hermDrcho(n), A);
    }
}

//Se define el desequilibrio de un árbol general como la máxima diferencia entre las alturas
//de los subárboles más bajo y más alto de cada nivel. Implementa un subprograma que calcule
//el grado de desequilibrio de un árbol general.

template <typename T>
int calcularDesequilibrio(typename Agen<T>::nodo n, const Agen<T>& A)
{
    
    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        int dif, altMax, altMin = 0;
        altMax = altura(A.hijoIzqdo(n),A);
        altMin = altura(A.hijoIzqdo(n),A);
        if(A.hermDrcho(A.hijoIzqdo(n)) != Agen<T>::NODO_NULO)
        {
            typename Agen<T>::nodo nodo;
            nodo = A.hermDrcho(A.hijoIzqdo(n));
            while(nodo != Agen<T>::NODO_NULO)
            {
                altMax = std::max(altMax, altura(nodo,A));
                altMin = std::min(altMin, altura(nodo,A));
                nodo = A.hermDrcho(nodo);  
            }
            dif = altMax - altMin;
            return dif;
        }
        else
        {
            dif = altMax - altMin;
            return dif;
        }
    }
}

template <typename T>
int altura(typename Agen<T>::nodo n, const Agen<T>& A)
{
    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        int alt = 0;
        typename Agen<T>::nodo nodo;
        nodo = A.hijoIzqdo(n);
        while(nodo != Agen<T>::NODO_NULO)
        {
            alt = std::max(alt, altura(nodo,A));
            nodo = A.hermDrcho(nodo);
        }
        return 1 + alt;
    }
}

//Ejercicio 4: Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice
//la poda de A a partir de x. Se asume que no hay elementos repetidos en A.

void poda(int x, Agen<T> &A){
    typename Agen<T>::nodo nodoBuscado = buscar(x, A.raiz(), A);
    poda_rec(nodoBuscado, nodoBuscado, A);
}

template <typename T>
Agen<T>::nodo buscar(int x, typename Agen<T>::nodo n, const Agen<T> &A){
    if(n==Agen<T>::NODO_NULO){
        return Agen<T>::NODO_NULO;
    }
    else{
        if(A.elemento(n) == x){
            return n;
        }
        else{
            typename Agen<T>::nodo aux = buscar(x, A.hijoIzqdo(n), A);
            if(aux != Agen<T>::NODO_NULO){
                return aux;
            }
            else{
                return buscar(x, A.hermDrcho(n), A);
            }
        }
    }
}

void poda_rec(typename Agen<T>::nodo n, typename Agen<T>::nodo elemento, Agen<T>& A){
    if(n != Agen<T>::NODO_NULO){
        if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO){
            if(n != elemento){
                n = A.padre(n);
                A.eliminarHijoIzqdo(n);
                poda_rec(n, elemento, A);
            }
        }
        else{
            poda_rec(A.hijoIzqdqo(n), elemento, A);
        }
    }
}

/***Calcular densidad de un arbol
    La densidad se define como el Grado maximo de un Arbol partido
    del numero de nodos hojas.***/

template <typename T>
float densidad(const Agen<T> &A){
    return ((grado_Arbol(A.raiz(), A) / num_nodos(A.raiz(), A)) * 100);
}

template <typename T>
int num_nodos(typename Agen<T>::nodo n, const Agen<T> &A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        return 1 + num_nodos(A.hijoIzqdo(n), A) + num_nodos(A.hermDrcho(n), A);
    }
}

template <typename T>
int grado_Arbol(typename Agen<T>::nodo n, const Agen<T> &A){
    typename Agen<T>::nodo aux;
    int grado;

    if(n == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        aux = A.hijoIzqdo(n);
        grado = contar_Hijos(A.hijoIzqdo(n), A);

        while(aux != Agen<T>::NODO_NULO){
            grado = std::max(grado, grado_Arbol(A.hijoIzqdo(n), A));
            aux = A.hermDrcho(aux);
        }

        return grado;
    }
}

template <typename T>
int contar_Hijos(typename Agen<T>::nodo n, const Agen<T> &A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        return 1 + contar_Hijos(A.hermDrcho(n), A);
    }
}

/*
Implementa un subprograma que devuelva el porcentaje de descendientes 
propios de un árbol general que sean múltiplos de 3.
*/

template <typename T>
float porcentajeDescendientes(const Agen<T> &A){
    return ((num_multiplos3(A.raiz(), A) / numNodos(A.raiz(), A)) * 100);
}

template <typename T>
int num_multiplos3(typename Agen<T>::nodo n, const Agen<T> &A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        if(contar_descendientes(A.hijoIzqdo(n), A) % 3 == 0){
            return 1 + num_multiplos3(A.hijoIzqdo(n), A) + num_multiplos3(A.hijoDrcho(n), A);
        }
        else{
            return num_multiplos3(A.hijoIzqdo(n), A) + num_multiplos3(A.hijoDrcho(n), A);
        }
    }
}

template <typename T>
int contar_descendientes(typename Agen<T>::nodo n, const Agen<T> &A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        return 1 + contar_descendientes(A.hermDrcho(n), A);
    }
}

template <typename T>
int numNodos(typename Agen<T>::nodo n, const Agen<T> &A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        return 1 + numNodos(A.hijoIzqdo(n), A) + numNodos(A.hermDrcho(n), A);
    }
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
        if(contar_nietos(A.hijoIzqdo(n), A) = 2*contar_hijos(A.hijoIzqdo(n), A)){
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
// *con descendientes vivos* (importante). Cuando se tenga que distribuir
// riquezas, se dividirán a parte siguales para todos los herederos.
// Si se da riqueza a un nodo muerto, este proceso anterior se repite
// con sus herederos.

struct Persona{
    bool vivo;
    float dinero;
};

void matar(typename Agen<Persona>::nodo n, Agen<Persona> A){
    if(n != Agen<Persona>::NODO_NULO){
        A.elemento(n).vivo = false;
        float dinero_repartir = A.elemento(n).dinero / contar_hijos(A.hijoIzqdo(n), A);
        repartir_dinero(dinero_repartir, A.hijoIzqdo(n), A);
    }
}

void repartir_dinero(float dinero_repartir, typename Agen<Persona>::nodo n, Agen<Persona> A){
    if(n != Agen<Persona>::NODO_NULO){
        A.elemento(n).riqueza += dinero;
        if(!A.elemento(n).vivo){
            matar(n, A);
        }
        repartir_dinero(dinero_repartir, A.hermDrcho(n), A);
    }
    
}

int contar_hijos(typename Agen<Persona>::nodo n, const Agen<Persona>::NODO_NULO){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        return 1 + contar_hijos(A.hermDrcho(n), A);
    }
}

//Ejercicio 2:Un árbol binario de búsqueda se puede equilibrar realizando el recorrido en inorden
//del árbol para obtener el listado ordenado de sus elementos y a continuación, repartir
//equitativamente los elementos a izquierda y derecha colocando la mediana en la raíz y
//construyendo recursivamente los subárboles izquierdo y derecho de cada nodo.
//Implementa este algoritmo para equilibrar un ABB.

template <typename T>
//El abb que devolvemos al estar equilibrado seria un AVL
void equilibrar(Abb<T> A){
    std::vector<T> vector;
    rellenarVector(vector, A);
    Abb<T> nuevo;
    rellenarAbb(vector, nuevo);
    A = nuevo;
}

template <typename T>
void rellenarVector(std::vector<T> &vector, Abb<T> &A){
    if(!A.izqdo().vacio()){
        rellenarVector(A.izqdo(), A);
    }
    vector.emplace_back(A.elemento());
    if(!A.drcho().vacio()){
        rellenarVector(A.drcho(), A);
    }
}

template <typename T>
void rellenarAbb(std::vector<T> &vector, Abb<T> &nuevo){
    T tamano = vector.size();
    std::vector mitad_izqda<T>;
    std::vector mitad_drcha<T>;

    for(int i = 0; i < tamano; i++){
        if(i < tamano/2 - 1){
            mitad_izqda.emplace_back(vector[i]);
        }
        else if(i == tamano/2 - 1){
            nuevo.insertar(vector[i]);
        }
        else{
            mitad_drcha.emplace_back(vector[i]);
        }
    }

    rellenarAbb(mitad_izqda, nuevo);
    rellenarAbb(mitad_drcha, nuevo);
}

//Ejercicio 3:
//Dados dos conjuntos representados mediante árboles binarios de búsqueda,
//implementa la operación unión de dos conjuntos que devuelva como resultado otro
//conjunto que sea la unión de ambos, representado por un ABB equilibrado.

template <typename T>
Abb<T> union(Abb<T> A, Abb<T> B){
    Abb<T> Arbol_unido = A;
    std::vector<T> vector;

    rellenarVector(vector, B);

    for(int i = 0; i < vector.size(); i++){
        Arbol_unido.insertar(vector[i]);
    }

    equilibrar(Arbol_unido);

    return Arbol_unido;
}

//Ejercicio 4:
//Dados dos conjuntos representados mediante árboles binarios de 
//búsqueda, implementa la operación intersección de dos conjuntos, que 
//devuelva como resultado otro conjunto que sea la intersección de ambos.
//El resultado debe quedar en un árbol equilibrado.

template <typename T>
Abb<T> insercion(Abb<T> A, Abb<T> B){
    Abb<T> final;

    std::vector<T> vectorA;
    std::vector<T> vectorB;

    for(int i = 0; i < vectorA.size(); i++){
        for(int j = 0; j < vectorB.size(); i++){
            if(vectorA[i] == vectorB[i]){
                final.insertar(vector[i]);
            }
        }
    }

    equilibrar(final);

    return final;
}


//Ejericio 5:
//Implementa el operador ROMBO para conjuntos definido como 
//A ROMBO B = (A U B) - (A n B). La implementación del operador ROMBO debe 
//realizarse utilizando obligatoriamente la operación E, que nos indica 
//si un elemento dado pertenece o no a un conjunto. La representación 
//del tipo Conjunto debe ser tal que la operación de pertenencia esté en 
//el caso promedio en O(log n).

template <typename T>

Abb<T> rombo(Abb<T> A, Abb<T> B){
    Abb<T> rombo;
    Abb<T> union = union(A, B);
    Abb<T> insercion = insercion(A, B);
    
    std::vector<T> vectorUnion;
    std::vector<T> vectorInsercion;

    rellenar_Vector(vectorUnion, union);
    rellenar_Vector(vectorInsercion, insercion);

    for(int i = 0; i < union.size(), i++){
        for(int j = 0; j < insercion.size(), j++){
            bool encontrado = false;
            if(union[i] == insercion[j]){
                encontrado = true;
            }
        }
        if(encontrado == false){
            rombo.insertar(union[i]);
        }
    }

    equilibrar(rombo);

    return rombo;
}

/*
Dado un conjunto ordenado no vacío A, se define el ínfimo de x como el mayor 
elemento de A menor o igual que x, si existe. Análogamente, el supremo de x 
en A, si existe, es el menor elemento de A mayor o igual que x.

Implementa dos funciones de O(log n) en promedio que dados un valor x cualquiera
y un ABB A no vacío devuelvan, respectivamente, el ínfimo y el supremo de x en A. 
Si no existe el ínfimo de x en A, la función correspondiente devolverá el mínimo 
de A. Así mismo, la otra función devolverá el máximo de A, en el caso de que no 
existe el supremo.

Nota: Es absolutamente necesario definir todos los tipos de datos implicados en 
la resulución del ejercicio, así como los prototipos de las operaciones 
utilizadas de los TADs conocidos.
*/

T infimo(const T& x, const Abb<T> &A){
    std::vector<T> vectorA;

    if(!A.buscar(x).vacio()){
        return A.elemento(A.buscar(x));
    }
    else{
        rellenar_Vector(vectorA , A);
    
        int i = 0;
        while(v[i] < x){
            i++;
        }
        if(v[i] < x){
            return v[i];
        }
        else{
            return v[0];
        }
    }

}

T supremo(const T& x, const Abb<T> &A){
    std::vector<T> vectorA;

    if(!A.buscar(x).vacio()){
        return A.elemento(A.buscar(x));
    }
    else{
        rellenar_Vector(vectorA , A);
    
        int i = vectorA.size();
        while(v[i] > x){
            i--;
        }
        if(v[i] > x){
            return v[i];
        }
        else{
            return v[vectorA.size() - 1];
        }
    }

}

void rellenar_Vector(std::Vector<T>& vectorA, Abb<T> A){
    if(!A.izqdo().vacio()){
        rellenarVector(A.izqdo(), A);
    }
    vectorA.emplace_back(A.elemento());
    if(!A.drcho().vacio()){
        rellenarVector(A.drcho(), A);
    }
}

/*Haz una agenda usando un Arbol de búsqueda. Utiliza como estructura una
con los campos telefono y nombre por ejemplo y acuerdate de sobrecargar
los operandos de comparación de la estructura.*/

/*class Contacto{
public:
    Contacto(string nombre, string telefono);
    string telefono(string nombre);
    string nombre(string telefono);
    ~Contacto();
private:
    string telefono_, nombre_;
};

Contacto::Contacto(string nombre, string telefono){
    nombre_ = nombre;
    telefono_ telefono;
}

string Contacto::telefono(string nombre){
    return telefono_;
}

string Contacto::nombre(string telefono){
    return nombre_;
}

Contacto::~Contacto(){
}*/

struct Persona{
    string telefono;
    string nombre;

    Persona(string nom, string telf): nombre(nom), telefono(telf) {}
};

class Agenda{
    public:
        Agenda();
        void insertarContacto(string telf, string nom);
        void eliminarContacto(persona p);
        Persona buscarContacto(persona p);
        bool agendaVacia();
        Persona primercontactoagenda();
        ~Agenda(){};
    private:
        Abb<Persona> agenda;
};

Agenda::Agenda():agenda(Abb<Persona>()){}

void Agenda::insertarContacto(string telf, string nom){
    Persona p(nom, telf);

    agenda.insertar(p);
}

void Agenda::eliminarContacto(persona p){
    agenda.eliminar(agenda.buscar(p));
}

Persona Agenda::buscarContacto(persona p){
    return agenda.elemento(agenda.buscar(p));
}

bool Agenda::agendaVacia(){
    return agenda.vacio();
}

Persona Agenda::primercontactoagenda(){
    return agenda.elemento();
}


/*Se necesita hacer un estudio de las distancias mínimas necesarias para viajar entre
dos ciudades cualesquiera de un país llamado Zuelandia. El problema es sencillo pero
hay que tener en cuenta unos pequeños detalles: 
    a) La orografía de Zuelandia es un poco especial, las carreteras son muy estrechas
y por tanto solo permiten un sentido de la circulación.
    b) Actualmente Zuelandia es un país en guerra. Y de hecho hay una serie de
ciudades del país que han sido tomadas por los rebeldes, por lo que no pueden
ser usadas para viajar.
    c) Los rebeldes no sólo se han apoderado de ciertas ciudades del país, sino que
también han cortado ciertas carreteras, (por lo que estas carreteras no pueden ser
usadas).
    d) Pero el gobierno no puede permanecer impasible ante la situación y ha exigido
que absolutamente todos los viajes que se hagan por el país pasen por la capital
del mismo, donde se harán los controles de seguridad pertinentes. 
Dadas estas cuatro condiciones, se pide implementar un subprograma que dados
    • el grafo (matriz de costes) de Zuelandia en situación normal,
    • la relación de las ciudades tomadas por los rebeldes,
    • la relación de las carreteras cortadas por los rebeldes
    • y la capital de Zuelandia, 
calcule la matriz de costes mínimos para viajar entre cualesquiera dos ciudades
zuelandesas en esta situación. 
*/

template <typename tCoste>

matriz<tCoste> ejercicio1(GrafoP<tCoste> Grafo, const std::vector<bool> &ciudades_tomadas, const std::matriz<bool> &carreteras_cortadas, typename GrafoP<tCoste>::Vertice capital){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N = G.NumVert();
    static const tCoste INF = GrafoP<tCoste>::INFINITO;

    for(vertice i = 0; i < N; i++){
        if(ciudades_tomadas[i]){
            for(vertice j = 0; j < N; j++){
                G[i][j] = INF;
                G[j][i] = INF;
            }
        }
    }

    for(vertice i = 0; i < N; i++){
        for(vertice j = 0; j < N; j++){
            if(carreteras_cortadas[i][j]){
                G[i][j] = INF;
            }
        }
    }

    std::vector<vertice> P1;
    std::vector<tCoste> hacia_capital = DjikstraInv(G, capital, P1);
    std::vector<vertice> P2;
    std::vector<tCoste> desde_capital = Djikstra(G, capital, P2);

    GrafoP<tCoste> Grafo_final(N);
    for(vertice i = 0; i < N; i++){
        for(vertice j = 0; j < N; j++){
            Grafo_final[i][j] = std::sum(hacia_capital[i], desde_capital[j]);
        }
        Grafo_final[i][i] = 0;
    }

    return Grafo_final;

}

//----------------PRACTICA 7----------------------------------------

/*Se dispone de un laberinto de NxN casillas del que se conocen las casillas de entrada 
y salida del mismo. Si te encuentras en una casilla sólo puedes moverte en las siguientes 
cuatro direcciones (arriba, abajo, derecha, izquierda). Por otra parte, entre algunas de las 
casillas hay una pared que impide moverse entre las dos casillas que separa dicha pared 
(en caso contrario no sería un verdadero laberinto). 
Implementa un subprograma que dados 
     N (dimensión del laberinto), 
     la lista de paredes del laberinto, 
     la casilla de entrada, y 
     la casilla de salida, 
calcule el camino más corto para ir de la entrada a la salida y su longitud.*/

struct Celda{
    int x, y;
    Celda(int x_, int y_): x(x_), y(y_) {}
}

struct Pared{
    Celda a, b;
}

template <typename tCoste>
Celda toCelda(typename GrafoP<tCoste>::vertice v, int n){
    return Celda(v%n, v/n);
}

template <typename tCoste>
typename GrafoP<tCoste>::vertice toVertice(Celda c){
    return c.i * n + c.j;
}

bool esAdyacente(Casilla c1, Casilla c2){
    return (abs(c1.i - c2.i) <= 1) && (abs(c1.j - c2.j) <= 1);
}

GrafoP<tCoste> construir_laberinto(const size_t N, const std::vector<Pared> &paredes){
    typedef typename GrafoP<tCoste>::vertice vertice;
    static const int INF = GrafoP<tCoste>::INFINITO;
    size_t tam = N*N;

    Grafo<tCoste> Laberinto(tam);

    for(vertice i = 0; i < tam; i++){
        for(vertice j = 0; j < tam; j++){
            if(i = j){
                Laberinto[i][j] = INF;
            }
            else if(esAdyacente(toCelda(i, tam), toCelda(j, tam))){
                Laberinto[i][j] = 1;
            }
            else{
                Laberinto[i][j] = INF;
            }

        }
    }

    for(vertice i = 0; i < paredes.size(), i++){
        Laberinto[paredes[i].a][paredes[i].b] = INF;
    }

    return Laberinto;
}

size_t solucion(Celda Entrada, Celda Salida, std::vector<Celda>& camino, const size_t N, const std::vector<Pared> &paredes){
    typedef typename GrafoP<tCoste>::vertice vertice;
    Grafop<Celda> laberinto = construir_laberinto(N, paredes);

    std::vector<vertice> P1;

}

/*Ejericio 3: Eres el orgulloso dueño de una empresa de distribución. Tu misión radica en 
distribuir todo tu stock entre las diferentes ciudades en las que tu empresa dispone de 
almacén. 
Tienes un grafo representado mediante la matriz de costes, en el que aparece el coste 
(por unidad de producto) de transportar los productos entre las diferentes ciudades del 
grafo. 
Pero además resulta que los Ayuntamientos de las diferentes ciudades en las que 
tienes almacén están muy interesados en que almacenes tus productos en ellas, por lo 
que están dispuestos a subvencionarte con un porcentaje de los gastos mínimos de 
transporte hasta la ciudad. Para facilitar el problema, consideraremos despreciables los 
costes de volver el camión a su base (centro de producción). 
He aquí tu problema. Dispones de 
     el centro de producción, nodo origen en el que tienes tu producto (no tiene 
    almacén), 
     una cantidad de unidades de producto (cantidad), 
     la matriz de costes del grafo de distribución con N ciudades, 
     la capacidad de almacenamiento de cada una de ellas, 
     el porcentaje de subvención (sobre los gastos mínimos) que te ofrece cada 
    Ayuntamiento. 
Las diferentes ciudades (almacenes) pueden tener distinta capacidad, y además la 
capacidad total puede ser superior a la cantidad disponible de producto, por lo que 
debes decidir cuántas unidades de producto almacenas en cada una de las ciudades. 
Debes tener en cuenta además las subvenciones que recibirás de los diferentes 
Ayuntamientos, las cuales pueden ser distintas en cada uno y estarán entre el 0% y el 
100% de los costes mínimos. 
La solución del problema debe incluir las cantidades a almacenar en cada ciudad bajo 
estas condiciones y el coste mínimo total de la operación de distribución para tu 
empresa.*/

struct solucion{
    std::vector<size_t> cantidad[N];
    tCoste coste_total;
}

solucion distribuir(const GrafoP<tCoste>::vertice origen, size_t cantidad, const std::vector<size_t> &capacidad_almacen, const std::vector<double> &subvencion, const GrafoP<tCoste> &G){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N = G.numVert();
    static const tCoste INF = GrafoP<tCoste>::INFINITO;

    solucion s;

    tCoste min_coste = INF;
    vertice mejor_ciudad;
    vertice ciudad_actual = origen;

    matriz<tCoste> P1;

    matriz<tCoste> F = Floyd(G, P1);

    while(cantidad > 0){
        for(vertice i = 0; i < N; i++){
            if(F[ciudad_actual][i] - (F[ciudad_actual][i]*subvenciones[i]) < min_coste){
                min_coste = (F[ciudad_actual][i] - (F[ciudad_actual][i]*subvenciones[i]));
                mejor_ciudad = i;
            }
        }
        if(capacidad_almacen[mejor_ciudad] >= cantidad){
            s.cantidad[mejor_ciudad] = cantidad;
            s.coste_total += min_coste;
            cantidad = 0;
        }
        else{
            cantidad -= capacidad_almacen[mejor_ciudad];
            s.cantidad[mejor_ciudad] = capacidad_almacen[mejor_ciudad];
            s.coste_total += min_coste;
            ciudad_actual = mejor_ciudad;
        }
    }

    return s;

}

/*Ejercicio 4: Eres el orgulloso dueño de la empresa “Cementos de Zuelandia S.A”. Empresa 
dedicada a la fabricación y distribución de cemento, sita en la capital de Zuelandia. Para 
la distribución del cemento entre tus diferentes clientes (ciudades de Zuelandia) 
dispones de una flota de camiones y de una plantilla de conductores zuelandeses. 
El problema a resolver tiene que ver con el carácter del zuelandés. El zuelandés es 
una persona que se toma demasiadas “libertades” en su trabajo, de hecho, tienes 
fundadas sospechas de que tus conductores utilizan los camiones de la empresa para 
usos particulares (es decir indebidos, y a tu costa) por lo que quieres controlar los 
kilómetros que recorren tus camiones.
Todos los días se genera el parte de trabajo, en el que se incluyen el número de 
cargas de cemento (1 carga = 1 camión lleno de cemento) que debes enviar a cada 
cliente (cliente = ciudad de Zuelandia). Es innecesario indicar que no todos los días hay 
que enviar cargas a todos los clientes, y además, puedes suponer razonablemente que tu 
flota de camiones es capaz de hacer el trabajo diario. 
Para la resolución del problema quizá sea interesante recordar que Zuelandia es un 
país cuya especial orografía sólo permite que las carreteras tengan un sentido de 
circulación. 
Implementa una función que dado el grafo con las distancias directas entre las 
diferentes ciudades zuelandesas, el parte de trabajo diario, y la capital de Zuelandia, 
devuelva la distancia total en kilómetros que deben recorrer tus camiones en el día, para 
que puedas descubrir si es cierto o no que usan tus camiones en actividades ajenas a la 
empresa. */

template <typename tCoste>

tCoste cemento(typename GrafoP<tCoste>::vertice capital, const GrafoP<tCoste> &G, const std::vector<size_t> &parte){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N = G.numVert();

    std::vector<vertice> P1;
    std::Vector<tCoste> hacia_cliente = Dijkstra(G, capital, P1);
    std::vector<vertice> P2;
    std::Vector<tCoste> hacia_capital = Dijkstrai(G, capital, P2);

    tCoste coste = 0;
    for(vertice i = 0; i < N; i++){
        coste += (hacia_cliente[i] + hacia_capital[i]) * parte[i];
    }

    return coste;
}

/*Ejercicio 5: Se dispone de tres grafos que representan la matriz de costes para viajes en un 
determinado país pero por diferentes medios de transporte, por supuesto todos los grafos 
tendrán el mismo número de nodos. El primer grafo representa los costes de ir por 
carretera, el segundo en tren y el tercero en avión. Dado un viajero que dispone de una 
determinada cantidad de dinero, que es alérgico a uno de los tres medios de transporte, y 
que sale de una ciudad determinada, implementar un subprograma que determine las 
ciudades a las que podría llegar nuestro infatigable viajero. */

template <typename tCoste>
std::vector<bool> alergia(const GrafoP<tCoste> carretera, const GrafoP<tCoste> tren, const GrafoP<tCoste> avion, double dinero, string alergia, const typename GrafoP<tCoste>::vertice Origen){
    switch(alergia){
        case 'carretera':
            return viaje_alergia(origen, dinero, tren, avion);
        case 'avion':
            return viaje_alergia(origen, dinero, carretera, tren);
        case 'tren':
            return viaje_alergia(origen, dinero, carretera, avion);
    }
}

template <typename tCoste>
std::vector<bool> viaje_alergia(const typename GrafoP<tCoste>::vertice Origen, double dinero, const GrafoP<tCoste> G1, const GrafoP<tCoste> G2){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N = G1.numVert();
    static const INF = GrafoP<tCoste>::INFINITO;

    GrafoP<tCoste> barato(N);

    for(vertice i = 0; i < N; i++){
        for(vertice j = 0; j < N; j++){
            barato[i][j] = std::min(G1[i][j], G2[i][j]);
        }
    }

    std::vector<vertice> P;
    std::Vector<tCoste> costes = Dijkstra(G, Origen, P);

    std::vector<vertice> solucion;
    for(size_t i = 0; i < costes.size(); i++){
        if(costes[i] <= dinero){
            solucion.emplace_back(i);
        }
    }

    return solucion;
}

/*Ejercicio 6: Al dueño de una agencia de transportes se le plantea la siguiente situación. La 
agencia de viajes ofrece distintas trayectorias combinadas entre N ciudades españolas 
utilizando tren y autobús. Se dispone de dos grafos que representan los costes (matriz de 
costes) de viajar entre diferentes ciudades, por un lado en tren, y por otro en autobús 
(por supuesto entre las ciudades que tengan línea directa entre ellas). Además coincide 
que los taxis de toda España se encuentran en estos momentos en huelga general, lo que 
implica que sólo se podrá cambiar de transporte en una ciudad determinada en la que, 
por casualidad, las estaciones de tren y autobús están unidas. 
Implementa una función que calcule la tarifa mínima (matriz de costes mínimos) de 
viajar entre cualesquiera de las N ciudades disponiendo del grafo de costes en autobús, 
del grafo de costes en tren, y de la ciudad que tiene las estaciones unidas. */

template <typename tCoste>

std::matriz<tCoste> ejercicio6(const GrafoP<tCoste> tren, const GrafoP<tCoste> bus, typedef GrafoP<tCoste>::vertice ciudad_cambio){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N = tren.numVert();

    std::matriz<vertice> P1;
    std::matriz<tCoste> bus_floyd = Floyd(bus, P1);
    std::matriz<vertice> P2;
    std::matriz<tCoste> tren_floyd = Floyd(tren, P1);

    matriz<tCoste> solucion(N);


    for(auto i = 0; i < N; i++){
        for(auto j = 0; j < N; j++){
            solucion[i][j] = std::min(bus_floyd[i][j], tren_floyd[i][j], std::max(bus_floyd[i][cambio], tren_floyd[cambio][j]), std::max(tren_floyd[i][cambio], bus_floyd[cambio][j]));
        }
    }

    return solucion;

} 

/* Ejercicio 7: Se dispone de dos grafos (matriz de costes) que representan los costes de viajar entre 
N ciudades españolas utilizando el tren (primer grafo) y el autobús (segundo grafo). 
Ambos grafos representan viajes entre las mismas N ciudades. 
Nuestro objetivo es hallar el camino de coste mínimo para viajar entre dos ciudades 
concretas del grafo, origen y destino, en las siguientes condiciones: 
     La ciudad origen sólo dispone de transporte por tren. 
     La ciudad destino sólo dispone de transporte por autobús. 
     El sector del taxi, bastante conflictivo en nuestros problemas, sigue en huelga, 
        por lo que únicamente es posible cambiar de transporte en dos ciudades del 
        grafo, cambio1 y cambio2, donde las estaciones de tren y autobús están 
        unidas. 
Implementa un subprograma que calcule la ruta y el coste mínimo para viajar entre 
las ciudades Origen y Destino en estas condiciones.*/

template <typename tCoste>

struct solucion{
    tCoste minimo;
    std::vector<typedef GrafoP<tCoste>::vertice> camino;
}

tCoste ejercicio7(const GrafoP<tCoste> tren, const GrafoP<tCoste> bus, typedef GrafoP<tCoste>::vertice Origen, typedef GrafoP<tCoste>::vertice Destino, typedef GrafoP<tCoste>::vertice cambio1, typedef GrafoP<tCoste>::vertice cambio2){
    typdef typename GrafoP<tCoste>::Vertice vertice;
    const size_t N = bus.numVert();
    static const INF = GrafoP<tCoste>::INFINITO;
    solucion s;

    std::vector<vertice> P1;
    std::vector<tCoste> tramo1 = Dijkstra(tren, origen, P1);

    std::vector<vertice> P2;
    std::vector<tCoste> tramo2 = DijkstraInv(bus, destino, P2);

    s.minimo = std::min(tramo1[cambio1] + tramo2[cambio1], tramo1[cambio2] + tramo2[cambio2]);

    vertice cambio;
    if((tramo1[cambio1] + tramo2[cambio1]) < (tramo1[cambio2] + tramo2[cambio2])){
        cambio = cambio1;
    }
    else{
        cambio = cambio2;
    }

    //RUTA 
    s.camino.insert(camino.begin(), Destino);
    for(auto i = destino; i != cambio; i = P1[i]){
        s.camino.insert(camino.begin(), P1[i]);
    }
    for(auto i = cambio; i != origen; i = P2[i]){
        s.camino.insert(camino.begin(), P2[i]);
    }

    return s;
}

/* Ejericio 8: "UN SOLO TRANSBORDO, POR FAVOR”. Este es el título que reza en tu 
flamante compañía de viajes. Tu publicidad explica, por supuesto, que ofreces viajes 
combinados de TREN y/o AUTOBÚS (es decir, viajes en tren, en autobús, o usando 
ambos), entre N ciudades del país, que ofreces un servicio inmejorable, precios muy 
competitivos, y que garantizas ante notario algo que no ofrece ninguno de tus 
competidores: que en todos tus viajes COMO MÁXIMO se hará un solo transbordo 
(cambio de medio de transporte). 
Bien, hoy es 1 de Julio y comienza la temporada de viajes. 
¡Qué suerte! Acaba de aparecer un cliente en tu oficina. Te explica que quiere viajar 
entre dos ciudades, Origen y Destino, y quiere saber cuánto le costará. 
Para responder a esa pregunta dispones de dos grafos de costes directos (matriz de 
costes) de viajar entre las N ciudades del país, un grafo con los costes de viajar en tren y 
otro en autobús. 
Implementa un subprograma que calcule la tarifa mínima en estas condiciones. 
Mucha suerte en el negocio, que la competencia es dura. */

template <typename tCoste>

tCoste ejercicio8(const GrafoP<tCoste> bus, const GrafoP<tCoste> tren, typedef GrafoP<tCoste>::Vertice Origen, typedef GrafoP<tCoste>::vertice Destino){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N = bus.numVert();
    static const INF = GrafoP<tCoste>::INFINITO;

    std::vector<vertice> P;

    std::vector<tCoste> bus_origen = Djikstra(bus, Origen ,P);
    std::vector<tCoste> bus_destino = DjikstraInv(bus, Origen ,P);

    std::vector<tCoste> tren_origen = Djikstra(tren, Origen ,P);
    std::vector<tCoste> tren_destino = DjikstraInv(tren, Origen ,P);


    tCoste minimo_directo = INF;
    //Directo
    minimo_directo = std::min(bus_origen[Destino], tren_origen[Destino]);

    tCoste minimo = INF;
    //Con maximo un trasbordo
    for(auto i = 0; i < bus_origen.size(); i++){
        minimo = std::min(minimo_directo, (bus_origen[i] + tren_destino[i]), (tren_origen[i] + bus_destino[i]));
    }

    return minimo;

}

/* Ejercicio 9: Se dispone de dos grafos que representan la matriz de costes para viajes en un 
determinado país, pero por diferentes medios de transporte (tren y autobús, por 
ejemplo). Por supuesto ambos grafos tendrán el mismo número de nodos, N. Dados 
ambos grafos, una ciudad de origen, una ciudad de destino y el coste del taxi para 
cambiar de una estación a otra dentro de cualquier ciudad (se supone constante e igual 
para todas las ciudades), implementa un subprograma que calcule el camino y el coste 
mínimo para ir de la ciudad origen a la ciudad destino. */

template <typename tCoste>

struct solucion{
    tCoste minimo;
    std::vector<typename GrafoP<tCoste>::vertice> camino;
}

solucion ejercicio9(typename GrafoP<tCoste>::vertice Origen, typename GrafoP<tCoste>::vertice Destino, tCoste taxi, const GrafoP<tCoste> tren, const GrafoP<tCoste> bus){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N = tren.numVert();
    static const INF = GrafoP<tCoste>::INFINITO;
    solucion s;

    //GRAFO UNIDO
    GrafoP<tCoste> global(N*2);
    for(vertice i = 0; i<N; i++){
        global[i][i+N] = global[N+i][i] = taxi;
        for(vertice j = 0; j < N; j++){
            global[i][j] = tren[i][j];
            global[i+N][j+N] = bus[i][j];
        }
    }

    //Hacemos floyd para calcular los costes minimos
    std::matriz<vertice> P;
    std::matriz<tCoste> global_floyd = Floyd(global, P);

    std::vector<tCoste> costes[] = {
        global_floyd[origen][destino],//TREN
        global_floyd[origen + N][destino + N],//BUS
        global_floyd[origen][destino + N],//TREN-BUS
        global_floyd[origen + N][destino]//BUS-TREN
    };

    solucion.s = std::min(costes);

    return solucion;

}


/*Ejercicio 10: Se dispone de tres grafos que representan la matriz de costes para viajes en un 
determinado país, pero por diferentes medios de transporte (tren, autobús y avión). Por 
supuesto los tres grafos tendrán el mismo número de nodos, N. 
Dados los siguientes datos: 
     los tres grafos, 
     una ciudad de origen, 
     una ciudad de destino, 
     el coste del taxi para cambiar, dentro de una ciudad, de la estación de tren a la 
    de autobús o viceversa (taxi-tren-bus) y 
     el coste del taxi desde el aeropuerto a la estación de tren o la de autobús, o 
    viceversa (taxi-aeropuerto-tren/bus) 
y asumiendo que ambos costes de taxi (distintos entre sí, son dos costes diferentes) son 
constantes e iguales para todas las ciudades, implementa un subprograma que calcule el 
camino y el coste mínimo para ir de la ciudad origen a la ciudad destino. */

template <typename tCoste>

tCoste ejercicio10(typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino, const tCoste coste_tren_bus, const tCoste coste_aero, const GrafoP<tCoste> &tren, const GrafoP<tCoste> &bus, const GrafoP<tCoste> &avion){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N = tren.numVert();

    GrafoP<tCoste> global(N*3);

    //GRAFO GLOBAL
    for(vertice i = 0; i < N; i++){
        global[i][i+N] = global[i+N][i] = coste_tren_bus;
        global[i][i+2*N] = global[i+2*N][i] = global[i+N][i+2*N] = global[i+2*N][i+N] = coste_aero;

        for(vertice j = 0; j < N; j++){
            global[i][j] = tren[i][j];
            global[i+N][j+N] = bus[i][j];
            global[i+2*N][j+2*N] = avion[i][j];
        }
    }

    std::matriz<vertice> P;
    std::matriz<tCoste> global_floyd = Floyd(global, P);

    std::vector<tCoste> costes[] = {
        global_floyd[origen][destino],
        global_floyd[origen + N][destino + N],
        global_floyd[origen + N*2][destino + N*2],
        global_floyd[origen][destino + N],
        global_floyd[origen][destino + N*2],
        global_floyd[origen +N][destino],
        global_floyd[origen + N][destino + N*2],
        global_floyd[origen + N*2][destino],
        global_floyd[origen + N*2][destino + N]
    }

    return std::min(costes);
}

/*Ejercicio 11: Disponemos de tres grafos (matriz de costes) que representan los costes directos de 
viajar entre las ciudades de tres de las islas del archipiélago de las Huríes (Zuelandia). 
Para poder viajar de una isla a otra se dispone de una serie de puentes que conectan 
ciudades de las diferentes islas a un precio francamente asequible (por decisión del 
Prefecto de las Huríes, el uso de los puentes es absolutamente gratuito). 
Si el alumno desea simplificar el problema, puede numerar las N1 ciudades de la isla 
1, del 0 al N1-1, las N2 ciudades de la isla 2, del N1 al N1+N2-1, y las N3 de la última, del 
N1+ N2 al N1+N2+ N3-1. 
Disponiendo de las tres matrices de costes directos de viajar dentro de cada una de 
las islas, y la lista de puentes entre ciudades de las mismas, calculad los costes mínimos 
de viajar entre cualesquiera dos ciudades de estas tres islas. 
¡¡¡ QUE DISFRUTÉIS EL VIAJE !!!*/

template <typename tCoste>

struct puente{
    typedef typename GrafoP<tCoste>::vertice ciudad;
    ciudad a, b;
}

matriz<tCoste> ejercicio11(const std::vector<puente> &puentes, const GrafoP<tCoste> &G1, const GrafoP<tCoste> &G2, const GrafoP<tCoste> &G3){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size N1 = G1.numVert(), N2 = G3.numVert(), N3 = G3.NumVert();

    GrafoP<tCoste> global(N1+N2+N3);

    for(vertice i = 0; i < N1; i++){
        for(vertice j = 0; j < N1; j++){
            global[i][j] = G1[i][j];
        }
    }

    for(vertice i = 0; i < N2; i++){
        for(vertice j = 0; j < N2; j++){
            global[i+N1][j+N1] = G2[i][j];
        }
    }

    for(vertice i = 0; i < N3; i++){
        for(vertice j = 0; j < N3; j++){
            global[i+N1+N2][j+N1+N2] = G2[i][j];
        }
    }

    for(auto i = 0; i < puentes.size(); i++){
        global[puentes[i].a][puentes[i].b] = global[puentes[i].b][puentes[i].a] = 0;
    }

    std::matriz<vertice> P;

    return Floyd(global, P);
}

/*Ejercicio 12: El archipiélago de Grecoland (Zuelandia) está formado únicamente por dos islas, 
Fobos y Deimos, que tienen N1 y N2 ciudades, respectivamente, de las cuales C1 y C2
ciudades son costeras (obviamente C1 ≤ N1 y C2 ≤ N2). Se desea construir un puente 
que una ambas islas. Nuestro problema es elegir el puente a construir entre todos los 
posibles, sabiendo que el coste de construcción del puente se considera irrelevante. Por 
tanto, escogeremos aquel puente que minimice el coste global de viajar entre todas las 
ciudades de las dos islas, teniendo en cuenta las siguientes premisas: 
    1. Se asume que el coste viajar entre las dos ciudades que una el puente es 0. 
    2. Para poder plantearse las mejoras en el transporte que implica la construcción de 
    un puente frente a cualquier otro, se asume que se realizarán exactamente el 
    mismo número de viajes entre cualesquiera ciudades del archipiélago. Por 
    ejemplo, se considerará que el número de viajes entre la ciudad P de Fobos y la 
    Q de Deimos será el mismo que entre las ciudades R y S de la misma isla. Dicho 
    de otra forma, todos los posibles trayectos a realizar dentro del archipiélago son 
    igual de importantes. 
Dadas las matrices de costes directos de Fobos y Deimos y las listas de ciudades 
costeras de ambas islas, implementa un subprograma que calcule las dos ciudades que 
unirá el puente.*/

struct puente{
    typedef typename GrafoP<tCoste>::vertice ciudad;
    ciudad a, b;
}

template <typename tCoste>

puente ejercicio12(std::vector<typename GrafoP<tCoste>::vertice> costeras_fobos, std::vector<typename GrafoP<tCoste>::vertice> costeras_deimo, const GrafoP<tCoste> fobos, const GrafoP<tCoste> deimos){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N_fobos = fobos.numVert(), N_deimos = fobos.numVert();
    static const INF = GrafoP<tCoste>::INFINITO;

    std::matriz<vertice> P1;
    std::matriz<tCoste> fobos_floyd = Floyd(fobos, P1);

    std::matriz<vertice> P2;
    std::matriz<tCoste> deimos_floyd = Floyd(deimos, P2);

    //Buscamos la ciudad costera con menos tCoste para luego unirla a la de Deimos
    tCoste coste_min_fobos = INF;
    vertice mejor_costera_fobos;

    for(vertice i = 0; i < N_fobos; i++){
        for(auto j = 0; j < costeras_fobos.size(); j++){
            if(i = costeras_fobos[j]){
                tCoste aux =0;
                for(vertice k = 0; k < N_fobos; k++){
                    aux += aux, fobos_floyd[j][k];
                }
                if(aux < coste_min_fobos){
                    coste_min_fobos = aux;
                    mejor_costera_fobos = j;
                }
            }
        }
    }

    //Buscamos la ciudad costera con menos tCoste para luego unirla a la de Foos
    tCoste coste_min_deimos = INF;
    vertice mejor_costera_deimos;

    for(vertice i = 0; i < N_Deimos; i++){
        for(auto j = 0; j < costeras_deimos.size(); j++){
            if(i = costeras_deimos[j]){
                tCoste aux =0;
                for(vertice k = 0; k < N_deimos; k++){
                    aux += aux, deimos_floyd[j][k];
                }
                if(aux < coste_min_deimos){
                    coste_min_deimos = aux;
                    mejor_costera_deimos = j;
                }
            }
        }
    }

    Puente p;
    p.a = mejor_costera_fobos;
    p.b = mejor_costera_deimos;

    return p;
    
}

/*Ejercicio 13: El archipiélago de las Huríes acaba de ser devastado por un maremoto de 
dimensiones desconocidas hasta la fecha. La primera consecuencia ha sido que todos y 
cada uno de los puentes que unían las diferentes ciudades de las tres islas han sido 
destruidos. En misión de urgencia las Naciones Unidas han decidido construir el 
mínimo número de puentes que permitan unir las tres islas. Asumiendo que el coste de 
construcción de los puentes implicados los pagará la ONU, por lo que se considera 
irrelevante, nuestro problema es decidir qué puentes deben construirse. Las tres islas de 
las Huríes tienen respectivamente N1, N2 y N3 ciudades, de las cuales C1, C2 y C3 son 
costeras (obviamente C1 ≤ N1 , C2 ≤ N2 y C3 ≤ N3) . Nuestro problema es elegir los 
puentes a construir entre todos los posibles. Por tanto, escogeremos aquellos puentes 
que minimicen el coste global de viajar entre todas las ciudades de las tres islas, 
teniendo en cuenta las siguientes premisas: 
    1. Se asume que el coste viajar entre las ciudades que unan los puentes es 0. 
    2. La ONU subvencionará únicamente el número mínimo de puentes necesario 
    para comunicar las tres islas.
    3. Para poder plantearse las mejoras en el transporte que implica la construcción de 
    un puente frente a cualquier otro, se asume que se realizarán exactamente el 
    mismo número de viajes entre cualesquiera ciudades del archipélago. Dicho de 
    otra forma, todos los posibles trayectos a realizar dentro del archipiélago son 
    igual de importantes. 
Dadas las matrices de costes directos de las tres islas y las listas de ciudades costeras 
del archipiélago, implementad un subprograma que calcule los puentes a construir en las 
condiciones anteriormente descritas. */

struct puente{
    typedef typename GrafoP<tCoste>::vertice vertice;
    vertice a, b;
}

std::vector<puente> ejercicio13(const std::vector<vertice> costeras_i1, const std::vector<vertice> costeras_i2, const std::vector<vertice> costeras_i3, const GrafoP<tCoste> G1, const GrafoP<tCoste> G2, const GrafoP<tCoste> G3){
    typedef typename GrafoP<tCoste>::vertice vertice;
    static const INF = GrafoP<tCoste>::INFINITO;
    const size_t n_i1 = G1.numVert(), n_i2 = G2.numvert(), n3_i3 = G3.numVert();

    std::matriz<vertice> P1;
    std::matriz<tCoste> i1_floyd = Floyd(G1, P1);

    std::matriz<vertice> P2;
    std::matriz<tCoste> i2_floyd = Floyd(G2, P2);

    std::matriz<vertice> P3;
    std::matriz<tCoste> i3_floyd = Floyd(G3, P3);

    //Isla 1
    tCoste mejor_coste = INF;
    vertice mejor_ciudad_i1;

    for(auto i = 0; i < costeras_i1.size(); i++){
        tCoste aux;
        for(auto j=0; j < n_i1; j++){
            aux += i1_floyd[i][j]; 
        }
        if(aux < mejor_coste){
            mejor_coste = aux;
            mejor_ciudad_i1 = i;
        }
    }

    //Isla 2
    tCoste mejor_coste = INF;
    vertice mejor_ciudad_i2;

    for(auto i = 0; i < costeras_i2.size(); i++){
        tCoste aux;
        for(auto j=0; j < n_i2; j++){
            aux += i2_floyd[i][j]; 
        }
        if(aux < mejor_coste){
            mejor_coste = aux;
            mejor_ciudad_i2 = i;
        }
    }

    //Isla d3
    tCoste mejor_coste = INF;
    vertice mejor_ciudad_i3;

    for(auto i = 0; i < costeras_id3.size(); i++){
        tCoste aux;
        for(auto j=0; j < n_i3; j++){
            aux += id3_floyd[i][j]; 
        }
        if(aux < mejor_coste){
            mejor_coste = aux;
            mejor_ciudad_id3 = i;
        }
    }

    puente p1;
    p1.a = mejor_ciudad_i1;
    p1.b = mejor_ciudad_i2;

    puente p2;
    p2.a = mejor_ciudad_i2;
    p2.b = mejor_ciudad_i3;

    puente dos_puentes[2] = {p1, p2};

    return dos_puentes;
}

/* 5.La nueva compañía de telefonía RETEUNI3 tiene que conectar entre sí, con fibra
óptica, todas y cada una de las ciudades del país. Partiendo del grafo que representa las
distancias entre todas las ciudades del mismo, implementad un subprograma que
calcule la longitud mínima de fibra óptica necesaria para realizar dicha conexión. 
*/

double ejercicio5(const GrafoP<tCoste> &grafo){
    typedef typename GrafoP<tCoste::vertice vertice;
    const size_t N = grafo.numVert();

    GrafoP<tCoste> grafo_prim = Prim(grafo);

    double solucion = 0;
    for(vertice i = 0; i < N; i++){
        for(vertice j = 0; j < N; j++){
            solucion += grafo_prim[i][j];
        }
    }

    return solucion;
}

/*6. La empresa EMASAJER S.A. tiene que unir mediante canales todas las ciudades del
valle del Jerte (Cáceres), teniendo en cuenta las siguientes premisas:
− El coste de abrir cada nuevo canal es casi prohibitivo, luego la solución final debe
tener un número mínimo de canales.
− El Ministerio de Fomento nos subvenciona por m3 /sg de caudal, luego el conjunto
de los canales debe admitir el mayor caudal posible, pero por otra parte, el coste
de abrir cada canal es proporcional a su longitud, por lo que el conjunto de los
canales también debería medir lo menos posible. Así pues, la solución óptima
debería combinar adecuadamente ambos factores.
Dada la matriz de distancias entre las diferentes ciudades del valle del Jerte, otra
matriz con los diferentes caudales máximos admisibles entre estas ciudades teniendo en
cuenta su orografía, la subvención que nos da Fomento por m3 /sg. de caudal y el coste
por km. de canal, implementen un subprograma que calcule qué canales y de qué
longitud y caudal deben construirse para minimizar el coste total de la red de canales.
*/

template <typename tCoste>

GrafoP<tCoste> ejercicio6(const GrafoP<tCoste> &distancias, const GrafoP<size_t> &caudal, double subvenecion, tCoste coste){
    typedef typename GrafoP<tCoste>::vertice vertice;

    for(vertice i = 0; i < N; i++){
        for(vertice j = 0; j < N; j++){
            if(distancia[i][j] != INF && caudal[i][j] != INF){
                distancias[i][j] = (distancias[i][j]*coste) - (caudal[i][j]*subvencion);
            }
        }
    }

    return Prim(distancias);

    
}

/*7. El archipiélago de Grecoland (Zuelandia) está formado únicamente por dos islas,
Fobos y Deimos, que tienen N1 y N2 ciudades, respectivamente, de las cuales C1 y C2
ciudades son costeras (obviamente C1 ≤ N1 y C2 ≤ N2 ). Se dispone de las coordenadas
cartesianas (x, y) de todas y cada una de las ciudades del archipiélago. El huracán
Isadore acaba de devastar el archipiélago, con lo que todas las carreteras y puentes
construidos en su día han desaparecido. En esta terrible situación se pide ayuda a la
ONU, que acepta reconstruir el archipiélago (es decir volver a comunicar todas las
ciudades del archipiélago) siempre que se haga al mínimo coste.
 De cara a poder comparar costes de posibles reconstrucciones se asume lo
siguiente:
1. El coste de construir cualquier carretera o cualquier puente es proporcional a su
longitud (distancia euclídea entre las poblaciones de inicio y fin de la carretera o
del puente).
2. Cualquier puente que se construya siempre será más caro que cualquier carretera
que se construya.
 De cara a poder calcular los costes de VIAJAR entre cualquier ciudad del
archipiélago se considerará lo siguiente:
1. El coste directo de viajar, es decir de utilización de una carretera o de un puente,
coincidirá con su longitud (distancia euclídea entre las poblaciones origen y
destino de la carretera o del puente).
 En estas condiciones, implementa un subprograma que calcule el coste mínimo
de viajar entre dos ciudades de Grecoland, origen y destino, después de haberse
reconstruido el archipiélago, dados los siguientes datos:
1. Lista de ciudades de Fobos representadas mediante sus coordenadas cartesianas.
2. Lista de ciudades de Deimos representadas mediante sus coordenadas
cartesianas.
3. Lista de ciudades costeras de Fobos.
4. Lista de ciudades costeras de Deimos.
5. Ciudad origen del viaje.
6. Ciudad destino del viaje.
*/

struct coord{
    double x, y
};

struct puente{
    tCoste coste;
    vertice a, b;
}

double distaciaEuclidea(coord c1, coord c2){
    return std::sqrt(std::pow((c2.x - c1.x), 2) + std::pow((c2.y - c1.y), 2));
}

template <typename tCoste>
tCoste Grecoland(const std::vector<typename GrafoP<coord>::vertice> ciudades_fobos, 
                 const std::vector<typename GrafoP<coord>::vertice> ciudades_deimos,
                 const std::vector<typename GrafoP<coord>::vertice> costeras_fobos,
                 const std::vector<typename GrafoP<coord>::vertice> costeras_deimos,
                 const typename GrafoP<tCoste>::vertice origen,
                 const typename GrafoP<tCoste>::vertice destino
) {

    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t ciudad_f = ciudades_fobos.size(), ciudades_d = ciudades_deimos.size(), costeras_f = costeras_fobos.size(), costeras_d = costeras_deimos.size();
    
    GrafoP<tCoste> grafo_fobos;

    for(vertice i = 0; i < ciudad_f; i++){
        for(vertice j = 0; j < ciudad_f; j++){
            if(i == j){
                grafos_fobos = 0;
            }
            else{
                grafos_fobos = distanciaEuclidea(ciudades_fobos[i], ciudades_fobos[j]);
            }
        }
    }

    GrafoP<tCoste> grafo_deimos;

    for(vertice i = 0; i < ciudad_d; i++){
        for(vertice j = 0; j < ciudad_d; j++){
            if(i == j){
                grafos_deimos[i][j] = 0;
            }
            else{
                grafos_deimos[i][j] = distanciaEuclidea(ciudades_deimos[i], ciudades_deimos[j]);
            }
        }
    }

    //Hacemos Prim
    GrafoP<tCoste> fobos_prim = Prim(grafo_fobos);
    GrafoP<tCoste> fobos_deimos = Prim(grafo_deimos);

    //SuperGrafo
    GrafoP<tCoste> global(fobos_prim + fobos_deimos);

    for(vertice i = 0; i < fobos_prim.numVert(); i++){
        for(vertice j = 0; j < fobos_prim.numVert(); j++){
            if(i == j){
                global[i][j] = 0;
            }  
            else{
                global[i][j] = fobos_prim[i][j];
            }
        }
    }

    for(vertice i = 0; i < fobos_deimos.numVert(); i++){
        for(vertice j = 0; j < fobos_deimos.numVert(); j++){
            if(i == j){
                global[i + fobos_prim.numVert()][j + fobos_prim.numVert()] = 0;
            }  
            else{
                global[i + fobos_prim.numVert()][j + fobos_prim.numVert()] = fobos_deimos[i][j];
            }
        }
    }


    //Hacemos el puente

    puente p;
    p.coste = INF;
    tCoste aux = INF;

    for(vertice i = 0; i < costeras_fobos.size(); i++){
        for(vertice j = 0; j < costeras_deimos.size(); j++){
            if(distanciaEuclidea(costeras_fobos[i], costeras_deimos[i]) < aux){
                aux = distanciaEuclidea(costeras_fobos[i], costeras_deimos[i]);
                p.coste = aux;
                p.a = costeras_fobos[i];
                p.b = costeras_deimos[i];
            }
        }
    }

    global[p.a][p.b + fobos.numVert()] = p.coste;
    global[p.b + fobos.numVert()][p.a] = p.coste;

    std::vector<vertice> P;
    vector<tCoste> solucion = Djikstra(global, origen, P);

    return solucion[destino];

}

/*Un repartidor de una empresa de distribución de bebidas tiene que visitar a todos sus
clientes cada día. Pero, al comenzar su jornada de trabajo, no conoce qué cantidad de bebidas
tiene que servir a cada cliente, por lo que no puede planificar una ruta óptima para visitarlos a
todos. Por tanto, nuestro repartidor decide llevar a cabo la siguiente estrategia:
 El camión parte del almacén con la máxima carga permitida rumbo a su cliente más
próximo.
 El repartidor descarga las cajas de bebidas que le pide el cliente. Si no tiene suficientes
cajas en el camión, le entrega todas las que tiene. Este cliente terminará de ser servido en
algún otro momento a lo largo del día, cuando la estrategia de reparto vuelva a llevar al
repartidor hasta él.
 Después de servir a un cliente:
o Si quedan bebidas en el camión, el repartidor consulta su sistema de navegación
basado en GPS para conocer la ruta que le lleva hasta su cliente más próximo
pendiente de ser servido.
o Si no quedan bebidas en el camión, vuelve al almacén por el camino más corto y
otra vez carga el camión completamente.
 Después de cargar el camión, el repartidor consulta su sistema de navegación y se va por
el camino más corto a visitar al cliente pendiente de ser servido más próximo.
Implementa un subprograma que calcule y devuelva la distancia total recorrida en un
día por nuestro repartidor, a partir de lo siguiente:
1. Grafo representado mediante matriz de costes con las distancias de los caminos directos
entre los clientes y entre ellos y la central.
2. Capacidad máxima del camión (cantidad de cajas de bebidas).
3. Asumiremos que existe una función int Pedido() que devuelve el número de cajas que
quedan por servir al cliente en el que se encuentra el repartidor.
*/

template <typename tCoste>

tCoste repartidor(const GrafoP<tCoste> grafo, double capacidad_camion, typename GrafoP<tCoste>::Vertice almacen){
    typedef typename GrafoP<tCoste>::vertice vertice;
    static const INF = GrafoP<tCoste>::INFINITO;
    const size_t numero_clientes = G.numVert() - 1;

    std::vector<vertice> clientes_servidos;

    std::matriz<vertice> p;

    vertice posicion_actual = alamcen;
    tCoste distancia_total = 0;
    size_t num_servidos = 0;

    while(num_servidos != numero_clientes){
        std::vector<vertice> p;
        std::vector<tCoste> vector = Djikstra(grafo, posicion_actual, P);
        vertice minimo;

        for(vertice j = 0; j < numero_clientes + 1; j++){
            if(grafo[posicion_actual][j] < minimo){
                minimo = j;
            }
        }
        distancia_total += vector[minimo];
        posicion_actual = minimo;

        if(Pedido(posicion_actual) <= capacidad_camion){
            
        }
    }

}

/*
La capital de Zuelandia está alcanzando niveles de toxicidad muy elevados, por ello se ha
decretado el cierre a la ciudad como paso de tránsito hacia otras ciudades. (Para ir de una
ciudad a otra no se podrá pasar por C.Zuelandia, pero si se podrá ir si es residente de la misma
empleándola como ciudad destino u origen).
Implemente un subprograma que dada la capital y un grafo ponderado con los km de las
carreteras existentes entre las ciudades del país, nos devuelva los caminos resultantes de
nuestra nueva política “Sin pasar por la capital, por favor”.
*/

template <typename tCoste>

matriz<tCoste> Floyd_modificado(const GrafoP<tCoste> &G, matriz<typename GrafoP<tCoste>::vetice> P, typename GrafoP<tCoste>::vertice capital){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t n = g.numvert();
    matriz<tCoste> A(n);
    static const INF = GrafoP<tCoste>::INFINITO;

    P = matriz<vertice>(n);

    for(vertice i = 0; i < n; i++){
        A[i] = G[i];
        A[i][i] = 0;
        P[i] = vector<vertice>(n, i);
    }

    for(vertice k = 0; k < n; k++){
        for(vertice i = 0; i < n; i++){
            for(vertice j = 0; j < n; j++){
                tCoste ikj = std::sum(A[i][k], A[k][j]);
                if(ikj < A[i][j]){
                    if(k != capital){
                        A[i][j] = ikj;
                        P[i][j] = k;
                    }
                    else{
                        A[i][j] = INF;
                    }
                }
            }
        }
    }

    return A;
}



matriz<tCoste> toxico(typename GrafoP<tCoste>::vertice capital, const GrafoP<tCoste> &grafo){
    typedef typename GrafoP<tCoste>::Vertice vertice;
    static const INF = GrafoP<tCoste>::INFINITO;

    std::matriz<vertice> P;

    std::matriz<tCoste> solucion = Floyd(grafo, P, capital);

    return solucion;

}


/*La capital de Zuelandia está ultimamente mas toxica que tu novia. Ante esta situacion
el gobierno esta pensando en cerrar los accesos a la capital (excepto residentes).
Esto solo se hará si los nuevos costes de ir de una ciudad a otra no superan en mas de unos kilometros dados, 
a los costes antes de implementar la medida. Para ello nos dan los siguientes datos:
La capital de Zuelandia
El grafo con los kilometros de cada carretera del país
Los viajes diarios que se estima que se realizan entre pares de ciudades
El numero máximo del total de kilometros adicionales que se acepta realizar para implementar la medida

Implementa un subprograma que calcule y devuelva el numero de km adicionales que provocaria la implantacion 
de la medida anticontaminacion, y si debe implementarse dicha media o no */

struct solucion{
    bool medida;
    tCoste km;
}

matriz<tCoste> Floyd_modificado2(const GrrafoP<tCoste> &g, matriz<typename GrafoP<tCoste>::vertice> &P, double km_adicionales_max, typename GrafoP<tCoste>::vertice capital){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t n = g.numVert();
    matriz<tCoste> A(n);

    P = matriz<vertice>(n);
    for(vertice i = 0; i < n; i++){
        A[i] = g[i];
        A[i][i] = 0;
        P[i] = vector<vertice>(n, i);
    }

    for(vertice k = 0; k < n; k++){
        for(vertice i = 0; i < n; i++){
            for(vertice j = 0; j < n; j++){
                tCoste ikj = A[i][k] + A[k][j];
                if(ikj < A[i][j]){
                    if(ikj > km_adicionales-max && k == capital){
                        A[i][j] = INF;
                    }
                    else{
                        A[i][j] = ikj;
                        P[i] = k;
                    }
                }
            }
        }
    }

    return A;

}

solucion toxica2(typename GrafoP<tCoste>::vertice capital, const GrafoPt<tCoste> &g, matriz<size_t> viajes, double km_adicionales_max){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N = g.numvert();
    static const INF = GrafoP<tCoste>::INFINITO;

    matriz<vertice> P;
    matriz<tCoste> g_floyd = Floyd(g, P, km_adicionales_max, capital);

    tCoste aux;
    solucion s;
    for(vertice i = 0; i < N; i++){
        for (vertice j = 0 ; j < i ; j++){
            s.km += g_floyd[i][j] * viajes[i][j]; 
        }
    }

    if(s.km > km_adicionales_max){
        s.medida = false;
    }
    else{
        s.medida = true;
    }

    return solucion;

}


#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"


/*Transformar un arbol binario de tipo genérico, eliminando los descendientes propios de 
todos aquellos nodos cuyo contenido sea, al mismo tiempo, mayor o igual
que el de sus ascendientes propios y menor o igual que el de sus decendientes propios.
*/
template <typename T>
void transformarAbin(Abin<T>& A){
    transformarAbinRec(A.raiz(),A);
}

template <typename T>
void transformarAbinRec(c){
    if(n != Abin<T>::NODO_NULO){
        if(comprobarAntecesores && comprobarSucesores){
            eliminarNodo(n,A);
        }else{
            transformarAbinRec(A.hijoIzqdo(n),A);
            transformarAbinRec(A.hijoDrcho(n),A);
        }
    }
}

template <typename T>
bool comprobarAntecesores(typename Abin<T>::nodo n, Abin<T>& A){
    if(n == A.raiz(n)){
        return true;
    }else{
        return(A.elemento(A.padre(n)) <= A.elemento(n))
    }
}

template <typename T>
bool comprobarSucesores(typename Abin<T>::nodo n, Abin<T>& A){
    if(A.elemento(A.hijoIzqdo(n)) >= A.elemento(n) && A.elemento(A.hijoDrcho(n)) >= A.elemento(n))
        return true;
    else
        return false;
}

template <typename T>
void eliminarNodo(typename Abin<T>::nodo n, Abin<T>& A){
    if(esHoja(A.hijoIzqdo(n),A)){
        A.eliminarHijoIzqdo(n);
    }else{
        eliminarNodo(A.hijoIzqdo(n),A);
    }

    if(esHoja(A.hijoDrcho(n),A)){
        A.eliminarHijoDrcho(n);
    }else{
        eliminarNodo(A.hijoDrho(n),A);
    }
}


template <typename T>
bool esHoja(typename Abin<T>::nodo n, Abin<T>& A){
    if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDcho(n) == Abin<T>::NODO_NULO)
        return true;
    else 
        return false;
}