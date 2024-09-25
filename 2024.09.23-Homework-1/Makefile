
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
all: texteditor
texteditor: main.o TextEditor.o
	$(CXX) $(CXXFLAGS) -o texteditor main.o TextEditor.o
main.o: main.cpp TextEditor.h
	$(CXX) $(CXXFLAGS) -c main.cpp
TextEditor.o: TextEditor.cpp TextEditor.h
	$(CXX) $(CXXFLAGS) -c TextEditor.cpp
clean:
	rm -f *.o texteditor

.PHONY: all clean
