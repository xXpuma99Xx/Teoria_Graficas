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

std::string Dirigida::lineas_paralelas(){
	std::string linea {imprimir_linea(1,9)};
	std::vector<std::string> headers {"Paralelas"};
	std::string tabla {imprimir_headers(headers,9)};
	size_t aux{tabla.size()};
	size_t n{entradas.size()};

	for(size_t i{};i < n;i++){
		for(size_t j{i+1};j < n;j++){
			if(entradas[i] == entradas[j]&&salidas[i] == salidas[j]){
				tabla += "|  (" + entradas[i] + "," + salidas[i] + ")  |\n";
				break;
			}
		}
	}
	if(tabla.size() > aux)
		tabla += linea;

	return tabla;
}

std::string Dirigida::bucles(){
	std::string linea {imprimir_linea(1,6)};
	std::vector<std::string> headers {"Bucles"};
	std::string tabla {imprimir_headers(headers,6)};
	size_t aux{tabla.size()};

	for(size_t i{};i < ad.matriz.size();i++)
		if(ad.matriz[i][i] == 1)
			tabla += "|   " + nodos[i] + "  |\n";
	if(tabla.size() > aux)
		tabla += linea;

	return tabla;
}

std::string Dirigida::simple_general(){
	bool bucle{false};
	bool paralela{false};

	for(size_t i{};i < ad.matriz.size();i++)
		if(ad.matriz[i][i] == 1)
			bucle = true;
	for(size_t i{};i < entradas.size();i++){
		for(size_t j{i+1};j < entradas.size();j++){
			if(entradas[i] == entradas[j]&&salidas[i] == salidas[j]){
				paralela = true;
				break;
			}
		}
		if(paralela)
			break;
	}

	if(bucle || paralela){
		s_g = 'g';
		return "Es una digrafica general\n";
	}
	s_g = 's';
	return "Es una digrafica simple\n";
}

std::string Dirigida::regular(){
	for(size_t i{0};i < sumatorias_p.size()-1;i++)
		if((sumatorias_p[i] != sumatorias_p[i+1])||(sumatorias_n[i] != sumatorias_n[i+1])||(sumatorias_p[i] != sumatorias_n[i]))
			return "No es una digrafica regular\n";
	return "Es una digrafica regular\n";
}

std::string Dirigida::balanceada(){
	for(size_t i {};i < sumatorias_p.size()-1;i++)
		if(sumatorias_p[i] != sumatorias_n[i])
			return "No es una digrafica balanceada\n";
	return "Es una digrafica balancead\n";
}

std::string Dirigida::simetrica(){
	for(size_t i{};i < entradas.size();i++) {
		bool si_hay {false};

		for(size_t j{i+1};j < entradas.size();i++)
			if((salidas[i] == entradas[j]&&(entradas[i] == salidas[j])))
				si_hay = true;
		if(!si_hay)
			return "No es una digrafica simetrica\n";
	}
	return "Es una digrafica simetrica\n";
}

std::string Dirigida::euleriana(){
	if(!c||s_g == 'g')
		return "No es una digrafica elueriana\n";
	for(size_t i{};i < sumatorias_p.size();i++)
		if(sumatorias_p[i] % 2 == 1||sumatorias_n[i] % 2 == 1)
			return "No es una digrafica elueriana\n";
	return "Es una digrafica elueriana\n";
}

std::string Dirigida::unicursal(){
	int contrador{};

	if(!c||s_g == 'g')
		return "No es una digrafica unicursal\n";
	for(size_t i{};i < sumatorias_p.size();i++)
		if(sumatorias_p[i] % 2 == 1&&sumatorias_n[i] % 2 == 1)
			contrador++;
	if(contrador > 2)
		return "No es una digrafica unicursal\n";
	return "Es una digrafica unicursal\n";
}
