#include <iostream>
#include "prime.h"

int main(int argc, char **argv) {

    if (argc > 1){
        int c = std::atoi(argv[1]);
        num_less(c);
        std::cout << "number of less prime numbers: " << num_less(c) << std::endl;
    }
	return 0;
}