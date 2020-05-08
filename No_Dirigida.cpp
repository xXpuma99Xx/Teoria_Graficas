#include "No_Dirigida.hpp"
#include "Funciones.hpp"
#include<iostream>

No_Dirigida::No_Dirigida(){
}

No_Dirigida::No_Dirigida(std::vector<std::string> n,std::vector<std::string> e,std::vector<std::string> s)
	: Grafica(n,e,s){
}

std::string No_Dirigida::incidencia(){
	std::string tabla;
	std::string linea {imprimir_linea()};

	tabla = imprimir_header_matriz();
	for(size_t i {};i < nodos.size();i++){
		std::string renglon;
		int contador {};

		renglon = "| " + nodos[i] + " |";
		for(size_t j{};j < entradas.size();j++){
			if(nodos[i] == entradas[j]||nodos[i] == salidas[j]){
				renglon += "  1|";
				contador++;
			}
			else
				renglon += "  0|";
		}
		
		sumatorias.push_back(contador);
		tabla += renglon + "\n" + linea;
	}

	return tabla;
}
