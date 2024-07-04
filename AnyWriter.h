#ifndef ANYWRITER_H
#define ANYWRITER_H

class AnyWriter {
public:
    virtual void putchar(int ch) = 0; // sanal fonksiyon: yazma işlemi
    virtual ~AnyWriter() {}
};

#endif // ANYWRITER_H

