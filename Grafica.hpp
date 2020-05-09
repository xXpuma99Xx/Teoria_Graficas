#ifndef _GRAFICA_H_
#define _GRAFICA_H_

#include<vector>
#include<string>

class Grafica {
public:
	std::vector<std::string> nodos;
	std::vector<std::string> entradas;
	std::vector<std::string> salidas;

	Grafica();
	Grafica(std::vector<std::string>,std::vector<std::string>,std::vector<std::string>);

	std::vector<std::string> get_nodos();
	void set_nodos(std::vector<std::string>);

	std::vector<std::string> get_entradas();
	void set_entradas(std::vector<std::string>);

	std::vector<std::string> get_salidas();
	void set_salidas(std::vector<std::string>);

	size_t str_nodo_mas_grande();
	std::string imprimir_linea(size_t);
};

#endif
