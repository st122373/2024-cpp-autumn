CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -I/usr/include/gtest
LDFLAGS = -lgtest -lgtest_main -pthread

SOURCES = main.cpp TextEditor.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = texteditor

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
