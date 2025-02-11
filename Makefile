CXX = g++                 # Компилятор C++
CXXFLAGS = -Wall -g        # Флаги компиляции (предупреждения, отладочная информация)
TARGET = hangman             # Имя исполняемого файла

SOURCES = src/main.cpp src/hangman.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) -lgtest -lgtest_main  # Линковка с Google Test

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(OBJECTS) $(TARGET)

run:
    ./$(TARGET)