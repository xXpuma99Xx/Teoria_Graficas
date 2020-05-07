#include "Grafica.hpp"

Grafica::Grafica(){}

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

