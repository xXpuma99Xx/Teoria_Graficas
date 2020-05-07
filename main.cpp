#include <iostream>
#include "No_Dirigida.hpp"
#include "Dirigida.hpp"

int main(){
	std::vector<std::string> n {"a","b","c","d","e"};
	std::vector<std::string> s {"a","b","b","c","d","a","b","a"};
	std::vector<std::string> e {"b","a","c","d","a","c","d","a"};

	No_Dirigida a{n,e,s};
	Dirigida b{n,e,s};

	std::cout << a.incidencia() << std::endl;
	std::cout << b.incidencia() << std::endl;
	return 0;
}
