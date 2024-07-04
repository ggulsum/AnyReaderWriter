#ifndef TERMINALWRITER_H
#define TERMINALWRITER_H

#include "AnyWriter.h"
#include <iostream>

class TerminalWriter : public AnyWriter {
public:
    void putchar(int ch) override {
        std::cout.put(static_cast<char>(ch)); // terminale karakter yazma
    }
};

#endif // TERMINALWRITER_H

