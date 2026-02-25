TARGETS=trajectory affine matrixTest
MATRIX_LIB=matrix.o
CXXFLAGS=-g -std=c++11
LD=g++
CC=g++

all: $(TARGETS)

trajectory: $(MATRIX_LIB) trajectory.o
affine: $(MATRIX_LIB) affine.o
matrixTest: $(MATRIX_LIB) matrixTest.o

clean:
	rm -f $(TARGETS) *.o