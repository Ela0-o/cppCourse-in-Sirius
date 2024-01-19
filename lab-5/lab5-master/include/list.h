#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>

enum class IOErrors {NoFileName = -999, NoInputFile, IncorrectInputData, NoOutputFile, CannotWriteData, NoError = 0};

std::vector<int> read_vectors(const char *filename);

std::string error_name(const IOErrors &error);

namespace VecListFuncks{

    class List{

        struct Elem{
            int _data = 0;
            Elem *_next = nullptr;
        };
        Elem *_first;
        List(const List&) = delete;
        List & operator = (const List&) = delete;

        public:
            List(const std::vector<int>& res);
            // Elem *first = nullptr;
            ~List();
            void list_display() const;
            void list_erase(int num);
            void list_insert(int num, int elem);
    };
}

#endif