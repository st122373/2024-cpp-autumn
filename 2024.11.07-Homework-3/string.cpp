#include "string.h"

std::pair< int, int > Helper( 0, 0 ); 

String::String(const char * str) 
{
    size = strlen(str);
    this->str = new char[size+1];
    for(size_t i = 0; i <= size; ++i)
    {
        this->str[i] = str[i];
    }
}

String::String(size_t n, char c): size(n), str(0)
{
    this->str = new char[size + 1];
    for (size_t i = 0; i < size; this->str[i] = c, ++i);
    str[size] = '\0';
}

String::~String()
{
    delete[] str;
}

String::String(const String& other) :size(other.size)
{
    str = new char[size + 1];
    strcpy(str, other.str);
}

String &String::operator=(const String &other)
{
    if (this != &other)
    {
    	delete[] this->str;
    	this->size = other.size;
        this->str = new char[this->size + 1];
        strcpy(this->str, other.str);
    }

    return *this;
}

String String::operator[](int index)
{
    if(Helper.first == 0)
    {
        String final(this->size - index, 'a');
        for(size_t i = 0; i < this->size - index; ++i)
        {
            final.str[i] = this->str[index + i];
        }
        Helper.first = 1;
        Helper.second = index;
        return final;
    }
    if(Helper.first == 1)
    {
        String final(index - Helper.second, 'a');
        for(int i = 0; i < index - Helper.second; ++i)
        {
            final.str[i] = this->str[i];
        }
        Helper.first = 0;
        return final;
    }
    return *this;
}

void String::print()
{
    for(size_t i = 0; i < strlen(this->str); ++i)
    {
        std::cout << this->str[i];
    }
    std::cout << " ";
}