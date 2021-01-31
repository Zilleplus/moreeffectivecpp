CXX=clang++
CFLAGS=-std=c++17 -Wall

all: RCObject.o string.o main.cpp
	$(CXX) ${CFLAGS} -o main.out $? -I.
	
RCObject.o : RCObject.cpp RCObject.h
	$(CXX) ${CFLAGS} -c RCObject.cpp

string.o :  string.cpp string.h RCObject.o
	$(CXX) ${CFLAGS} -c string.cpp 

RCPtr : RCPtr.h
	$(CXX) ${CFLAGS} -fsyntax-only RCPtr.h

clean:
	rm -f *.o
	rm -f main.out
