#include <iostream>
#include <vector>
#include "list.h"

using namespace VecListFuncks;

int main(int argc, char **argv) {
    try{
        if (argc < 2){
            throw IOErrors::NoFileName;
        }
        auto res = read_vectors(argv[1]);
        List l(res);
        l.list_display();
        int num1;
        int elem;
        int num2;
        std::cout<<"Куда запихнуть какой элемент:";
        std::cin >> num1 >> elem;       
        std::cout<<"Какой элемент удалить:";
        std::cin >> num2;
            
        l.list_insert(num1, elem);
        l.list_display();

        l.list_erase(num2);
        l.list_display();

        l.~List();
        l.list_display();
        return 0;
    }
    catch(const IOErrors& error){
        std::cerr << error_name(error) << std::endl;
        return -1;
    }
}