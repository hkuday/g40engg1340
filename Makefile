
output: main.o
	g++ main.o -o output

main.o: *.cpp
	g++ -c main.cpp

clean:
	rm *.o output
