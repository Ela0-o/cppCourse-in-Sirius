#include <iostream>
#include "list.h"

using namespace VecListFuncks;

VecListFuncks::List::List(const std::vector<int>& res) {

    _first = new Elem;
    _first->_data = res[0];
    _first->_next = nullptr;

    Elem *current = _first;

    for (int num = 1; num < res.size(); num++) {

        Elem *new_elem = new Elem;
        new_elem->_data = res[num];
        new_elem->_next = nullptr;

        current->_next = new_elem;
        current = current->_next;
    }
}


// вывод всех элементов списка на экран
void VecListFuncks::List::list_display() const{
    Elem* current = _first;
    while (current != nullptr) {
        std::cout << current->_data << " ";
        current = current->_next;
    }
    std::cout << std::endl;
}

// удаление элемента с заданным номером
void VecListFuncks::List::list_erase(int num){
    if (_first == nullptr) {
        std::cerr << "Нельзя удалить то, чего нет......." << std::endl;
        return;
    }

    if (num == 0) {
        Elem* temp = _first;
        _first = _first->_next;
        delete temp;
    } 
    else{
        Elem* current = _first;
        for (int i = 0; (i < num - 1) && (current != nullptr); i++) {
            current = current->_next;
        }
        if ((current != nullptr) && (current->_next != nullptr)) {
            Elem* temp = current->_next;
            current->_next = current->_next->_next;
            delete temp;
        } 
        else {
            std::cerr << "Нельзя удалить больше чем то, что есть в списке......." << std::endl;
        }
    }
}

// добавление элемента с заданным значением в указанную позицию
void VecListFuncks::List::list_insert(int num, int elem){

    Elem* new_elem = new Elem;
    new_elem->_data = elem;
    new_elem->_next = nullptr;

    if (num == 0) {
        new_elem->_next = _first;
        _first = new_elem;
    } 
    else {
        Elem* current = _first;
        for (int i = 0; (i < num - 1) && (current != nullptr); i++) {
            current = current->_next;
        }
        if (current != nullptr) {
            new_elem->_next = current->_next;
            current->_next = new_elem;
        } 
        else {
            std::cerr << "Нет такой позиции ..." << std::endl;
            delete new_elem;
        }
    }
}

// Функция для очистки списка
VecListFuncks::List::~List(){
    while (_first != nullptr) {
        Elem* temp = _first;
        _first = _first->_next;
        delete temp;
    }
}
