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
	/*

	lineas_paralelas();
	bucles();

	simple_general();
	conectada_desconectada();
	regular();
	completa();
	simetrica(); // digrafica
	balanceada(); // digrafica
	*/
};

#endif
