#include <iostream>
#include "No_Dirigida.hpp"
#include "Dirigida.hpp"

int main(){
	std::vector<std::string> n {"a","b","c","d"};
	//std::vector<std::string> s {"b","a","a","b","c","c","d"};
	//std::vector<std::string> e {"a","a","b","c","b","d","c"};
	std::vector<std::string> s {"a","b","c","d","d"};
	std::vector<std::string> e {"a","c","d","c","b"};

	No_Dirigida a{n,e,s};
	Dirigida b{n,e,s};

	std::cout << a.incidencia() << std::endl;
	std::cout << a.adyacencia() << std::endl;
	std::cout << b.incidencia() << std::endl;
	std::cout << b.adyacencia() << std::endl;
	return 0;
}
