#include <iostream>
#include "prime.h"


bool number(int c){

	if (c < 2)
		return false;
	for(int i = 2; i <= c/i; ++i){
		if (c % i == 0)
			return false;
	} 
	return true;
}

int num_less(int a){

	int n = 0;
	int b = 0;
	
	if (a >= 2){

		while (b <= a) {
			if (number(b))
				n++;
			b++;
		}
	}
	else
		n = 0;
	return n;
}
