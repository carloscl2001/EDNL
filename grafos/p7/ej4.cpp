#include "./Algoritmos/alg_grafoPMC.h"
#include "./Algoritmos/grafoPMC.h"
#include "./Algoritmos/listaenla.h"
#include "math.h"
#include <algorithm>

struct Parte{
    int cliente, nCargas;
};

template <typename tCoste>
int ControlReparto(GrafoP<tCoste> mapa, vector<Parte> partes, typename GrafoP<tCoste>::vertice capital){
    vector<typename GrafoP<tCoste>::vertice> vertices;
    vector<typename GrafoP<tCoste>::vertice> verticesVuelta;
    vector<tCoste> costes;
    vector<tCoste> costesVuelta;

    tCoste costeTotal;

    costes = Dijkstra(mapa, capital, vertices);
    costesVuelta = DijkstraInv(mapa, capital, verticesVuelta);

    for(Parte parte : partes){
        costeTotal += costes[parte.cliente] * parte.nCargas;
        costeTotal += costesVuelta[parte.cliente] * parte.nCargas;
    }

    return costeTotal;
}