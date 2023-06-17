#include "./Algoritmos/alg_grafoPMC.h"
#include "./Algoritmos/grafoPMC.h"
#include "./Algoritmos/listaenla.h"
#include "math.h"
#include <algorithm> 

template <typename tCoste>
struct Ciudad{
    Ciudad(int i, int c) : id(i), coste(c) {}
    int id;
    tCoste coste;
};

template <typename tCoste>
tCoste Distribucion(vector<size_t>& cantidadCiudad, typename GrafoP<tCoste>::vertice origen, int suministro, matriz<tCoste> mCiudades, const vector<size_t> capacidad, vector<float> subvencion){
    GrafoP<tCoste> ciudades(ciudades.dimension());
    int n = sqrt(ciudades.dimension());
    
    vector<typename GrafoP<tCoste>::vertice>& vertices;
    vector<tCoste> costeCiudad;
    vector<Ciudad> ciudadOrdenado;

    tCoste costoTotal = 0;
    

    for(typename GrafoP<tCoste>::vertice v = 0; v <= n; v++){
        for(typename GrafoP<tCoste>::vertice w = 0; w <= n; w++){
            ciudades[v][w] = mCiudades[v][w];
        }
    }

    costeCiudad = Dijkstra(ciudades, origen, vertices);
    for(int i = 0; i < costeCiudad.size(); i++){
        costeCiudad[i] = costeCiudad[i] - subvencion[i]*costeCiudad[i];
        ciudadOrdenado[i] = Ciudad(i, costeCiudad[i]);
    }

    std::sort(ciudadOrdenado.begin(), ciudadOrdenado.end(), [](Ciudad a, Ciudad b) -> {
        return a.coste < b.coste;
    })
    
    for(int i = 0; i < ciudadOrdenado.size() && suministro > 0; i++){
        if(capacidad[ciudadOrdenado[i].id] < suministro)
            cantidadCiudad[ciudadOrdenado[i].id] = suministro;
        else
            cantidadCiudad[ciudadOrdenado[i].id] = capacidad[ciudadOrdenado.id];
        suministro -= cantidad[ciudadOrdenado[i].id];
        costeTotal += ciudadOrdenado[i].coste;
    }

    return costeTotal;
}