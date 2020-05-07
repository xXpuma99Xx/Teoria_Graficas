#include<iostream>


void no_valido(bool borrar = true);
std::string si_no(std::string texto, bool borrar = true);
void borrar_pantalla();
void lower(std::string &texto);
std::string mientras_no_sea_numero(std::string, bool borrar = true);
bool numero(std::string cadena);
void nombres();

int main(){
	return 0;
}

std::string mientras_no_sea_numero(std::string texto, bool borrar) {
	std::string aux;

	do {
		std::cout << texto;
		std::cin >> aux;
		if (!numero(aux))
			no_valido(borrar);
	} while (!numero(aux));

	return aux;
}

std::string si_no(std::string texto, bool borrar) {
	std::string respuesta;

	do {
		std::cout << texto;
		std::cin >> respuesta;
		lower(respuesta);
		if (respuesta != "s" && respuesta != "n")
			no_valido(borrar);
	} while (respuesta != "s" && respuesta != "n");

	return respuesta;
}

bool numero(std::string cadena) {
	bool punto{false};

	for (size_t i{}; i < cadena.size(); i++) {
		if (cadena[i] == '-' || cadena[i] == '+'){
			if(i != 0)
				return false;
		} else if (cadena[i] == '.') {
			if (punto == true)
				return false;
			punto = true;
		} else if (!isdigit(cadena[i])) 
			return false;
	}

	return true;
}

void lower(std::string &texto) {
	for (size_t i{}; i < texto.size(); i++)
		texto[i] = tolower(texto[i]);
}

void no_valido(bool borrar) {
	if (borrar)
		borrar_pantalla();
	std::cout << "Ingreso una opcion no valida. Intente de nuevo" << std::endl << std::endl;
}

void borrar_pantalla() {
	system("cls");
	// system("clear");
}

void nombres() {
	borrar_pantalla();
	std::cout << "Gómez González Astrid" << std::endl;
	std::cout << "Márquez Rosas Lemuel Helon" << std::endl;
	std::cout << "Navarro Ramos Karen" << std::endl;
	std::cout << "Pérez Romero Jonathan " << std::endl;
}
