CXX=g++
CFLAGS=-Wall -O2 -std=c++11

all:
	$(CXX) programa.cpp -o ejecutar $(CFLAGS)
	./ejecutar	
