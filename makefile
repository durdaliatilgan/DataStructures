all: build link run


build:
	g++ -I ./include/ -o ./lib/Cell.o -c ./src/Cell.cpp
	g++ -I ./include/ -o ./lib/Radix.o -c ./src/Radix.cpp
	g++ -I ./include/ -o ./lib/Queue.o -c ./src/Queue.cpp
	g++ -I ./include/ -o ./lib/Tissue.o -c ./src/Tissue.cpp
	g++ -I ./include/ -o ./lib/Organism.o -c ./src/Organism.cpp
	g++ -I ./include/ -o ./lib/Organ.o -c ./src/Organ.cpp
	g++ -I ./include/ -o ./lib/ReadData.o -c ./src/ReadData.cpp
	g++ -I ./include/ -o ./lib/System.o -c ./src/System.cpp
	g++ -I ./include/ -o ./lib/Control.o -c ./src/Control.cpp
	g++ -I ./include/ -o ./lib/Display.o -c ./src/Display.cpp
	g++ -I ./include/ -o ./lib/BinarySearchTree.o -c ./src/BinarySearchTree.cpp
	
link:
	g++ -I ./include/ -o ./bin/test ./lib/ReadData.o ./lib/BinarySearchTree.o ./lib/Cell.o ./lib/Tissue.o ./lib/Organ.o ./lib/System.o ./lib/Organism.o ./lib/Control.o ./lib/Radix.o ./lib/Queue.o ./lib/Display.o ./src/test.cpp

run:
	./bin/test