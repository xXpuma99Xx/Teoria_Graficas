#include <iostream>
#include "No_Dirigida.hpp"
#include "Dirigida.hpp"

int main(){
	std::vector<std::string> n {"a","b","c","d","e","f","g","h"};
	std::vector<std::string> s {"b","a","a","b","c","c","d","f","f","f","f","h"};
	std::vector<std::string> e {"a","a","b","c","b","d","c","a","g","g","g","a"};
	//std::vector<std::string> s {"a","b","c","d","d"};
	//std::vector<std::string> e {"a","c","d","c","b"};

	No_Dirigida a{n,e,s};
	//Dirigida b{n,e,s};

	std::cout << a.incidencia() << std::endl;
	std::cout << a.adyacencia() << std::endl;
	std::cout << a.grado_de_vertices() << std::endl;
	std::cout << a.aislados() << std::endl;
	std::cout << a.colgante() << std::endl;
	std::cout << a.lineas_paralelas() << std::endl;
	std::cout << a.bucles() << std::endl;
	//std::cout << b.incidencia() << std::endl;
	//std::cout << b.adyacencia() << std::endl;
	//std::cout << b.incidencia() << std::endl;
	//std::cout << b.adyacencia() << std::endl;
	//std::cout << b.grado_de_vertices() << std::endl;
	//std::cout << b.aislados() << std::endl;
	//std::cout << b.inicial() << std::endl;
	//std::cout << b.final_() << std::endl;
	
	return 0;
}
