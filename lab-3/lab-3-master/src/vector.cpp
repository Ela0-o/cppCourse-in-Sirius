#include <iostream>
#include "vector.h"
#include <vector>
#include <algorithm>

void vector(std::vector<float>& v, float c){
	std::cout << "[";
	int elem = 0;
	while(elem < v.size()){
		if (v[elem] < 0 || v[elem] < c)
			v.erase(v.begin() + elem);
		else 
			elem++;
	}
	for (int elem = 0; elem < v.size(); elem++)
		std::cout << v[elem] << "  ";	
	std::cout << "]" << std::endl;
}

void vector(std::vector<int>& w){
	std::cout << "[";
	std::vector<int> v;
	for (int elem : w){
		if (elem %2 == 0){
			v.push_back(elem);
		}
	}
	w.insert(w.end(), v.begin(), v.end());
	for (int elem : w){
		std::cout << elem << "  ";
	}
	std::cout << "]" << std::endl;
}

// Для std::vector с числами с плавающей запятой удаляет или все значения меньшие 0, или все значения меньшие заданной константы.
// Для std::vector с целыми числами для каждого чётного числа добавляет такое же в конец.