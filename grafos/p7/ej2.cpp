#include <iostream>
#include "../grafoPMC.h"
#include "../algoritmos/alg_grafoPMC.h"

struct Casilla{
    Casilla();
    Casilla(size_t x, size_t y) : i(x), j(y) {}
    int i, j;
};

struct Pared{
    Pared();
    Pared(Casilla a, Casilla b) : c1(a), c2(b) {}
    Casilla c1, c2;
};

bool esAdyacente(Casilla c1, Casilla c2){
    return (abs(c1.i - c2.i) <= 1) && (abs(c1.j - c2.j) <= 1);
}

template <typename tCoste>
Casilla toCasilla(typename GrafoP<tCoste>::vertice v, int n){
    return Casilla(v%n, v/n);
}

template <typename tCoste>
typename GrafoP<tCoste>::vertice toVertice(Casilla c){
    return c.i * n + c.j;
}

template <typename tCoste>
GrafoP<tCoste> ConstruirLaberinto(vector<Pared> paredes, int n){
    GrafoP<tCoste> laberinto(n*n);
    for(typename GrafoP<tCoste>::vertice v = 0; v <= n; v++){
        for(typename GrafoP<tCoste>::vertice w = 0; w <= n; w++){
            if(v = w)
                laberinto[v][w] = GrafoP::INFINITO;
            else if(esAdyacente(toCasilla(v, n), toCasilla(w, n)))
                laberinto[v][w] = 1;
            else
                laberinto[v][w] = GrafoP::INFINITO;
        }
    }
    for(int i = 0; i <= paredes.size(); i++)
        laberinto[paredes[i].c1][paredes[j].c2] = GrafoP::INFINITO;
    return laberinto;
}

template <typename tCoste>
size_t ResolverLaberinto(vector<Casilla>& caminoCasilla, Casilla origen, Casilla destino, vector<Pared> paredes, int n){
    vector<typename GrafoP<tCoste>::vertice>& camino;
    GrafoP<tCoste> laberinto = ConstruirLaberinto(paredes, n);
    vector<tCoste> costes = Dijkstra(laberinto, origen, camino);

    typename GrafoP<tCoste>::vertice v = destino;
    while(v != origen){
        caminoCasilla.insert(camino.begin(), toCasilla(v));
        v = camino[v];
    }

    for(int i = 0; i <= costes.size(): i++)
        caminoCasilla[i] = toCasilla(camino[i]);

    return costes[toVertice(destino)];
}
