#include "Grafica.hpp"
#include "Funciones.hpp"

Grafica::Grafica(){
}

Grafica::Grafica(std::vector<std::string> n,std::vector<std::string> e,std::vector<std::string> s)
	:nodos{n}, entradas{e}, salidas{s} {
}

std::vector<std::string> Grafica::get_nodos(){
	return nodos;
}

void Grafica::set_nodos(std::vector<std::string> nodos){
	this->nodos = nodos;
}

std::vector<std::string> Grafica::get_entradas(){
	return entradas;
}

void Grafica::set_entradas(std::vector<std::string> entradas){
	this->entradas = entradas;
}

std::vector<std::string> Grafica::get_salidas(){
	return salidas;
}

void Grafica::set_salidas(std::vector<std::string> salidas){
	this->salidas = salidas;
}

size_t Grafica::str_nodo_mas_grande(){
	size_t tamanio {};
	
	for(size_t i{};i < nodos.size();i++)
		if(nodos[i].size() > tamanio)
			tamanio = nodos[i].size();

	return tamanio;
}

std::string Grafica::imprimir_linea(size_t e, size_t tamanio){
	std::string linea {"+"};

	for(size_t i{};i < e;i++){
		for(size_t j {};j < tamanio;j++)
			linea += "-";
		linea += "+";
	}

	return linea + "\n";
}
