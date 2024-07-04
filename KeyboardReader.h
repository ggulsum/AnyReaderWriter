#ifndef KEYBOARDREADER_H
#define KEYBOARDREADER_H

#include "AnyReader.h"
#include <iostream>

class KeyboardReader : public AnyReader {
public:
    int getchar() const override {
        return std::cin.get(); // klavyeden karakter okuma
    }
};

#endif // KEYBOARDREADER_H

