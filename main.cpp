#include "KeyboardReader.h"
#include "FileReader.h"
#include "TerminalWriter.h"
#include "FileWriter.h"
#include "AnyReader.h"
#include "AnyWriter.h"
#include <iostream>
#include <string>
bool copy(const AnyReader& reader, AnyWriter& writer) {
    int ch = reader.getchar();
    while (ch != EOF) {
        writer.putchar(ch);
        ch = reader.getchar();
    }
    return true;
}

int main() {
    // Klavyeden okuma ve dosyaya yazma
    {
        KeyboardReader keyboard;
        FileWriter fileWriter("output.txt");

        std::cout << "Enter text (press Enter then type END to finish):" << std::endl;
        std::string line;
        while (true) {
            std::getline(std::cin, line);
            if (line == "END") {
                break;
            }
            for (char ch : line) {
                fileWriter.putchar(ch);
            }
            fileWriter.putchar('\n');
        }
        std::cout << "Finished writing to output.txt" << std::endl;
    }

    // output.txt dosyasını terminale yazma
    {
        FileReader fileReader("output.txt");
        TerminalWriter terminal;

        copy(fileReader, terminal);
        std::cout << "Finished reading from output.txt and writing to terminal" << std::endl;
    }

    // output.txt dosyasını output-copy.txt dosyasına kopyalama
    {
        FileReader fileReader("output.txt");
        FileWriter fileWriter("output-copy.txt");

        copy(fileReader, fileWriter);
        std::cout << "Finished copying from output.txt to output-copy.txt" << std::endl;
    }

    return 0;
}
