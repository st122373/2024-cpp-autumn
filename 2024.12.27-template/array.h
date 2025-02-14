#include <iostream>

template <class T>
class Array
{
private:
    static const int size = 5;
    T array[size];

public:
    Array() {}
    Array(T* b); 
    void show(); 
    T minimum();
};

template<class T>
Array<T>::Array(T* b)
{
    for(int i = 0; i < size; ++i)
    {
        array[i] = b[i];
    }
}

template<class T>
void Array<T>::show()
{
    std::cout << "[";

    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i];
    }

} 

template<class T>
T Array<T>::minimum()
{
    T min = array[0];
    for (int i = 1; i < size; ++i)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}
