#include <iostream>
#include "No_Dirigida.hpp"
#include "Dirigida.hpp"

int main(){
	std::vector<std::string> n {"a","b","c","d","e","f"};
	std::vector<std::string> s {"a","b","b","c","c","d","d","d","e"};
	std::vector<std::string> e {"b","a","c","b","d","c","d","e","d"};
	//std::vector<std::string> s {"a","b","c","d","d"};
	//std::vector<std::string> e {"a","c","d","c","b"};

	//No_Dirigida a{n,e,s};
	Dirigida b{n,e,s};

	//std::cout << a.incidencia() << std::endl;
	//std::cout << a.adyacencia() << std::endl;
	//std::cout << a.grado_de_vertices() << std::endl;
	//std::cout << a.aislados() << std::endl;
	//std::cout << a.colgante() << std::endl;
	//std::cout << a.lineas_paralelas() << std::endl;
	//std::cout << a.bucles() << std::endl;
	std::cout << b.incidencia() << std::endl;
	std::cout << b.adyacencia() << std::endl;
	std::cout << b.accesibilidad() << std::endl;
	std::cout << b.grado_de_vertices() << std::endl;
	std::cout << b.aislados() << std::endl;
	std::cout << b.inicial() << std::endl;
	std::cout << b.final_() << std::endl;
	std::cout << b.lineas_paralelas() << std::endl;
	std::cout << b.bucles() << std::endl;
	
	return 0;
}
