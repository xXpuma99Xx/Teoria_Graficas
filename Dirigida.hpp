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

	std::string lineas_paralelas();
	std::string bucles();

	std::string simple_general();
	std::string conectada_desconectada();
	std::string regular();
	std::string completa();
	std::string simetrica();
	std::string balanceada();
};

#endif
