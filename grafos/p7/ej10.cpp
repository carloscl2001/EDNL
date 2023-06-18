#include "./Algoritmos/alg_grafoPMC.h"
#include "./Algoritmos/grafoPMC.h"
#include "./Algoritmos/listaenla.h"
#include "math.h"

template <typename tCoste>
tCoste calcularViaje(
    GrafoP<tCoste> tren, 
    GrafoP<tCoste> bus, 
    GrafoP<tCoste> avion, 
    tCoste trenBus, 
    tCoste taxiAeropuerto,
    typename GrafoP<tCoste>::vertice origen, 
    typename GrafoP<tCoste>::vertice destino,
    vector<typename GrafoP<tCoste>::vertice> vCamino
){
    typedef typename GrafoP<tCoste> vertice;
    typedef GrafoP<tCoste>::INFINITO INFINITO;

    vector<tCoste> cMinimo;
    vector<vertice> vMinimo;
    tCoste costeTotal;

    int n = tren.numVert();
    GrafoP<Tramo> minimos(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            minimos[i][j] = bus[i][j];
        }
    }

    for(int i=n; i<2*n; i++){
        for(int j=n; j<2*n; j++){
            minimos[i][j] = tren[i][j];
        }
    }

    for(int i=2*n; i<3*n; i++){
        for(int j=2*n; j<3*n; j++){
            minimos[i][j] = avion[i][j];
        }
    }

    for(int i=0; i<n; i++){
        minimos[i][2*n + i] = trenBus;
        minimos[i][3*n + i] = taxiAeropuerto;
        minimos[2*n + i][i] = trenBus;
        minimos[2*n + i][3*n + i] = taxiAeropuerto;
        minimos[3*n + i][i] = taxiAeropuerto;
        minimos[3*n + i][2*n + i] = taxiAeropuerto; 
    }
   
    cMinimo = Dijkstra(minimos, origen, vMinimo);

    for(vertice v = destino; v != origen; v = vMinimo[v]){
        vCamino.insert(v.begin(); v);
        costeTotal += cMinimo[v];
    }

    return costeTotal;
}