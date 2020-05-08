#include "Dirigida.hpp"


Dirigida::Dirigida(){
}

Dirigida::Dirigida(std::vector<std::string> n,std::vector<std::string> e,std::vector<std::string> s)
	:Grafica(n,e,s){
}


std::string Dirigida::incidencia(){
	std::string tabla;
	std::string linea {imprimir_linea()};

	tabla = imprimir_header_matriz();
	for(size_t i {};i < nodos.size();i++){
		std::string renglon;
		int contador_p {};
		int contador_n {};

		renglon = "| " + nodos[i] + " |";
		for(size_t j{};j < entradas.size();j++){
			if(nodos[i] == entradas[j]&&nodos[i] == salidas[j]){
				renglon += "+-1|";
				contador_p++;
				contador_n++;
			}
			else if(nodos[i] == entradas[j]){
				renglon += " -1|";
				contador_n++;
			}
			else if(nodos[i] == salidas[j]){
				renglon += "  1|";
				contador_p++;
			}
			else
				renglon += "  0|";
		}
		sumatorias_p.push_back(contador_p);
		sumatorias_n.push_back(contador_n);
		tabla += renglon + "\n" + linea;
	}

	return tabla;
}
