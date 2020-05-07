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

		renglon = "| " + nodos[i] + " |";
		for(size_t j{};j < entradas.size();j++){
			if(nodos[i] == entradas[j]&&nodos[i] == salidas[j])
				renglon += "+-1|";
			else if(nodos[i] == entradas[j])
				renglon += " -1|";
			else if(nodos[i] == salidas[j])
				renglon += "  1|";
			else
				renglon += "  0|";
		}

		tabla += renglon + "\n" + linea;
	}

	return tabla;
}
