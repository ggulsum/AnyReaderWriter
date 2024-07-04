#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "AnyWriter.h"
#include <fstream>
#include <stdexcept>

class FileWriter : public AnyWriter {
public:
    FileWriter(const std::string& filename) {
        file.open(filename, std::ios::out | std::ios::trunc);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file for writing: " + filename);
        }
    }

    ~FileWriter() {
        if (file.is_open()) {
            file.close();
        }
    }

    void putchar(int ch) override {
        file.put(static_cast<char>(ch)); // dosyaya karakter yazma
    }

private:
    std::ofstream file;
};

#endif // FILEWRITER_H
