CXX=g++
CFLAGS=-Wall -O2 -std=c++11

all:
	$(CXX) lectura.cpp -o hola $(CFLAGS)
