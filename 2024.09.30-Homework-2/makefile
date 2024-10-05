CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
all: bank
bank: main.o Bank.o
	$(CXX) $(CXXFLAGS) -o bank main.o Bank.o
main.o: main.cpp Bank.h
	$(CXX) $(CXXFLAGS) -c main.cpp
Bank.o: Bank.cpp Bank.h
	$(CXX) $(CXXFLAGS) -c Bank.cpp
clean:
	rm -f *.o bank

.PHONY: all clean