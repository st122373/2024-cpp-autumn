#include "Dataset.h"

int main() {
    try {
        Dataset dataset("test_data.csv", true, true);

        std::cout << "Первые 3 строки:" << std::endl;
        dataset.head(3);

        std::cout << "\nПоследние 2 строки:" << std::endl;
        dataset.tail(2);

        std::cout << "\nДобавляем новую строку:" << std::endl;
        dataset.insert(2, {"2", "Frank", "28", "55000"});
        dataset.head();

        std::cout << "\nУдаляем строку с индексом 1:" << std::endl;
        dataset.remove(1);
        dataset.head();

        std::cout << "\nСтатистика по столбцу Age:" << std::endl;
        dataset.describe("Age");

        std::cout << "\nДоступ к элементу [2][1]: " << dataset[2][1] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}