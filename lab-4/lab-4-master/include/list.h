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

<<<<<<< HEAD
        public:
            List(const std::vector<int>& res);
            // Elem *first = nullptr;
            ~List();
            void list_display();
            void list_erase(int num);
            void list_insert(int num, int elem);
    };
}
=======
    // void list_push_back(List& l, int a);
    void list_from_vector(List& l, const std::vector<int>& res);
    void list_display(const List& l);
    void list_erase(List& l, int num);
    void list_insert(List& l, int num, int elem);
    void list_clear(List& l);
    }
>>>>>>> 46ad618dfa8bb942c8ec611280248c7ed62575a6

#endif
