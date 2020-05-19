#include "Dirigida.hpp"
#include "Funciones.hpp"

Dirigida::Dirigida(){
}

Dirigida::Dirigida(std::vector<std::string> n,std::vector<std::string> e,std::vector<std::string> s)
	:Grafica(n,e,s){
}

std::string Dirigida::incidencia(){
	std::string tabla;
	std::string linea {imprimir_linea(entradas.size() + 1 , 3)};
	std::vector<std::string> headers {" "};

	for(size_t i {};i < entradas.size();i++)
		headers.push_back(std::to_string(i+1));
	tabla = imprimir_headers(headers,3);
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
			} else if(nodos[i] == entradas[j]){
				renglon += " -1|";
				contador_n++;
			} else if(nodos[i] == salidas[j]){
				renglon += "  1|";
				contador_p++;
			} else
				renglon += "  0|";
		}
		sumatorias_p.push_back(contador_p);
		sumatorias_n.push_back(contador_n);
		tabla += renglon + "\n" + linea;
	}

	return tabla;
}

std::string Dirigida::Dirigida::adyacencia(){
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

			for(size_t k {};k < entradas.size();k++)
				if(nodos[j] == entradas[k]&&nodos[i] == salidas[k])
					no_linea = false;
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
	ad = Matriz{mat_aux,true};

	return tabla;
}

std::string Dirigida::grado_de_vertices(){
	std::string linea {imprimir_linea(3,3)};
	std::vector<std::string> headers {" ","+","-"};
	std::string tabla {imprimir_headers(headers,3)};

	for(size_t i {};i < nodos.size();i++)
		tabla += "| " + nodos[i] + " |" + imprimir_numero_entero(sumatorias_p[i],3) + "|" + imprimir_numero_entero(sumatorias_n[i],3) + "|\n";
	
	return tabla + linea;
}

std::string Dirigida::aislados(){
	std::string linea {imprimir_linea(1,7)};
	std::vector<std::string> headers {"Aislado"};
	std::string tabla {imprimir_headers(headers,7)};
	size_t aux{tabla.size()};

	for(size_t i {};i < nodos.size();i++)
		if(sumatorias_p[i] == 0&&sumatorias_n[i] == 0)
			tabla += "|   " + nodos[i] + "   |\n";
	
	if(tabla.size() > aux)
		tabla += linea;
	return tabla;
}

std::string Dirigida::inicial(){
	std::string linea {imprimir_linea(1,7)};
	std::vector<std::string> headers {"Inicial"};
	std::string tabla {imprimir_headers(headers,7)};
	size_t aux{tabla.size()};

	for(size_t i {};i < nodos.size();i++)
		if(sumatorias_p[i] > 0&&sumatorias_n[i] == 0)
			tabla += "|   " + nodos[i] + "   |\n";
	
	if(tabla.size() > aux)
		tabla += linea;
	return tabla;
}

std::string Dirigida::final_(){
	std::string linea {imprimir_linea(1,5)};
	std::vector<std::string> headers {"Final"};
	std::string tabla {imprimir_headers(headers,5)};
	size_t aux{tabla.size()};

	for(size_t i {};i < nodos.size();i++)
		if(sumatorias_p[i] == 0&&sumatorias_n[i] > 0)
			tabla += "|  " + nodos[i] + "  |\n";
	
	if(tabla.size() > aux)
		tabla += linea;
	return tabla;
}
