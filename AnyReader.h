#ifndef ANYREADER_H
#define ANYREADER_H

class AnyReader {
public:
    virtual int getchar() const = 0; //  sanal fonksiyon: okuma islemi
    virtual ~AnyReader() {}
};

#endif // ANYREADER_H

