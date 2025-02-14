#ifndef DATASET_H
#define DATASET_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>

class Dataset {
private:
    std::vector<std::vector<std::string>> data;  // Хранение данных в виде таблицы
    std::vector<std::string> column_names;       // Названия столбцов
    bool has_index;                              // Флаг, указывающий на наличие индекса
    size_t size;                                 // Размер датасета (количество строк)

public:
    // Конструктор, принимающий путь к файлу и дополнительные параметры
    Dataset(const std::string& file_path, bool has_header = true, bool has_index = false, const std::vector<std::string>& column_names = {});

    // Метод для загрузки данных из файла
    void load_data(const std::string& file_path, bool has_header, const std::vector<std::string>& column_names);

    // Метод для разделения строки по разделителю
    std::vector<std::string> split(const std::string& s, char delimiter);

    // Метод head для вывода первых n строк
    void head(int n = 5) const;

    // Метод tail для вывода последних n строк
    void tail(int n = 5) const;

    // Метод для вывода строк в диапазоне [start, end)
    void print_rows(size_t start, size_t end) const;

    // Метод для добавления строки по индексу
    void insert(size_t index, const std::vector<std::string>& row);

    // Метод для удаления строки по индексу
    void remove(size_t index);

    // Метод для вычисления статистики по столбцу
    void describe(const std::string& column_name) const;

    // Метод для получения индекса столбца по его имени
    size_t get_column_index(const std::string& column_name) const;

    // Метод для конвертации столбца в числовой формат
    std::vector<double> convert_column_to_numeric(size_t col_index) const;

    // Перегрузка оператора [] для доступа к строкам и элементам
    std::vector<std::string>& operator[](size_t index);
    const std::vector<std::string>& operator[](size_t index) const;

    // Метод для получения размера датасета
    size_t get_size() const;
};

#endif // DATASET_H