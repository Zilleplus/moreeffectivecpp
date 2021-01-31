CXX=clang++
CFLAGS=-std=c++17 -Wall

all: counted.out
	
counted.out : counted.cpp
	$(CXX) ${CFLAGS} counted.cpp -o counted.out

clean:
	rm -f *.o
	rm -f *.out
