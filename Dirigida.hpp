#ifndef _DIRIGIDA_H_
#define _DIRIGIDA_H_

#include "Grafica.hpp"

class Dirigida: public Grafica {
public:
	std::vector<int> sumatorias_p;
	std::vector<int> sumatorias_n;
	
	Dirigida();
	Dirigida(std::vector<std::string>,std::vector<std::string>,std::vector<std::string>);

	std::string incidencia();
	std::string adyacencia();
	std::string accesibilidad();

	std::string grado_de_vertices();
	std::string aislados();
	std::string inicial();
	std::string final_();
	/*
	simple_general();
	conectada_desconectada();
	regular();
	completa();
	arbol(); // grafica
	*/
};

#endif
