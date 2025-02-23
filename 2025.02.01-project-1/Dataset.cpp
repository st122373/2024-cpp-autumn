#include "Dataset.h"

Dataset::Dataset(const std::string& file_path, bool has_header, bool has_index, const std::vector<std::string>& column_names)
    : has_index(has_index) {
    load_data(file_path, has_header, column_names);
}

void Dataset::load_data(const std::string& file_path, bool has_header, const std::vector<std::string>& column_names) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + file_path);
    }
    std::string line;
    if (has_header) {
        std::getline(file, line);
        this->column_names = split(line, ',');
    } else if (!column_names.empty()) {
        this->column_names = column_names;
    } else {

        for (size_t i = 0; i < this->column_names.size(); ++i) {
            this->column_names.push_back("Column_" + std::to_string(i));
        }
    }
    while (std::getline(file, line)) {
        std::vector<std::string> row = split(line, ',');
        data.push_back(row);
    }
    size = data.size();
}

std::vector<std::string> Dataset::split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void Dataset::head(int n) const {
    print_rows(0, n);
}

void Dataset::tail(int n) const {
    print_rows(size - n, size);
}

void Dataset::print_rows(size_t start, size_t end) const {
    if (start >= size || end > size) {
        throw std::out_of_range("Некорректный диапазон строк");
    }
    if (has_index) {
        std::cout << "Index\t";
    }
    for (const auto& name : column_names) {
        std::cout << name << "\t";
    }
    std::cout << std::endl;
    for (size_t i = start; i < end; ++i) {
        if (has_index) {
            std::cout << i << "\t";
        }
        for (const auto& cell : data[i]) {
            std::cout << cell << "\t";
        }
        std::cout << std::endl;
    }
}

void Dataset::insert(size_t index, const std::vector<std::string>& row) {
    if (index > size) {
        throw std::out_of_range("Некорректный индекс для вставки");
    }
    data.insert(data.begin() + index, row);
    size++;
}

void Dataset::remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Некорректный индекс для удаления");
    }
    data.erase(data.begin() + index);
    size--;
}

void Dataset::describe(const std::string& column_name) const {
    size_t col_index = get_column_index(column_name);
    std::vector<double> numeric_data = convert_column_to_numeric(col_index);
    double max_value = numeric_data[0];
    double min_value = numeric_data[0];
    double sum = 0.0;
    double mean = 0.0;
    double std_dev = 0.0;
    for (const auto& value : numeric_data) {
        if (value > max_value) max_value = value;
        if (value < min_value) min_value = value;
        sum += value;
    }
    mean = sum / numeric_data.size();
    for (const auto& value : numeric_data) {
        std_dev += (value - mean) * (value - mean);
    }
    std_dev = std::sqrt(std_dev / numeric_data.size());
    std::cout << "Статистика для столбца " << column_name << ":" << std::endl;
    std::cout << "Максимальное значение: " << max_value << std::endl;
    std::cout << "Минимальное значение: " << min_value << std::endl;
    std::cout << "Среднее значение: " << mean << std::endl;
    std::cout << "Стандартное отклонение: " << std_dev << std::endl;
}

size_t Dataset::get_column_index(const std::string& column_name) const {
    for (size_t i = 0; i < column_names.size(); ++i) {
        if (column_names[i] == column_name) {
            return i;
        }
    }
    throw std::invalid_argument("Столбец с именем " + column_name + " не найден");
}

std::vector<double> Dataset::convert_column_to_numeric(size_t col_index) const {
    std::vector<double> numeric_data;
    for (const auto& row : data) {
        try {
            numeric_data.push_back(std::stod(row[col_index]));
        } catch (const std::invalid_argument&) {
            throw std::runtime_error("Столбец содержит нечисловые данные");
        }
    }
    return numeric_data;
}

std::vector<std::string>& Dataset::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Некорректный индекс");
    }
    return data[index];
}

const std::vector<std::string>& Dataset::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Некорректный индекс");
    }
    return data[index];
}

size_t Dataset::get_size() const {
    return size;
}
