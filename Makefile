# Define the compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -g

# Define the object files
OBJECTS = star.o asteroid.o game.o main.o termfuncs.o dot.o boulder.o

# Define the final executable
TARGET = star

# Default target
all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)
	chmod g+rwx $(TARGET)

# Rules for creating object files
star.o: star.cpp star.h constants.h termfuncs.h
	$(CXX) $(CXXFLAGS) -c star.cpp
	chmod g+rw star.o

asteroids.o: asteroid.cpp asteroids.h constants.h termfuncs.h
	$(CXX) $(CXXFLAGS) -c asteroid.cpp
	chmod g+rw asteroid.o

game.o: game.cpp *.h
	$(CXX) $(CXXFLAGS) -c game.cpp
	chmod g+rw game.o

main.o: main.cpp constants.h termfuncs.h
	$(CXX) $(CXXFLAGS) -c main.cpp
	chmod g+rw main.o

boulder.o: boulder.cpp boulder.h termfuncs.h constants.h
	$(CXX) $(CXXFLAGS) -c boulder.cpp
	chmod g+rw boulder.o

dot.o: dot.cpp dot.h constants.h termfuncs.h
	$(CXX) $(CXXFLAGS) -c dot.cpp
	chmod g+rw dot.o

termfuncs.o: termfuncs.cpp termfuncs.h
	$(CXX) $(CXXFLAGS) -c termfuncs.cpp
	chmod g+rw termfuncs.o

# Clean up build artifacts
clean:
	rm -f *.o $(TARGET)

