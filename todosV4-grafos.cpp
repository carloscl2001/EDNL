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
