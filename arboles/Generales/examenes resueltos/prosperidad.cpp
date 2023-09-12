#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include "agenDinamica.h"
#include "abin_E-S.h"

//Calcula el indice de prosperidad de una poblacion, es decir,  el porcentaje de nodos prosperos. El elemento del nodo nos indica la 
//riqueza, se considera que un nodo es prospero cuando su dinero es mayor que el de sus antecesores propios y su dinero es menor que sus 
//descendientes propios.

//REHACER