#include "No_Dirigida.hpp"
#include "Funciones.hpp"

No_Dirigida::No_Dirigida(){
}

No_Dirigida::No_Dirigida(std::vector<std::string> n,std::vector<std::string> e,std::vector<std::string> s)
	: Grafica(n,e,s){
}

std::string No_Dirigida::incidencia(){
	std::string linea {imprimir_linea(entradas.size() + 2)};
	std::vector<std::string> headers {" "};

	for(size_t i {};i < entradas.size();i++)
		headers.push_back(std::to_string(i+1));
	headers.push_back("p");

	std::string tabla {imprimir_headers(headers)};

	for(size_t i {};i < nodos.size();i++){
		std::string renglon;
		int contador {};

		renglon = "| " + nodos[i] + " |";
		for(size_t j{};j < entradas.size();j++){
			if(nodos[i] == entradas[j]||nodos[i] == salidas[j]){
				renglon += "  1|";
				contador++;
			} else
				renglon += "  0|";
		}
		renglon += imprimir_numero_entero(contador) + "|";
		sumatorias.push_back(contador);
		tabla += renglon + "\n" + linea;
	}

	return tabla;
}

std::string No_Dirigida::adyacencia(){
	std::string linea {imprimir_linea(nodos.size() + 1)};
	std::vector<std::string> headers {" "};
	std::vector<std::vector<double>> mat_aux;

	for(size_t i {};i < nodos.size();i++)
		headers.push_back(nodos[i]);

	std::string tabla {imprimir_headers(headers)};
	
	for(size_t i {};i < nodos.size();i++){
		std::string renglon;
		std::vector<double> vec_aux;

		renglon = "| " + nodos[i] + " |";
		for(size_t j{};j < nodos.size();j++){
			bool no_linea {true};

			for(size_t k {};k < entradas.size();k++){
				if(j == i){
					if((nodos[i] == entradas[k]&&nodos[j] == salidas[k])||(nodos[j] == entradas[k]&&nodos[i] == salidas[k]))
						no_linea = false;
				} else {
					if((nodos[i] == entradas[k]||nodos[i] == salidas[k])&&(nodos[j] == entradas[k]||nodos[j] == salidas[k]))
						no_linea = false;
				}
			}
			if(no_linea){
				renglon += "  0|";
				vec_aux.push_back(0);
			} else {
				renglon += "  1|";
				vec_aux.push_back(1);
			}
		}
		mat_aux.push_back(vec_aux);
		tabla += renglon + "\n" + linea;
	}

	return tabla;
}
