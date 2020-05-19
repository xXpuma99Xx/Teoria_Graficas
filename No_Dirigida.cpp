#include "No_Dirigida.hpp"
#include "Funciones.hpp"

No_Dirigida::No_Dirigida(){
}

No_Dirigida::No_Dirigida(std::vector<std::string> n,std::vector<std::string> e,std::vector<std::string> s)
	: Grafica(n,e,s){
}

std::string No_Dirigida::incidencia(){
	std::string linea {imprimir_linea(entradas.size() + 1, 3)};
	std::vector<std::string> headers {" "};

	for(size_t i {};i < entradas.size();i++)
		headers.push_back(std::to_string(i+1));

	std::string tabla {imprimir_headers(headers,3)};

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
		sumatorias.push_back(contador);
		tabla += renglon + "\n" + linea;
	}

	return tabla;
}

std::string No_Dirigida::adyacencia(){
	std::string linea {imprimir_linea(nodos.size() + 1,3)};
	std::vector<std::string> headers {" "};
	std::vector<std::vector<double>> mat_aux;

	for(size_t i {};i < nodos.size();i++)
		headers.push_back(nodos[i]);

	std::string tabla {imprimir_headers(headers,3)};
	
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

std::string No_Dirigida::grado_de_vertices(){
	std::string linea {imprimir_linea(2,3)};
	std::vector<std::string> headers {"n"," ° "};
	std::string tabla {imprimir_headers(headers,3)};

	for(size_t i {};i < nodos.size();i++)
		tabla += "| " + nodos[i] + " |" + imprimir_numero_entero(sumatorias[i],3) + "|\n";
	
	return tabla + linea;

}

std::string No_Dirigida::aislados(){
	std::string linea {imprimir_linea(1,7)};
	std::vector<std::string> headers {"Aislado"};
	std::string tabla {imprimir_headers(headers,7)};
	size_t aux{tabla.size()};

	for(size_t i {};i < nodos.size();i++)
		if(sumatorias[i] == 0)
			tabla += "|   " + nodos[i] + "   |\n";
	
	if(tabla.size() > aux)
		tabla += linea;

	return tabla;
}

std::string No_Dirigida::colgante(){
	std::string linea {imprimir_linea(1,8)};
	std::vector<std::string> headers {"Colgante"};
	std::string tabla {imprimir_headers(headers,8)};
	size_t aux{tabla.size()};

	for(size_t i {};i < nodos.size();i++)
		if(sumatorias[i] == 1)
			tabla += "|    " + nodos[i] + "   |\n";
	
	if(tabla.size() > aux)
		tabla += linea;

	return tabla;
}
