CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = main.exe
OBJS = main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp AnyReader.h AnyWriter.h KeyboardReader.h TerminalWriter.h FileReader.h FileWriter.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	del $(OBJS) $(TARGET)
