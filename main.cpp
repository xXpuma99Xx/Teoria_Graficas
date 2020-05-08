#include <iostream>
#include "No_Dirigida.hpp"
#include "Dirigida.hpp"

int main(){
	std::vector<std::string> n {"a","b","c","d"};
	std::vector<std::string> s {"b","a","a","b","c","c","d"};
	std::vector<std::string> e {"a","a","b","c","b","d","c"};

	//No_Dirigida a{n,e,s};
	Dirigida b{n,e,s};

	//std::cout << a.incidencia() << std::endl;
	std::cout << b.incidencia() << std::endl;
	for(auto i:b.sumatorias_p)
		std::cout << i << " ";
	std::cout << std::endl;
	for(auto i:b.sumatorias_n)
		std::cout << i << " ";
	return 0;
}
