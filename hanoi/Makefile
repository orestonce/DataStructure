a.out	: hanoi.o main.o
	g++ hanoi.o main.o -o a.out

main.o	: hanoi.h main.cpp
	g++ -std=c++11 -Wall -Werror main.cpp -c -o main.o

hanoi.o	: hanoi.h hanoi.cpp
	g++ -std=c++11 -Wall -Werror hanoi.cpp -c 

clean	:
	rm *.o a.out -f
