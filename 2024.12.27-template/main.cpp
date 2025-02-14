#include "array.h"

int main()
{
    int arr[] = {5, 3, 8, 1, 4};
    Array<int> myArray(arr);
    myArray.show();
    std::cout << "Minimum element: " << myArray.minimum() << std::endl;

    return 0;
}
