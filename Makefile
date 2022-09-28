algo: main.o test.o other.o list.o
	g++ main.o test.o other.o list.o -o algo
main.o:
	g++ -c main.cpp -o main.o
test.o:
	g++ -c test/test.cpp -o test.o
other.o:
	g++ -c other/other.cpp -o other.o
list.o:
	g++ -c list/list.cpp -o list.o
clean:
	rm -rf algo *.o