CXX=g++
CXXFLAGS=-Wall -Wextra -Wswitch -pedantic -O2 -std=c++20
OBJ=build/snemu.o

snemu: build build/snemu.o
	${CXX} ${CXXFLAGS} ${OBJ} -o snemu

build:
	mkdir -p build/

build/snemu.o: src/snemu.cpp src/args.h
	$(CXX) $(CXXFLAGS) -c src/snemu.cpp -o build/snemu.o

clean:
	rm -rf snemu build
