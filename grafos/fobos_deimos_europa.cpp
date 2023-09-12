#include <iostream>
#include <cmath>
#include "grafoPMC.h"


using namespace std;

struct ciudad{
    double cx;
    double cy;
};

template <typename tCoste> 
struct puente{
    GrafoP<tCoste>::vertice c1, c2;
};

template <typename tCoste> 
struct solucion{
    matriz<tCoste> m_solucion_;
    vector<puente> v_solucion;
};

double distanciaEuclidea(ciudad c1, ciudad c2)
{
    return std::sqrt(std::pow((c2.cx - c1.cx), 2) + std::pow((c2.cy - c1.cy), 2));
}

template <typename tCoste> 
solucion funcion(vector<ciudad> c_fobos, 
                vector<ciudad> c_deimos,
                vector<ciudad> c_europa,
                tCoste coste_carretera, tCoste coste_carretera_l,
                tCoste coste_puente, tCoste coste_puente_l)
{
    typedef GrafoP<tCoste>::vertice vertice;
    
    //Montamos los 3 grtafos por separados, y le damos la posibilida de crear todas las carreteras posibles 

    grafoP<tCoste> Fobos (c_fobos.size());
    grafoP<tCoste> Deimos (c_deimos.size());
    grafoP<tCoste> Europa (c_europa.size());


    for(vertice i = 0; G.numVert(); i++){
        for(vertice j=0; G.numVert();j++){
            if(i < Fobos.size()){
                if(j < Fobos.size()){ // si i es de Fobos y j tbn es Deimos

                    G[i][j] = distanciaEuclidea(Fobos[i],Fobos[j]) * unidadCarretera + costeCarretera;

                }else{

                    if(j < Fobos.size() + Deimos.size()){ // si I es de Fobos y j es de Deimos

                         G[i][j] = distanciaEuclidea(Fobos[i],Deimos[j]) * unidadPuente + costePuente;
                         
                    }else{//si no es de Europa
                        G[i][j] = distanciaEuclidea(Fobos[i],Europa[j]) * unidadPuente + costePuente;
                    }

                }
            }else if(i < Fobos.size() + Deimos.size()){ //si i es Deimos

                if(j < Fobos.size()){ // si i es de Fobos y j tbn es Deimos

                    G[i][j] = distanciaEuclidea(Deimos[i],Fobos[j]) * unidadPuente + costePuente;

                }else{
                    if(j < Fobos.size() + Deimos.size()){ // si I es de Fobos y j es de Deimos

                         G[i][j] = distanciaEuclidea(Deimos[i],Deimos[j]) * unidadCarretera + costeCarretera;

                    }else{//si jo es de Europa

                        G[i][j] = distanciaEuclidea(Deimos[i],Europa[j]) * unidadPuente + costePuente;

                    }
                }
            }else{
                if(j < Fobos.size()){ // si i es de Fobos y j tbn es Deimos

                    G[i][j] = distanciaEuclidea(Europa[i],Fobos[j]) * unidadPuente + costePuente;

                }else{
                    if(j < Fobos.size() + Deimos.size()){ // si I es de Fobos y j es de Deimos

                         G[i][j] = distanciaEuclidea(Europa[i],Deimos[j])  * unidadPuente + costePuente;

                    }else{//si jo es de Europa

                        G[i][j] = distanciaEuclidea(Europa[i],Europa[j])  * unidadCarretera + costeCarretera;
                    }
                }
            }
        }
    
    }

    //Montamos el superGrafo para crear todos los puentes
    size_t N = c_fobos.size() + c_deimos.size() + c_europa.size();

    grafoP<tCoste> gSolucion (N);

    for(vertice i = 0; i < c_fobos.size(); i++){
        for(vertice i = 0; i < c_fobos.size(); i++){
            gSolucion = 
        }
    }
};
