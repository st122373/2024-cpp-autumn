CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: dataset

dataset: main.o Dataset.o
	$(CXX) $(CXXFLAGS) -o dataset main.o Dataset.o

main.o: main.cpp Dataset.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Dataset.o: Dataset.cpp Dataset.h
	$(CXX) $(CXXFLAGS) -c Dataset.cpp

clean:
	rm -f *.o dataset

.PHONY: all clean