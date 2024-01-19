#include <iostream>
#include "prime.h"
#include <cmath>

bool number(int c){

	if (c < 2)
		return false;
	for(int i = 2; i <= c/i; ++i){
		if (c % i == 0)
			return false;
	} 

	return true;
}

void prime(void) {
	std::cout << "write a number" << std::endl;
	int c;
	std::cin >> c;

	if (number(c))
		std::cout << "prime" << std::endl;
	else
		std::cout << "not prime" << std::endl;	
}