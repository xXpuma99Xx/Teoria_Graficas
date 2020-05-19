#include <sstream>
#include <iomanip>
#include "Funciones.hpp"

std::string imprimir_numero(double numero, bool espacios, size_t tamanio) {
	std::stringstream stream;

	stream << std::fixed << std::setprecision(12) << numero;

	std::string numero_string{stream.str()};

	if (numero_string.size() > tamanio)
		numero_string = numero_string.substr(0, tamanio);
	for (size_t i{}; i < numero_string.size(); i++) {
		if (numero_string[i] == '.') {
			unsigned contador{};

			for (size_t j = i + 1; j < numero_string.size(); j++) {
				if (numero_string[j] == '0')
					contador++;
				else {
					i = j;
					contador = 0;
				}
			}
			if (contador > 0)
				numero_string = numero_string.erase(i + 1, contador);
			break;
		}
	}
	if (numero_string[numero_string.size() - 1] == '.')
		numero_string.erase(numero_string.size() - 1);
	if (numero_string.size() < tamanio&&espacios) {
		for (size_t i{numero_string.size()}; i < tamanio; i++)
			numero_string += " ";
	}

	return numero_string;
}

std::string imprimir_headers(std::vector<std::string> nombres, size_t tamanio) {
	size_t n{nombres.size()};
	std::string headers{};
	std::string linea{};

	for (size_t i{}; i < n; i++) {
		linea += "+";
		for (size_t j{}; j < tamanio; j++)
			linea += "-";
	}
	linea += "+\n";
	headers = linea + "|";
	for (size_t i{}; i < n; i++) {
		std::string celda{nombres[i]};
		int espacios_izquierda{static_cast<int>((tamanio - nombres[i].size()) / 2)};
		int espacios_derecha{((tamanio - nombres[i].size()) % 2) == 0 ? espacios_izquierda : espacios_izquierda + 1};

		for (int j{}; j < espacios_izquierda; j++)
			celda = " " + celda;
		for (int j{}; j < espacios_derecha; j++)
			celda += " ";
		headers = headers + celda + "|";
	}

	return headers + "\n" + linea;
}

std::string imprimir_vector(std::vector<double> array, std::string texto, bool enumerar, size_t tamanio) {
	std::vector<std::string> nombres{texto};
	std::string tabla{imprimir_headers(nombres)};

	for (size_t i{}; i < array.size(); i++) {
		if (enumerar)
			tabla = tabla + "|" + imprimir_numero(array[i]) + "| " + std::to_string(i) + "\n";
		else
			tabla = tabla + "|" + imprimir_numero(array[i]) + "|\n";
	}
	tabla += "+";
	for (size_t j{}; j < tamanio; j++)
		tabla += "-";

	return tabla + "+\n";
}

std::string imprimir_vectores(std::vector<std::vector<double>> vectores, std::vector<std::string> nombres, size_t tamanio) {
	std::string tabla{imprimir_headers(nombres)};
	std::string linea;
	std::string espacios;
	size_t filas{vectores[0].size()};
	size_t columnas{vectores.size()};

	for (size_t j{}; j < tamanio; j++) {
		linea += "-";
		espacios += " ";
	}
	for (size_t i{}; i < filas + 1; i++) {
		std::string fila;

		for (size_t j{}; j < columnas; j++) {
			if (i < vectores[j].size()) {
				if (j == 0 || fila[fila.size() - 1] == '-' || fila[fila.size() - 1] == ' ')
					fila = fila + "|" + imprimir_numero(vectores[j][i]) + "|";
				else
					fila = fila + imprimir_numero(vectores[j][i]) + "|";
			}
			else if (i == vectores[j].size()) {
				if (j == 0 || fila[fila.size() - 1] == '-' || fila[fila.size() - 1] == ' ')
					fila += "+" + linea;
				else if (fila[fila.size() - 1] == '|')
					fila += linea;
				if (j == columnas - 1)
					fila += "+";
			}
			else if (i > vectores[j].size()) {
				if (fila[fila.size() - 1] == '-')
					fila += "+" + espacios;
				else if (fila[fila.size() - 1] == '|')
					fila += espacios;
				else if (fila[fila.size() - 1] == ' ')
					fila += " " + espacios;
			}
		}
		tabla = tabla + fila + "\n";
	}

	return tabla + "\n";
}

std::string imprimir_matriz(std::vector<std::vector<double>> m, size_t tamanio) {
	std::string tabla;
	std::string linea;

	for (size_t i{}; i < m[0].size(); i++) {
		linea += "+";
		for (size_t j{}; j < tamanio; j++)
			linea += "-";
	}
	linea += "+\n";
	tabla += linea;
	for (size_t i{}; i < m.size(); i++) {
		std::string fila{"|"};

		for (size_t j{}; j < m[i].size(); j++)
			fila += imprimir_numero(m[i][j]) + "|";
		tabla += fila + "\n" + linea;
	}

	return tabla;
}

std::string imprimir_numero_entero(int numero, size_t tamanio){
	std::string numero_str {std::to_string(numero)};
	
	if(numero_str.size() < tamanio){
		for(size_t i {};i <= tamanio - numero_str.size();i++)
			numero_str = " " + numero_str;
	}

	return numero_str;
}
