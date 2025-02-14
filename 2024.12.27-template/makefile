CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: array

array: main.o 
	$(CXX) $(CXXFLAGS) -o array main.o

main.o: main.cpp array.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o array

.PHONY: all clean