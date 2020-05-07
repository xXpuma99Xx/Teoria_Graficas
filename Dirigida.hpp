#ifndef _DIRIGIDA_H_
#define _DIRIGIDA_H_

#include "Grafica.hpp"

class Dirigida: public Grafica {
public:
	Dirigida();
	Dirigida(std::vector<std::string>,std::vector<std::string>,std::vector<std::string>);

	std::string incidencia();
	std::string adyacencia();
	std::string accesibilidad();
	/*
	grado_de_vertices();

	simple_general();
	conectada_desconectada();
	regular();
	completa();
	arbol(); // grafica
	*/
};

#endif