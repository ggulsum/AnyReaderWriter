# AnyReaderWriter Projesi

## Genel Bakış
Bu proje, C++ dilinde farklı kaynaklardan okuma ve farklı hedeflere yazma işlemlerini gerçekleştiren basit bir çerçeve sunmaktadır. Proje, karakter okuma ve yazma işlemleri için soyut temel sınıflar olan AnyReader ve AnyWriter'ı tanımlar. Klavyeden okuma, dosyalardan okuma, terminale yazma ve dosyalara yazma işlemleri için uygulamalar içermektedir. Ayrıca, bir AnyReader nesnesinden veri okuyup bir AnyWriter nesnesine yazan basit bir kopyalama fonksiyonu bulunmaktadır.

## Sınıf Tanımları
Proje aşağıdaki bileşenlerden oluşmaktadır:

### AnyReader
Karakter okuma işlemi için soyut bir temel sınıftır. Türetilecek sınıflar tarafından uygulanması gereken saf bir sanal fonksiyon olan `getchar()` fonksiyonunu tanımlar.

### AnyWriter
Karakter yazma işlemi için soyut bir temel sınıftır. Türetilecek sınıflar tarafından uygulanması gereken saf bir sanal fonksiyon olan `putchar()` fonksiyonunu tanımlar.

### FileReader
Dosyalardan karakter okuma işlemi için AnyReader sınıfından türetilmiş somut bir sınıftır.

### FileWriter
Dosyalara karakter yazma işlemi için AnyWriter sınıfından türetilmiş somut bir sınıftır.

### KeyboardReader
Klavyeden karakter okuma işlemi için AnyReader sınıfından türetilmiş somut bir sınıftır.

### TerminalWriter
Terminale karakter yazma işlemi için AnyWriter sınıfından türetilmiş somut bir sınıftır.

### copy Fonksiyonu
Bir AnyReader nesnesinden veri okuyup bir AnyWriter nesnesine veri yazan fonksiyondur.

## Kullanım
`main` fonksiyonu, sınıfların ve `copy` fonksiyonunun kullanımını gösterir. Üç işlem gerçekleştirilir:

1. Klavyeden okuma ve dosyaya yazma (`output.txt`).
2. Dosyadan okuma (`output.txt`) ve terminale yazma.
3. `output.txt` dosyasının içeriğini başka bir dosyaya (`output-copy.txt`) kopyalama.

## Projenin Derlenmesi

### Windows'ta
Projeyi Windows'ta derlemek için aşağıdaki komutları kullanabilirsiniz:

```sh
mingw32-make
```
Derlemeden sonra dosyayı çalıştırmak için:

```sh
main.exe
```

Temizleme işlemi yapmak isterseniz:

```sh
mingw32-make clean
```

### Linux'ta
Linux için repoda yer alan Makefile yerine bunu kullanmalısınız :

```sh
# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = main

# Source files
SRCS = main.cpp

# Header files
HDRS = AnyReader.h AnyWriter.h KeyboardReader.h FileReader.h TerminalWriter.h FileWriter.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compilation
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $<

# Clean up
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: all clean

```

Projeyi Linux'ta derlemek için aşağıdaki komutları kullanabilirsiniz:

```sh
make
```
Derlemeden sonra dosyayı çalıştırmak için:

```sh
./main
```

Temizleme işlemi yapmak isterseniz:

```sh
 rm -f *.o main
```

