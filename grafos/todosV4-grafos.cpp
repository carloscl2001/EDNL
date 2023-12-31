#include <iostream>
#include <cassert>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "arbol.h"
#include "abin_E-S.h"
#include "alg_grafoPMC.h"
#include "matriz.h"
#include "implementacion/alg_grafoPMC.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;



/*
\\--------------------------------------PRACTICA 6 ------------------------------------------------------------------

Se necesita hacer un estudio de las distancias mínimas necesarias para viajar entre
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
GrafoP<tCoste> ejercicio1(GrafoP<tCoste> Grafo, const std::vector<bool> &ciudades_tomadas, const matriz<bool> &carreteras_cortadas, typename GrafoP<tCoste>::Vertice capital){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N = Grafo.NumVert();
    static const tCoste INF = GrafoP<tCoste>::INFINITO;

    for(int i = 0; i < N; i++){
        if(ciudades_tomadas[i]){
            for(int j = 0; j < N; j++){
                Grafo[i][j] = Grafo[j][i] = INF;
                if(carreteras_cortadas[i][j])
                    Grafo[i][j] = INF;
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

//--------------------------------------PRACTICA 7 ------------------------------------------------------------------
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

//PARA HACER







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
template <typename tCoste>
struct solucion{
    std::vector<size_t> cantidad[N];
    tCoste coste_total;
};

template <typename tCoste>
solucion distribuir(const GrafoP<tCoste>::vertice origen, size_t cantidad, const std::vector<size_t> &capacidad_almacen, const std::vector<double> &subvencion, const GrafoP<tCoste> &G){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N = G.NumVert();
    static const tCoste INF = GrafoP<tCoste>::INFINITO;
    matriz<tCoste> mC;
    matriz<vertice> mV;

    mC = Floyd(G, mV);

    for(size_t i = 0; i < N; i++){
        mC[i][i] = INF;
        for(size_t j = 0; j < N; j++){
            mC[i][j] *= subvencion[j];
        }
    }

    vertice ubicacion;
    ubicacion = origen;
    solucion sol{};
    while (cantidad != 0)
    {
        vertice min;
        int tCosteAux = INF;
        int capacidad_dejada = 0;
        for(int j = 0; j < N; j++){
            if(tCosteAux > mC[ubicacion][j]){
                min = j;
                tCosteAux = mC[ubicacion][j];
            }
        }
        
        if(capacidad_almacen[min] <= cantidad){
            cantidad -= capacidad_almacen[min];
            sol.cantidad[min] = capacidad_almacen[min];
        }
        else{
            cantidad = 0;
            sol.cantidad[min] = cantidad;
        }
        
        sol.coste_total += mC[ubicacion][min];
        mC[min][ubicacion] = INF;
        ubicacion = min;
    }
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

//Entedemos el parte como un vector de boleanos que nos dice si ha entrgado en una ciudad o no
template <typename tCoste>
tCoste cemento(typename GrafoP<tCoste>::vertice capital, const GrafoP<tCoste> &G, const std::vector<bool> &parte){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N = G.numVert();

    std::vector<vertice> P1;
    std::Vector<tCoste> hacia_cliente = Dijkstra(G, capital, P1);
    std::vector<vertice> P2;
    std::Vector<tCoste> hacia_capital = DijkstraInv(G, capital, P2);

    tCoste coste = 0;
    for(vertice i = 0; i < N; i++){
        if(parte[i])
            coste += (hacia_cliente[i] + hacia_capital[i]);
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
std::vector<vertice> alergia(const GrafoP<tCoste> carretera, const GrafoP<tCoste> tren, const GrafoP<tCoste> avion, double dinero, string alergia, const typename GrafoP<tCoste>::vertice Origen){
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
std::vector<vertice> viaje_alergia( typename GrafoP<tCoste>::vertice Origen, double dinero, const GrafoP<tCoste> G1, const GrafoP<tCoste> G2){
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
    std::Vector<tCoste> costes = Dijkstra(barato, Origen, P);

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

matriz<tCoste> ejercicio6(const GrafoP<tCoste> tren, const GrafoP<tCoste> bus, typename GrafoP<tCoste>::vertice ciudad_cambio){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N = tren.numVert();

    std::matriz<vertice> P1;
    std::matriz<tCoste> bus_floyd = Floyd(bus, P1);
    std::matriz<vertice> P2;
    std::matriz<tCoste> tren_floyd = Floyd(tren, P1);

    matriz<tCoste> solucion(N);


    for(auto i = 0; i < N; i++){
        for(auto j = 0; j < N; j++){
            solucion[i][j] = std::min(bus_floyd[i][j], tren_floyd[i][j], std::sum(bus_floyd[i][cambio], tren_floyd[cambio][j]), std::sum(tren_floyd[i][cambio], bus_floyd[cambio][j]));
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

matriz<tCoste> ejercicio6(const GrafoP<tCoste> tren, const GrafoP<tCoste> bus, typename GrafoP<tCoste>::vertice ciudad_cambio1, typename GrafoP<tCoste>::vertice ciudad_cambio2, typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N = tren.numVert();

    std::matriz<vertice> P1;
    std::matriz<tCoste> bus_floyd = Floyd(bus, P1);
    std::matriz<vertice> P2;
    std::matriz<tCoste> tren_floyd = Floyd(tren, P1);

    matriz<tCoste> solucion(N);



   return std::min(std::sum(bus_floyd[ciudad_cambio1][destino], tren_floyd[origen][ciudad_cambio1]), std::sum(bus_floyd[ciudad_cambio2][destino], tren_floyd[origen][ciudad_cambio2]));
    

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
Mucha suerte en el negocio, que la competencia es dura. 
*/
template <typename tCoste>

tCoste ejercicio8(const GrafoP<tCoste> bus, const GrafoP<tCoste> tren, typename GrafoP<tCoste>::Vertice Origen, typename GrafoP<tCoste>::vertice Destino){
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

    assert(tren.numVert() == autobus.numVert());
    const size_t N = tren.numVert();

    assert(origen < N && destino < N);

    ej7_9<tCoste> resultado;
    resultado.coste_minimo = {};

    // Esto es un supergrafo, porque de 0 a N - 1 incluye el grafo del tren,
    // y de N a (N * 2 - 1) incluye el grafo del autobús.
    GrafoP<tCoste> grafo_unido(N * 2);
    for (vertice i = 0; i < N; i++)
    {
        // Añadimos el coste del taxi para ir de una ciudad a otra.
        grafo_unido[i][i + N] = grafo_unido[i + N][i] = taxi;

        for (vertice j = 0; j < N; j++)
        {
            grafo_unido[i][j] = tren[i][j];
            grafo_unido[N + i][N + j] = autobus[i][j];
        }
    }

    // Haremos Floyd para calcular el mejor camino entre el origen y el destino.
    matriz<tCoste> P; // para camino
    const auto distancias = Floyd(grafo_unido, P);

    // Elegimos la mejor opción posible:
    resultado.coste_minimo = std::min(distancias[origen][destino], // salir en tren y llegar en tren
        std::min(distancias[N + origen][destino]),                 // salir en autobús y llegar en tren
        std::min(distancias[origen][N + destino],                  // salir en tren y llegar en autobús
            distancias[origen + N][destino + N]));                 // salir en autobús y llegar en autobús

    if (resultado.coste_minimo == distancias[N + origen][destino])
        origen = origen + N;
    else if (resultado.coste_minimo == distancias[origen][N + destino])
        destino = destino + N;
    else if (resultado.coste_minimo != distancias[origen][destino])
    {
        destino = destino + N;
        origen = origen + N;
    }

    resultado.camino = camino(origen, destino, P);

    // Le quitamos el offset que pueda tener con el módulo (con N = 8, 15 pasaría a ser 7).
    for (auto i = resultado.camino.primera(); i != resultado.camino.fin(); i = resultado.camino.siguiente(i))
        resultado.camino.elemento(i) = resultado.camino.elemento(i) % N;

    return resultado;
    

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
template<typename tCoste>
struct solucion
{
    Lista<typename GrafoP<tCoste>::vertice> camino;
    tCoste coste_minimo;
};

template <typename tCoste>
tCoste ejercicio10(typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino, const tCoste coste_tren_bus, const tCoste coste_aero, const GrafoP<tCoste> &tren, const GrafoP<tCoste> &bus, const GrafoP<tCoste> &avion){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N = tren.numVert();
    static const INF = GrafoP<tCoste>::INFINITO;

    assert(origen < N && destino < N);

    GrafoP<tCoste> grafo_unido(N * 3);

    for(vertice i = 0; i < N; i++){
        //rellenamos el grafo con los costes de los taxis
        grafo_unido[i][i+N] = grafo_unido[i+N][i] = coste_tren_bus;
        grafo_unido[i+N][i+2*N] = grafo_unido[i+2*N][i+N] = coste_aero; 
        grafo_unido[i][i+2*N] = grafo_unido[i+2*N][i] = coste_aero;
        //rellenamos el resto del grafo con los costes de los medios de transporte
        for( vertice j = 0; j < N; j++){
            grafo_unido[i][j] = bus[i][j];
            grafo_unido[i+N][j+N] = tren[i][j];
            grafo_unido[i+2*N][j+2*N] = avion[i][j];
        }
    }

    matriz<tCoste> distancias;
    matriz<vertice> P
    solucion sol;

    distancias = Floyd(grafo_unido, P);

    sol.coste_camino = std::min(distancias[origen][destino],//d. bus
             distancias[origen+N][destino+N], //d. tren
             distancias[origen+2*N][destino+2*N], //d. avion
             distancias[origen][destino+N], // bus-tren
             distancias[origen+N][destino], // tren-bus
             distancias[origen][destino+2*N], //bus-avion
             distancias[origen+N][destino+2*N], //tren-avion
             distancias[origen+2*N][destino+N], //avion-tren
             distancias[origen+2*N][destino] //avion-bus
    );

    if(sol.coste_camino == distancias[origen][destino]){
        origen = origen;
        destino = destino;
    }
    else if(sol.coste_camino == distancias[origen+N][destino+N]){
        origen = origen + N;
        destino = destino + N;
    }
    else if(sol.coste_camino == distancias[origen+2*N][destino+2*N]){
        origen = origen + 2*N;
        destino = destino + 2*N;
    }
    else if(sol.coste_camino == distancias[origen][destino+N]){
        origen = origen;
        destino = destino + N;
    }
    else if(sol.coste_camino == distancias[origen+N][destino]){
        origen = origen + N;
        destino = destino;
    }
    else if(sol.coste_camino == distancias[origen][destino+2*N]){
        origen = origen;
        destino = destino + 2*N;
    }
    else if(sol.coste_camino == distancias[origen+N][destino+2*N]){
        origen = origen + N;
        destino = destino + 2*N;
    }
    else if(sol.coste_camino == distancias[origen+2*N][destino+N]){
        origen = origen + 2*N;
        destino = destino + N;
    }
    else if(sol.coste_camino == distancias[origen+2*N][destino]){
        origen = origen + 2*N;
        destino = destino;
    }

    sol.camino = camino(origen, destino, P);
    
    for(auto i = sol.camino.primera(); i != sol.camino.fin(); i = sol.camino.siguiente(i)){
        sol.camino.elemento(i) = sol.camino.elemento(i) % N;
    }

    return sol;
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
};

matriz<tCoste> ejercicio11(const std::vector<puente> &puentes, const GrafoP<tCoste> &G1, const GrafoP<tCoste> &G2, const GrafoP<tCoste> &G3){
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N1 = G1.numVert();
    const size_t N2 = G2.numVert();
    const size_t N3 = G3.numVert();

    const size_t NT = N1 + N2 + N3;
    GrafoP<tCoste> grafo_unido(NT);

    for(vertice i = 0; i < N1; i++){
        for(vertice j = 0; j < N1; j++){
            grafo_unido[i][j] = G1[i][j];
        }
    }

    for(vertice i = N1; i < N1 + N2; i++){
        for(vertice j = N1; j < N1 + N2; j++){
            grafo_unido[i][j] = G2[i][j];
        }
    }

    for(vertice i = N1 + N2; i < NT; i++){
        for(vertice j = N1 + N2; j < NT; j++){
            grafo_unido[i][j] = G3[i][j];
        }
    }

    for(auto i = 0; i < puentes.size(); i++){
        grafo_unido[puentes[i].a][puentes[i].b] = grafo_unido[puentes[i].b][puentes[i].a] = 0;
    }

    matriz<tCoste> mCostes;
    matriz<vertice> P;

    mCostes = Floyd(grafo_unido, P);

    return mCostes;
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

puente ejercicio12(std::vector<bool> costeras_fobos, std::vector<bool> costeras_deimo, const GrafoP<tCoste> fobos, const GrafoP<tCoste> deimos){
    typdef typename GrafoP<tCoste>::vertice vertice;
    const size_t Nf = fobos.numVert();
    const size_t Nd = deimos.numVert();
    const size_t Cf = costeras_fobos.size();
    const size_t Cd = costeras_deimos.size();
    const size_t NT = Nf + Nd;

    matriz<tCoste> mCostesF;
    matriz<vertice> PF;
    matriz<tCoste> mCostesD;
    matriz<vertice> PD;

    mCostesF = Floyd(fobos, PF);
    tCoste minFobos = INF;
    vertice vMinFobos;
    for(vertice i = 0; i < Cf; i++){
        if(costeras_fobos[i]){
            tCoste aux = 0;
            for(vertice j = 0; j < Nf; j++){
                aux += mCostesF[i][j];
            }
            if(aux < minFobos){
                vMinFobos = i;
                minFobos = aux;
            }
        }
    }  

    mCostesD = Floyd(deimos, PD);
    tCoste minDeimos = INF;
    vertice vMinDeimos;
    for(vertice i = 0; i < Cd; i++){
        if(costeras_deimos[i]){
            tCoste aux = 0;
            for(vertice j = 0; j < Nd; j++){
                aux += mCostesD[i][j];
            }
            if(aux < minDeimos){
                vMinDeimos = i;
                minDeimos = aux;
            }
        }
    }

    puente sol;
    sol.a = vMinFobos;
    sol.b = vMinDeimos;

    return sol;
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

//--------------------------------------PRACTICA 8 ------------------------------------------------------------------
/*1. El archipiélago de Tombuctú, está formado por un número indeterminado de islas,
cada una de las cuales tiene, a su vez, un número indeterminado de ciudades. En
cambio, sí es conocido el número total de ciudades de Tombuctú (podemos llamarlo N,
por ejemplo).
Dentro de cada una de las islas existen carreteras que permiten viajar entre todas
las ciudades de la isla. Se dispone de las coordenadas cartesianas (x, y) de todas y cada
una de las ciudades del archipiélago. Se dispone de un grafo (matriz de adyacencia) en
el que se indica si existe carretera directa entre cualesquiera dos ciudades del
archipiélago. El objetivo de nuestro problema es encontrar qué ciudades de Tombuctú
pertenecen a cada una de las islas del mismo y cuál es el coste mínimo de viajar entre
cualesquiera dos ciudades de una misma isla de Tombuctú.
Así pues, dados los siguientes datos:
- Lista de ciudades de Tombuctú representada cada una de ellas por sus
coordenadas cartesianas.
- Matriz de adyacencia de Tombuctú, que indica las carreteras existentes en
dicho archipiélago.
Implementen un subprograma que calcule y devuelva la distribución en islas de las
ciudades de Tombuctú, así como el coste mínimo de viajar entre cualesquiera dos
ciudades de una misma isla del archipiélago.*/

template <typename tCoste>
struct solucion{
    particion p;
    matriz<tCoste> mCostes;
};

struct ciudad{
    double x, y;
};

template <typename tCoste>
tCoste distancia(ciudad c1, ciudad c2){
    return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}

template <typename tCoste>
solucion ejercicio1(vector<coordenadas> vector, matriz<bool> mAdyacencia){
    size_t N = mAdyacencia.size();

    //Creamos la particion
    particion p(N);


    //Pasamos de matriz de adyacencia a matriz de costes y rellena la particion
    matriz<tCoste> mCostes(N);
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < N; j++){
            if(mAdyacencia[i][j]){
                mCostes[i][j] = distancia(vector[i], vector[j]);
                
                //!DUDA DE SI ESTO ESTA BIEN
                if(p.encontrar(i) != p.encontrar(j)){
                    p.unir(p.encontrar(i), p.encontrar(j));
                
            }
            else{
                mCostes[i][j] = GrafoP<tCoste>::INFINITO;
            }
        }
    }

    //Aplicamos Floyd
    matriz<vertice> P;
    matriz<tCoste> mCostesFloyd(N);
    mCostesFLoyd = Floyd(mCostes, P);


    return solucion{p, mCostesFloyd};
}

/*
2. El archipiélago de Tombuctú2 está formado por un número desconocido de islas,
cada una de las cuales tiene, a su vez, un número desconocido de ciudades, las cuales
tienen en común que todas y cada una de ellas dispone de un aeropuerto. Sí que se
conoce el número total de ciudades del archipiélago (podemos llamarlo N, por ejemplo).
Dentro de cada una de las islas existen carreteras que permiten viajar entre todas
las ciudades de la isla. No existen puentes que unan las islas y se ha decidido que la
opción de comunicación más económica de implantar será el avión.
Se dispone de las coordenadas cartesianas (x, y) de todas y cada una de las
ciudades del archipiélago. Se dispone de un grafo (matriz de adyacencia) en el que se
indica si existe carretera directa entre cualesquiera dos ciudades del archipiélago. El
objetivo de nuestro problema es encontrar qué líneas aéreas debemos implantar para
poder viajar entre todas las ciudades del archipiélago, siguiendo los siguientes criterios:
1) Se implantará una y sólo una línea aérea entre cada par de islas.
2) La línea aérea escogida entre cada par de islas será la más corta entre todas
las posibles.
Así pues, dados los siguientes datos:
• Lista de ciudades de Tombuctú2 representada cada una de ellas por sus
coordenadas cartesianas.
• Matriz de adyacencia de Tombuctú que indica las carreteras existentes en
dicho archipiélago,
Implementen un subprograma que calcule y devuelva las líneas aéreas necesarias para
comunicar adecuadamente el archipiélago siguiendo los criterios anteriormente
expuestos*/
template <typename tCoste>
struct lineaAerea{
    vertice i, j;
    tCoste coste;
};

template <typename tCoste>
struct ciudad{
    double x, y;
};

template <typename tCoste>
tCoste distancia(ciudad c1, ciudad c2){
    return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}

void tombuctu2(const Grafo& archipielago, vector<isla<double> > islas)
{
    unsigned N = archipielago.numVert(), nIslas;
    Particion p(n);
    nIslas = N;
    typedef typename Grafo::vertice vertice;

    for(vertice i = 0; i < n; ++i)
    {
        for(vertice j = 0; j < n; ++j)
        {   
            //condicion de que exista carretera y condidicion de los representantes necesaria por la precondición de la función unir
            if(archipielago[i][j] && p.encontrar(i) != p.encontrar(j))
            {
                --nIslas;
                p.unir(p.encontrar(i), p.encontrar(j));
            }
        }
    }
    nLineas = nIslas*(nIslas-1)/2;
    //Tras este for ya sabemos el numero de islas que hay y el numero de lineas aereas que necesitamos por cada par de islas
    std::cout << "Numero de islas: " << nIslas << std::endl; 
    std::cout << "Numero de lineas: " << nLineasPosibles << std::endl; 


    //Apo que va a almacenar todas las lineas posibles
    Apo<LineaAerea> apo(LineasPosibles);

    //Rellenamos el apo con todas las lineas posibles da igual que nos valgan o no
    for(vertice i = 0; i <= N-1; i++){
        for(vertice j = 0; j <= N-1; j++){
            linea(i, j, coste) = {i, j, distancia(i, j)};
            apo.insertar(linea); //Inserto línea en el apo
        }
    }
    
    //vector solucion con las minimas lineas aereas
    vector<LineaAerea> vector(nLineas);

    //matriz que controla que una linea no tenga ni misma ciudad de origen ni misma ciudad de destino
    matriz<bool> mLineaNoRepetida(N, false);

    //Una vez en el Apo las lineas estan ordenadas de menor a mayor
    //Ahora vamos a ir sacando las lineas del apo y comprobando si nos valen o no
    int lineas_actual = 0; 
    while(lineas_actual < nLineas){
        lineaArea actual = apo.cima();
        apo.suprimir();

        //Si tienen representante distintos es pk las lineas une ciudad de islas distintas
        //por tanto, se mete en el vector solucion, se unen para decir que ya hay una linea con esas islas a través de las ciudades
        //y  aumentamos el contador de las lineas actuales
        if(!mLineaNoRepetida[actual.i][actual.j]){
            vector.push_back(actual);
            mLineaNoRepetida[actual.i][actual.j] = T
            lineas_actual++;
        }
    }

    return vector;
}


/*
2. El archipiélago de Tombuctú2 está formado por un número desconocido de islas,
cada una de las cuales tiene, a su vez, un número desconocido de ciudades, las cuales
tienen en común que todas y cada una de ellas dispone de un aeropuerto. Sí que se
conoce el número total de ciudades del archipiélago (podemos llamarlo N, por ejemplo).
Dentro de cada una de las islas existen carreteras que permiten viajar entre todas
las ciudades de la isla. No existen puentes que unan las islas y se ha decidido que la
opción de comunicación más económica de implantar será el avión.
Se dispone de las coordenadas cartesianas (x, y) de todas y cada una de las
ciudades del archipiélago. Se dispone de un grafo (matriz de adyacencia) en el que se
indica si existe carretera directa entre cualesquiera dos ciudades del archipiélago. El
objetivo de nuestro problema es encontrar qué líneas aéreas debemos implantar para
poder viajar entre todas las ciudades del archipiélago, siguiendo los siguientes criterios:
1) Se implantará una y sólo una línea aérea entre cada par de islas.
2) La línea aérea escogida entre cada par de islas será la más corta entre todas
las posibles.
Así pues, dados los siguientes datos:
• Lista de ciudades de Tombuctú2 representada cada una de ellas por sus
coordenadas cartesianas.
• Matriz de adyacencia de Tombuctú que indica las carreteras existentes en
dicho archipiélago,
Implementen un subprograma que calcule y devuelva las líneas aéreas necesarias para
comunicar adecuadamente el archipiélago siguiendo los criterios anteriormente
expuestos.
PERO VERSIÓN EXAMEN -> EN VEZ DE LINEAS ENTRE CADA PAR DE ISLAS, QUE SEA LAS LINEAS MINIMAS*/
template <typename tCoste>
struct lineaAerea{
    vertice i, j;
    tCoste coste;
};

template <typename tCoste>
struct ciudad{
    double x, y;
};

template <typename tCoste>
tCoste distancia(ciudad c1, ciudad c2){
    return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}

void tombuctu2(const Grafo& archipielago, vector<isla<double> > islas)
{
    unsigned n = archipielago.numVert(), nIslas;
    Particion p(n);
    nIslas = n;
    typedef typename Grafo::vertice vertice;

    for(vertice i = 0; i < n; ++i)
    {
        for(vertice j = 0; j < n; ++j)
        {   
            //condicion de que exista carretera y condidicion de los representantes necesaria por la precondición de la función unir
            if(archipielago[i][j] && p.encontrar(i) != p.encontrar(j))
            {
                --nIslas;
                p.unir(p.encontrar(i), p.encontrar(j));
            }
        }
    }
    nLineasPosibles = nIslas*(nIslas-1)/2;
    nLineasMinimas = nIslas-1;
    //Tras este for ya sabemos el numero de islas que hay y el numero de lineas aereas que necesitamos por cada par de islas
    std::cout << "Numero de islas: " << nIslas << std::endl; 
    std::cout << "Numero de lineas posibles: " << nLineasPosibles << std::endl; 
    std::cout << "Numero de lineas minimas"<< nLineasMinimas << std::endl;


    //Apo que va a almacenar todas las lineas posibles
    Apo<LineaAerea> apo(LineasPosibles);

    //Rellenamos el apo con todas las lineas posibles da igual que nos valgan o no
    for(vertice i = 0; i <= N-1; i++){
        for(vertice j = 0; j <= N-1; j++){
            linea(i, j, coste) = {i, j, distancia(i, j)};
            apo.insertar(linea); //Inserto línea en el apo
        }
    }

    //vector solucion con las minimas lineas aereas
    vector<LineaAerea> vector(nLineasMinimas);

    //Una vez en el Apo las lineas estan ordenadas de menor a mayor
    //Ahora vamos a ir sacando las lineas del apo y comprobando si nos valen o no
    int lineas_actual = 0; 
    while(lineas_actual < nLineasMinimas){
        lineaArea actual = apo.cima();
        apo.suprimir();

        //Si tienen representante distintos es pk las lineas une ciudad de islas distintas
        //por tanto, se mete en el vector solucion, se unen para decir que ya hay una linea con esas islas a través de las ciudades
        //y  aumentamos el contador de las lineas actuales
        if(p.encontrar(actual.i) != p.encontrar(actual.j)){
            vector.push_back(actual);
            p.unir(p.encontrar(actual.i), p.encontrar(actual.j));
            lineas_actual++;
        }
    }

    return vector;
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
    size_t N = distancias.numVert();

    GrafoP<tCoste> g(N);

    for(vertice i = 0; i < N; i++){
        for(vertice j = 0; j < N, j++){
            g[i][j] = (distancias[i][j] * coste)-(caudal[i][j] * subvencion);
        }
    }

    return Kruskal(g);
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
struct ciudad
{
    double x, y;
    ciudad(double x_, double y_) : x(x_), y(y_){};
};

struct puente
{
    ciudad a, b;
    double coste;
};

tCoste distancia(ciudad c1, ciudad c2){
    return sqrt(pow(c1.a - c2.a,2) + pow(c1.b - c2.b, 2));
}

puente puenteCosteMinimo(vector<ciudad> fobos, vector<ciudad> deimos, vector<vertice> costaFobos,
     vector<vertice> costaDeimos)
{
    puente puenteMin;
    puenteMin.fobos = 0;
    puenteMin.deimos = 0;
    puenteMin.coste = GrafoP<double>::INFINITO;
    for (int i = 0; i < costaFobos.size(); ++i)
        for (int j = 0; j < costaDeimos.size(); ++j)
        {
            double coste = distancia(fobos[costaFobos[i]], deimos[costaDeimos[j]]);
            if (coste < puenteMin.coste)
            {
                puenteMin.coste = coste;
                puenteMin.fobos = costaFobos[i];
                puenteMin.deimos = costaDeimos[i];
            }
        }
    return puenteMin;
}


template <typename tCoste>
tCoste Grecoland(const vector<ciudad> Fobos, const vector<ciudad> Deimos, const vector<vertice> costerasFobos, 
                const vector<vertice> costerasDeimos, vertice origen, vertice destino){
    size_t Nf = Fobos.size();
    size_t Nd = Deimos.size();
    size_t  N = Nf + Nd;

    GrafoP<tCoste> sGrafo (N);
    //Carreteras de fobos
    for(vertice i = 0; i < Nf; i++){
        for(vertice j = 0; j < Nf, j++){
            sGrafo[i][j] = distancia(Fobos[i],Fobos[j]);
        }
    }
    //Carretera de Deimos
    for(vertice i = Nf; i < N; i++){
        for(vertice j = Nf; j < N, j++){
            sGrafo[i][j] = distancia(Deimos[i],Deimos[j]);
        }
    }

    //Hacemos los puentes
    for(vertice i = 0; i < Nf; i++){
        for(vertice j = Nf; j < N, j++){
            sGrafo[i][j] = distancia(Fobos[i],Deimos[j]);
        }
    }


    puente puente = puenteCosteMinimo(Fobos, Deimos, costerasFobos, costerasDeimos);
    archipielago[puente.fobos][puente.deimos + Fobos.size()] = archipielago[puente.deimos + Fobos.size()][puente.fobos] = puente.coste;

    vector<vertice> vVer;
    vector<double> costes = Dijkstra(archipielago, origen, vVer);
    std::cout << costes[destino];

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


/*
La capital de Zuelandia está alcanzando niveles de toxicidad muy elevados, por ello se ha
decretado el cierre a la ciudad como paso de tránsito hacia otras ciudades. (Para ir de una
ciudad a otra no se podrá pasar por C.Zuelandia, pero si se podrá ir si es residente de la misma
empleándola como ciudad destino u origen).
Implemente un subprograma que dada la capital y un grafo ponderado con los km de las
carreteras existentes entre las ciudades del país, nos devuelva los caminos resultantes de
nuestra nueva política “Sin pasar por la capital, por favor”.
*/



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