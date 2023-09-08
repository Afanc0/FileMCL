# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11

# Source file and output executable
SRCS = main.cpp
EXEC = main

all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXEC)

clean:
	rm -f $(EXEC)

