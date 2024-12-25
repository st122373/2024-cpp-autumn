#ifndef STRING_H
#define STRING_H 

#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
    private:
        size_t size; // Размер строки
        char *str; // Указатель на массив символов (строку)

    public:
        String(const char *str = "");
        String(size_t n, char c);
        ~String();

        String(const String &other);
        String &operator=(const String &other);

        String operator[](int index);

        void print();  
};
#endif //STRING_H