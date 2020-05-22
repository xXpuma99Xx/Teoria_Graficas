#include <iostream>
#include "No_Dirigida.hpp"
#include "Dirigida.hpp"

void nombres();
void borrar_pantalla();
void no_valido(bool borrar = false);

std::vector<std::vector<std::string>> capturar_datos();
int imprimir_menu(std::vector<std::string> opciones);
void menu(std::vector<std::vector<std::string>> datos);
bool numero(std::string cadena);
bool si_no(std::string texto);
bool existe(std::vector<std::string> nodos, std::string nodo);

void grafica_dirigida(std::vector<std::string> n, std::vector<std::string> e, std::vector<std::string> s);
void grafica_no_dirigida(std::vector<std::string> n, std::vector<std::string> e, std::vector<std::string> s);

template <typename T>
T mientras_no_sea_numero(std::string texto, bool borrar = true) {
	std::string respuesta;

	do {
		std::cout << texto;
		std::cin >> respuesta;
		if (!numero(respuesta))
			no_valido(borrar);
	} while (!numero(respuesta));

	return static_cast<T>(stod(respuesta));
}

int main(){
	bool repetir{};
	//std::vector<std::string> n {"a","b","c","d","e","f"};
	//std::vector<std::string> s {"a","b","b","c","c","d","d","d","e"};
	//std::vector<std::string> e {"b","a","c","b","d","c","d","e","d"};
	//std::vector<std::string> s {"a","b","c","d","d"};
	//std::vector<std::string> e {"a","c","d","c","b"};
	std::vector<std::vector<std::string>> datos;

	nombres();
	do{
		datos = capturar_datos();
		borrar_pantalla();
		menu(datos);
		repetir = si_no("Desea repetir el programa?[s/n]: ");
		borrar_pantalla();
	}while(repetir);
	return 0;
}

void grafica_dirigida(std::vector<std::string> n, std::vector<std::string> s, std::vector<std::string> e){
	Dirigida grafica {n,e,s};

	std::cout << "Matriz Incidencia\n" << grafica.incidencia() << std::endl;
	std::cout << "Matriz Adyacencia\n" << grafica.adyacencia() << std::endl;
	std::cout << "Matriz Accesibilidad\n" << grafica.accesibilidad() << std::endl;
	std::cout << grafica.grado_de_vertices() << std::endl;
	std::cout << grafica.aislados() << std::endl;
	std::cout << grafica.inicial() << std::endl;
	std::cout << grafica.final_() << std::endl;
	std::cout << grafica.lineas_paralelas() << std::endl;
	std::cout << grafica.bucles() << std::endl;
}

void grafica_no_dirigida(std::vector<std::string> n, std::vector<std::string> s, std::vector<std::string> e){
	No_Dirigida grafica{n,e,s};

	std::cout << "Matriz Incidencia\n" << grafica.incidencia() << std::endl;
	std::cout << "Matriz Adyacencia\n" << grafica.adyacencia() << std::endl;
	std::cout << "Matriz Accesibilidad\n" << grafica.accesibilidad() << std::endl;
	std::cout << grafica.incidencia() << std::endl;
	std::cout << grafica.adyacencia() << std::endl;
	std::cout << grafica.grado_de_vertices() << std::endl;
	std::cout << grafica.aislados() << std::endl;
	std::cout << grafica.colgante() << std::endl;
	std::cout << grafica.lineas_paralelas() << std::endl;
	std::cout << grafica.bucles() << std::endl;
}

std::vector<std::vector<std::string>> capturar_datos(){
	std::vector<std::string> nodos;
	std::vector<std::string> salidas;
	std::vector<std::string> entradas;
	std::string nodo;
	bool seguir{};
	int n {};

	n = mientras_no_sea_numero<int>("Cuantos nodos son? ");
	borrar_pantalla();
	for(int i {};i < n;i++){
		do{
			std::cout << "Dame el nombre del nodo " << i + 1 << ": ";
			std::cin >> nodo;
			seguir = existe(nodos,nodo);
			if(seguir)
				no_valido(true);
		} while(seguir);
		nodos.push_back(nodo);
		std::cout << std::endl;
	}
	borrar_pantalla();
	n = mientras_no_sea_numero<int>("Cuantas lineas tiene la grafica? ");
	for(int i {};i < n;i++){
		do{
			std::cout << "La linea " << i + 1 << " sale del nodo: ";
			std::cin >> nodo;
			seguir = existe(nodos,nodo);
			if(!seguir)
				no_valido(true);
		} while(!seguir);
		salidas.push_back(nodo);
		do{
			std::cout << "Y llega al nodo: ";
			std::cin >> nodo;
			seguir = existe(nodos,nodo);
			if(!seguir)
				no_valido(true);
		} while(!seguir);
		entradas.push_back(nodo);
		std::cout << std::endl;
	}

	return std::vector<std::vector<std::string>> {nodos,salidas,entradas};
}

void menu(std::vector<std::vector<std::string>> datos){
	std::vector<std::string> opciones{"Dirigida", "No dirigida"};
	int r{imprimir_menu(opciones)};

	borrar_pantalla();
	switch(r){
		case 1:
			grafica_dirigida(datos[0],datos[1],datos[2]);
			break;
		case 2:
			grafica_no_dirigida(datos[0],datos[1],datos[2]);
			break;
	}
}

int imprimir_menu(std::vector<std::string> opciones) {
	int r;
	std::string menu;

	for (size_t i{}; i < opciones.size(); i++)
		menu += (std::to_string(i + 1) + ") " + opciones[i] + "\n");
	menu += "\nElige una opcion: ";
	do {
		r = mientras_no_sea_numero<int>(menu);
		if (r < 1 || r > static_cast<int>(opciones.size()))
			no_valido(true);
	} while (r < 1 || r > static_cast<int>(opciones.size()));

	return r;
}

bool existe(std::vector<std::string> nodos, std::string nodo){
	for(size_t i{};i < nodos.size();i++)
		if(nodos[i] == nodo)
			return true;
	return false;
}

bool si_no(std::string texto) {
	std::string respuesta;

	do { std::cout << texto;
		std::cin >> respuesta;
		for (size_t i{}; i < respuesta.size(); i++)
			respuesta[i] = tolower(respuesta[i]);
		if (respuesta != "s" && respuesta != "n")
			no_valido(true);
	} while (respuesta != "s" && respuesta != "n");
	if (respuesta == "n")
		return false;
	return true;
}

bool numero(std::string cadena) {
	bool punto{false};

	for (size_t i{}; i < cadena.size(); i++) {
		if (i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			;
		else if (cadena[i] == '.') {
			if (punto == true)
				return false;
			punto = true;
		}
		else if (!isdigit(cadena[i]))
			return false;
	}

	return true;
}

void no_valido(bool borrar) {
	if (borrar)
		borrar_pantalla();
	std::cout << "Ingreso una opcion no valida. Intente de nuevo" << std::endl << std::endl;
}

void borrar_pantalla() {
	// system("cls");
	system("clear");
}

void nombres() {
	borrar_pantalla();
	std::cout << "Gómez González Astrid" << std::endl;
	std::cout << "Márquez Rosas Lemuel Helon" << std::endl;
	std::cout << "Navarro Ramos Karen" << std::endl;
	std::cout << "Pérez Romero Jonathan\n\n" << std::endl;
}
