#ifndef FILEREADER_H
#define FILEREADER_H

#include "AnyReader.h"
#include <fstream>
#include <stdexcept>

class FileReader : public AnyReader {
public:
    FileReader(const std::string& filename) : filename(filename), file(filename) {
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file for reading: " + filename);
        }
    }

    int getchar() const override {
        if (!file) {
            return EOF;
        }
        return file.get(); // dosyadan karakter okuma
    }

private:
    std::string filename;
    mutable std::ifstream file; 
};

#endif // FILEREADER_H
