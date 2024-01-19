#include "vector.h"
#include <iostream>
#include <vector>

int main(int argc, char **argv) {
    std::vector<float> v = {-1.9f, -5.78f, 3.6f, 1.05f, 10.0f};
    std::vector<int> w = {-1, -2, 5, 2, 3, 1, 10, 4};
    if (argc > 1){
        float c = std::atoi(argv[1]);
        vector(v, c);
    }
    vector(w);
	return 0;
}