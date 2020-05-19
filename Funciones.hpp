#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

#include <string>
#include <vector>

const size_t length = 8;

std::string imprimir_numero(double numero,bool espacios = true, size_t tamanio = length);
std::string imprimir_headers(std::vector<std::string> nombres, size_t tamanio = length);
std::string imprimir_vector(std::vector<double> array, std::string texto, bool enumerar, size_t tamanio = length);
std::string imprimir_vectores(std::vector<std::vector<double>> vectores, std::vector<std::string> nombres, size_t tamanio = length);
std::string imprimir_matriz(std::vector<std::vector<double>> m, size_t tamanio = length);
std::string imprimir_numero_entero(int, size_t tamanio = length);

#endif
