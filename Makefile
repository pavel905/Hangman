CXX = g++
CXXFLAGS = -Wall -g
TARGET = hangman

SOURCES = main.cpp hangman.cpp
OBJECTS = main.o hangman.o

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

hangman.o: hangman.cpp
	$(CXX) $(CXXFLAGS) -c hangman.cpp -o hangman.o

clean:
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)