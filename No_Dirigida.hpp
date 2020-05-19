#ifndef _NO_DIRIGIDA_H_
#define _NO_DIRIGIDA_H_

#include "Grafica.hpp"

class No_Dirigida: public Grafica {
public:
	std::vector<int> sumatorias;
	
	No_Dirigida();
	No_Dirigida(std::vector<std::string>,std::vector<std::string>,std::vector<std::string>);

	std::string incidencia();
	std::string adyacencia();
	std::string accesibilidad();

	std::string grado_de_vertices();
	std::string aislados();
	std::string colgante();

	std::string lineas_paralelas();
	std::string bucles();
	std::string lineas_serie();

	std::string simple_general();
	std::string conectada_desconectada();
	std::string regular();
	std::string completa();
	std::string arbol();
};

#endif
