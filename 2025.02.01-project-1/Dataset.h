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
    std::vector<std::vector<std::string>> data;
    std::vector<std::string> column_names;
    bool has_index;
    size_t size;

public:

    Dataset(const std::string& file_path, bool has_header = true, bool has_index = false, const std::vector<std::string>& column_names = {});

    void load_data(const std::string& file_path, bool has_header, const std::vector<std::string>& column_names);

    std::vector<std::string> split(const std::string& s, char delimiter);

    void head(int n = 5) const;

    void tail(int n = 5) const;

    void print_rows(size_t start, size_t end) const;

    void insert(size_t index, const std::vector<std::string>& row);

    void remove(size_t index);

    void describe(const std::string& column_name) const;

    size_t get_column_index(const std::string& column_name) const;

    std::vector<double> convert_column_to_numeric(size_t col_index) const;

    std::vector<std::string>& operator[](size_t index);
    const std::vector<std::string>& operator[](size_t index) const;

    size_t get_size() const;
};

#endif // DATASET_H
