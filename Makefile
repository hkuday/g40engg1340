
output: main.o
	g++ main.o ouput

main.o: *.cpp
	g++ -c main.cpp
