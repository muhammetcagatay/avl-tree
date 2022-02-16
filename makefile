hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Person.o -c ./src/Person.cpp
	g++ -I ./include/ -o ./lib/NodeAVL.o -c ./src/NodeAVL.cpp
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/NodeStack.o -c ./src/NodeStack.cpp
	g++ -I ./include/ -o ./lib/AVLTree.o -c ./src/AVLTree.cpp
	g++ -I ./include/ -o ./bin/Test  ./lib/Person.o ./lib/NodeStack.o ./lib/NodeAVL.o ./lib/Stack.o ./lib/AVLTree.o ./src/Test.cpp
calistir:
	./bin/Test