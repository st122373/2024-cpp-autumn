CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
all: str
str: main.o string.o
	$(CXX) $(CXXFLAGS) -o str main.o string.o
main.o: main.cpp string.h
	$(CXX) $(CXXFLAGS) -c main.cpp
string.o: string.cpp string.h
	$(CXX) $(CXXFLAGS) -c string.cpp
clean:
	rm -f *.o str

.PHONY: all clean