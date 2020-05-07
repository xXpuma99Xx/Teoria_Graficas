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
	size_t length {};
	
	for(size_t i{};i < nodos.size();i++)
		if(nodos[i].size() > length)
			length = nodos[i].size();

	return length;
}

std::string Grafica::imprimir_header_matriz(){
	std::vector<std::string> head {" "};

	for(size_t i {};i < entradas.size();i++)
		head.push_back(std::to_string(i+1));

	return imprimir_headers(head);
}

std::string Grafica::imprimir_linea(){
	std::string linea {"+"};

	for(size_t i{};i < entradas.size() + 1;i++){
		for(size_t j {};j < length;j++)
			linea += "-";
		linea += "+";
	}

	return linea + "\n";
}
